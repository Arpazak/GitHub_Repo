/*
Watt Challenge for Concept2 Performance Monitors PM3 and PM4

Copyright (C) 2009 Jason Dahlstrom
    This file is part of Watt Challenge
    Watt Challenge is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    Watt Challenge is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with Watt Challenge.  If not, see <http://www.gnu.org/licenses/>.
 
Rights to and distribution responsibilities for Watt Challenge has been 
assigned by Jason Dahlstrom to Concept2 (www.concept2.com, 105 Industrial Park Drive Morrisville VT USA +1(802) 888-7971).  Contact person is Scott Hamilton, Product Engineer, scotth@concept2.com.   

Please see readme-license.txt for additional license and dependency notices.
 
*/
#include <QtGui>
#include <QFileDialog>
#include <QMessageBox>
#include <QIcon>
#include "wattchallenge.h"

WattChallengeDialog::WattChallengeDialog(QWidget *parent, bool bDebug) : QDialog(parent) {
	QString qstr;
	setupUi(this);

	setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowMinMaxButtonsHint);
	setWindowIcon(QIcon("wcicon.gif"));

	// Turn off debug capture functionality
	m_bDebug = bDebug;

	if( m_bDebug ) {
		m_Logger.openLogfile( QFileDialog::getSaveFileName( this,
														  tr("Log File"),
														  "./debug.html",
														  tr("HTML Files (*.html)") ) );
	}

	// Initialize member variables
	m_uiLastMeters = 0;
	m_uiMetersConstantCounter = 0;

	// Track our state
	m_iState = APPSTATE_UNCONFIGURED;

	m_pConfigDialog  = new ConfigChallengeDialog(this);
	m_pStartDialog   = new StartChallengeDialog(this);
	m_pVErgDialog    = new VirtualErgDialog(this);
	m_pSummaryDialog = new SummaryDialog(this);

	m_iErgConnectTimer = 0;

	if( m_bDebug ) {
		m_Logger.logentry( "Initializing PM API" );
	}
	m_Erg.init( m_bDebug, &m_Logger );

	// Monitor watts off of the PM
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateCurrentWatts()));
	if( m_bDebug ) {
		m_Logger.logentry("Starting erg query & update loop timer");
	}
	timer->start(500);

	if( m_bDebug ) {
		m_Logger.logentry( "User configuration dialog launching");
	}
	m_pConfigDialog->exec();

	// Capture the user's weight and target watts
	qstr = m_pConfigDialog->weightEdit->text();
	m_iUserWeight = qstr.toInt();

	if( m_pConfigDialog->WattsCustomButton->isChecked() ) {
		qstr = m_pConfigDialog->wattCustomEdit->text();
		m_uiTargetWatts = qstr.toInt();
	}
	else {
		m_uiTargetWatts = 80;
	}

	if( m_bDebug ) {
		qstr.sprintf("Target Watts: %d, User Weight: %d", m_uiTargetWatts, m_iUserWeight);
		m_Logger.logentry( "User configuration dialog closed", qstr);
	}

	// Set up the watt meter
	wattmeter->setTarget( m_uiTargetWatts );

	qstr.sprintf("Row as long as you can without dropping below %d Watts.  Once the watt meter drops into the red, the challenge is over. Good Luck!",
                m_uiTargetWatts );
	m_iState = APPSTATE_CONFIGURED;
	m_pStartDialog->instructionsLabel->setText(qstr);
	if( m_bDebug ) {
		m_Logger.logentry("Launching User Information Dialog", qstr);
	}
	m_pStartDialog->show();
}

void
WattChallengeDialog::updateCurrentWatts(void) {
  //int uiWatts = 4 * m_pVErgDialog->spinBox->value();

	QString qstr;
	unsigned int uiWatts = 0;

	if( !m_Erg.isConnected() ) {      // Not connected to a PM
		qstr = "---";
		currentWattsLabel->setText( qstr );
		m_Erg.pollstop();             // Don't try to query a PM
		if( !m_iErgConnectTimer ) {
			if( m_bDebug ) {
				m_Logger.logentry("No PM Detected, retrying");
			}
			m_Erg.connect();          // Try to connect
			m_iErgConnectTimer = 6 ;  // Wait 6 cycles (~3 seconds) before retrying
		}
		else {
			m_iErgConnectTimer--;
		}
	}
	else { // connected to a PM
	
		switch( m_iState ) {
			case APPSTATE_CONFIGURED:
				if( m_bDebug ) {
					m_Logger.logstate("APPSTATE_CONFIGURED");
				}
				// See if we are polling.  If not, fire it up
				if( !m_Erg.isPolling() ) {   // If not querying, start 
					if( m_bDebug ) {
						m_Logger.logentry("Launching Erg Communications Thread");
					}
					m_Erg.pollstart();
				}
				uiWatts = 0;
				m_iState = APPSTATE_CAPTUREBOGUSWATTS;
				if( m_bDebug ) {
					m_Logger.logstate("APPSTATE_CAPTUREBOGUSWATTS");
				}
				break;

			case APPSTATE_CAPTUREBOGUSWATTS:
				// We want the first Watts value off the PM - this value
				// can be bogus (leftover from previous workout)
				m_uiBogusWatts = m_Erg.getPower();
				uiWatts = 0;
				m_iState = APPSTATE_WAITFORVALIDWATTS;
				if( m_bDebug ) {
					m_Logger.logstate("APPSTATE_WAITFORVALIDWATTS");
				}
				break;

			case APPSTATE_WAITFORVALIDWATTS:
				if( m_Erg.getPower() != m_uiBogusWatts ) {
					uiWatts = m_Erg.getPower();
					m_iState = APPSTATE_WAITFORTARGETWATTS;
					if( m_bDebug ) {
						m_Logger.logstate("APPSTATE_WAITFORTARGETWATTS");
					}
				}
				break;

			case APPSTATE_WAITFORTARGETWATTS:
				if( m_Erg.getPower() >= m_uiTargetWatts ) {
					m_uiStartMeters = m_Erg.getDistance();
					m_startTime = QTime::currentTime();
					m_pStartDialog->hide();
					m_iState = APPSTATE_GAMEON;
					if( m_bDebug ) {
						m_Logger.logstate("APPSTATE_GAMEON");
					}
				}
				uiWatts = m_Erg.getPower();
				break;

			case APPSTATE_GAMEON:
				// Watch for the user to stop rowing by 
				// monitoring the meters value.  If it does not
				// change for six consecutive samples (3 seconds)
				// then the user has stopped rowing
				if( m_uiLastMeters == m_Erg.getDistance() ) {
					m_uiMetersConstantCounter++;
				}
				m_uiLastMeters = m_Erg.getDistance();
				m_uiSeconds  = m_startTime.secsTo( QTime::currentTime() );
				m_uiMeters   = m_Erg.getDistance() - m_uiStartMeters;
				m_uiPace = m_Erg.getPace();  // Note, this is seconds per km
				uiWatts = m_Erg.getPower();

				// From Trevor: cal/hr = (((cal/hr – 300 + (1.714 x weight))/60) x total time
				// From PM3 Data Conversions: cal/hr = (((2.8 / (pace * pace * pace))* (4.0 * 0.8604)) + 300.0)
				double dPaceSecsMeter = (double)m_uiPace / 1000;
				double dCaloriesHr = ((2.8/(dPaceSecsMeter*dPaceSecsMeter*dPaceSecsMeter)) * (4.0*0.8604) + (1.714*(double)m_iUserWeight));  // cals/hr
				double dHours = (double)m_uiSeconds/3600;
				double dCalories = dCaloriesHr * ((double)m_uiSeconds/3600);

				if( m_bDebug ) {
					qstr.sprintf("Pace: %f, Calories/Hr: %f Hours: %f Calories: %f", dPaceSecsMeter, dCaloriesHr, dHours, dCalories);
					m_Logger.logentry("Calories Burned Computation", qstr);
				}

				
				
				if( ( m_uiMetersConstantCounter > 5 ) || (m_Erg.getPower() < m_uiTargetWatts ) ) {
					if( m_bDebug ) {
						m_Logger.logstate("APPSTATE_GAMEOVER");
						if (m_Erg.getPower() < m_uiTargetWatts) {
							m_Logger.logentry("Game over due to watts falling below threshold");
						} 
						else {
							m_Logger.logentry("Game over due to rower stopped rowing");
						}
					}
					// Clear the main window values (blank them)
					qstr = "Time Rowed:";
					timeRowedLabel->setText(qstr);
					qstr = "Meters Rowed:";
					metersRowedLabel->setText(qstr);
					qstr = "Calories Burned:";
					caloriesBurnedLabel->setText(qstr);
					qstr = "";
					currentWattsLabel->setText(qstr);
					wattmeter->setWatts( 0 );

					// Set the stats in the summary dialog
					if( m_uiSeconds < 3600 ) {
						unsigned int uiMins = (unsigned int)((unsigned int)m_uiSeconds/60);
						unsigned int uiSecs = (unsigned int)m_uiSeconds % 60;
						qstr.sprintf("Time Rowed: %02d:%02d", uiMins, uiSecs);
   					} 
					else {
						unsigned int uiHours = (unsigned int)m_uiSeconds / 3600;
						unsigned int uiMins = ((unsigned int)m_uiSeconds - (uiHours*3600))/60;
						unsigned int uiSecs = (unsigned int)m_uiSeconds % 60;
						qstr.sprintf("Time Rowed: %d:%02d:%02d", uiHours, uiMins, uiSecs );
					}
					m_pSummaryDialog->labelTime->setText(qstr);
					qstr.sprintf("Meters Rowed: %d", m_uiMeters/10);
					m_pSummaryDialog->labelMeters->setText(qstr);
					qstr.sprintf("Calories Burned: %d", (int)dCalories);
					m_pSummaryDialog->labelCalories->setText(qstr);
					if( m_pSummaryDialog->exec() ) {
						m_uiLastMeters = 0;
						m_uiMetersConstantCounter = 0;
						m_iState = APPSTATE_CONFIGURED;
						m_pStartDialog->show();
					} 
					else {
						if( m_bDebug ) {
							m_Logger.logstate("APPSTATE_EXIT");
						}
						exit(0);
					}
				}
				else {
					if( m_uiSeconds < 3600 ) {
						unsigned int uiMins = (unsigned int)((unsigned int)m_uiSeconds/60);
						unsigned int uiSecs = (unsigned int)m_uiSeconds % 60;
						qstr.sprintf("Time Rowed: %02d:%02d", uiMins, uiSecs);
   					} 
					else {
						unsigned int uiHours = (unsigned int)m_uiSeconds / 3600;
						unsigned int uiMins = ((unsigned int)m_uiSeconds - (uiHours*3600))/60;
						unsigned int uiSecs = (unsigned int)m_uiSeconds % 60;
						qstr.sprintf("Time Rowed: %d:%02d:%02d", uiHours, uiMins, uiSecs );
					}
	
					timeRowedLabel->setText(qstr);

					qstr.sprintf("Meters Rowed: %d", m_uiMeters/10);
					metersRowedLabel->setText(qstr);

					qstr.sprintf("Calories Burned: %d", (int)dCalories);
					caloriesBurnedLabel->setText(qstr);
				}
				break;
			} // switch()

			// Update the WattMeter and Current Watts label
			wattmeter->setWatts( uiWatts );
			if( uiWatts > (m_uiTargetWatts * 1.15) ) {
				currentWattsLabel->setStyleSheet("color: #00ff00;");
			}
			else if( uiWatts > m_uiTargetWatts) {
				currentWattsLabel->setStyleSheet("color: #ffff00;");
			}
			else {
				currentWattsLabel->setStyleSheet("color: #ff0000;");
			}
			qstr.sprintf("%d", uiWatts );
			currentWattsLabel->setText( qstr );
		} // else()
};