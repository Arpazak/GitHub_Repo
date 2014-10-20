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
#ifndef WATTCHALLENGE_H_
#define WATTCHALLENGE_H_

#include <QDialog>
#include <QTextStream>
#include <QTime>
#include "ui_wattchallenge.h"

// Sub-dialogs called by WattChallengeDialog
#include "configchallenge.h"
#include "startchallenge.h"
#include "virtualerg.h"
#include "summary.h"
#include "wattmeter.h"

// PM connection
#include "Erg.h"

// Logging
#include "C2Logger.h"

const int APPSTATE_UNCONFIGURED       = 0;
const int APPSTATE_CONFIGURED         = 1;
const int APPSTATE_CAPTUREBOGUSWATTS  = 2;
const int APPSTATE_WAITFORVALIDWATTS  = 3;
const int APPSTATE_WAITFORTARGETWATTS = 4;
const int APPSTATE_GAMEON             = 5;
const int APPSTATE_FINISHED           = 6;

class WattChallengeDialog : public QDialog, public Ui_WattChallengeDialog {
  Q_OBJECT

  public:
    WattChallengeDialog(QWidget *parent = 0, bool bDebug = false);

  protected:
    unsigned int m_uiTargetWatts;
	int m_iUserWeight;
    ConfigChallengeDialog *m_pConfigDialog;
    StartChallengeDialog  *m_pStartDialog;
    VirtualErgDialog      *m_pVErgDialog;
    SummaryDialog         *m_pSummaryDialog;
    WattMeter             *m_pWattMeter;

	C2Logger m_Logger;
	Erg m_Erg;

    int m_iState;
	QTime m_startTime;
    unsigned int m_uiSeconds;
    unsigned int m_uiMeters;
    unsigned int m_uiPace;
	unsigned int m_uiStartMeters;
	unsigned int m_uiLastMeters;
	unsigned int m_uiBogusWatts;
	unsigned int m_uiMetersConstantCounter;

	int m_iErgConnectTimer;

	bool m_bDebug;
	

  private slots:
    void updateCurrentWatts(void);
};

#endif
