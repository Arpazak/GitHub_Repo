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
#include "Erg.h"

#include <QMessageBox>

#define PM_SERIALNUMSTRING_LEN   16
#define PM_FWIDSTRING_LEN        20
#define PM_PNSTRING_LEN          20

PollThread::PollThread() {
  stopped = true;

  m_uiDistance = 0;
  m_uiPace     = 0;
  m_uiPower    = 0;
  m_bDebug = false;
}

unsigned int
PollThread::getPace() {
	//m_mutex.lock();
	unsigned int retval = m_uiPace;
	//m_mutex.unlock();
	return retval;
}

unsigned int
PollThread::getPower() {
	//m_mutex.lock();
	unsigned int retval = m_uiPower;
	//m_mutex.unlock();
	return retval;
}

unsigned int
PollThread::getDistance() {
	//m_mutex.lock();
	unsigned int retval = m_uiDistance;
	//m_mutex.unlock();
	return retval;
}

void
PollThread::setDebugging( bool bDebug, C2Logger *pLogger ) {
	m_bDebug = bDebug;
	m_pLogger = pLogger;
}

void
PollThread::run() {
	QString str, str2;
	ERRCODE_T ecode;
	char cErrorNameBuf[256];
	char cErrorTextBuf[256];

	const unsigned short uwUnitNumber = 0;

	UINT16_T uwCmdDataSize = 5;
	UINT32_T uiCmdData[5] = { 0x1A, 0x01, 0xA3, 0xA6, 0xB4 };  // Get Distance, Pace, Power

	UINT32_T uiRspData[64];
	UINT16_T uwRspDataSize;

	UINT16_T uwState;
	UINT16_T uwStatus;

	// We expect an 8 byte response
	// 0xA1 0x07 0xA3 0x05 <LSB> <Byte2> <Byte3> <MSB> <Frac>   - Meters
	// 0xA6 0x03 <LSB> <MSB> <UNITS>                            - Pace
	// 0xB4 0x03 <LSB> <MSB> <UNITS>                            - Power
	const unsigned short uwRspDataExpect = 19; 

	stopped = false;

	while( !stopped ) {
		ecode = tkcmdsetCSAFE_command (uwUnitNumber, 
		                               uwCmdDataSize, uiCmdData, 
									   &uwRspDataSize, uiRspData);

		// If we get an error when we try to poll the PM, assume the PM is disconnected
		// so stop polling and indicate we're disconnected;
		// TODO - need to wire this back up to IsConnected()
		if( ecode ) {
			if( m_bDebug ) {
				tkcmdsetDDI_get_error_name( ecode, cErrorNameBuf, (UINT16_T)sizeof( cErrorNameBuf ) );
				tkcmdsetDDI_get_error_text( ecode, cErrorTextBuf, (UINT16_T)sizeof( cErrorTextBuf ) );
				str.sprintf( "C2Erg::PollThread->Error (%d): %s %s", ecode, cErrorNameBuf, cErrorTextBuf );
				m_pLogger->logentry( str );
			}
			stopped = true;
		}
		else {
			UINT8_T ubStatus = tkcmdsetCSAFE_get_status();
			uwState = GET_SLAVE_STATE( ubStatus );
			uwStatus = GET_FRAME_STATUS( ubStatus );

			if( uwRspDataSize != uwRspDataExpect ) {
				if( m_bDebug ) {
					m_pLogger->logentry("C2Erg::PollThread->Unexpected data length returned from PM");
				}
			}
			else {
			    //m_mutex.lock();
				m_uiDistance = uiRspData[4] | uiRspData[5]<<8 | uiRspData[6]<<16 | uiRspData[7]<<24;
				m_uiPace     = uiRspData[11] | uiRspData[12]<<8;
				m_uiPower    = uiRspData[16] | uiRspData[17]<<8;
				//m_mutex.unlock();
			}

			if( m_bDebug ) {
				str.sprintf("State[%d] Status[%d] Meters[%d] Pace[%d] Power[%d] Raw Data [ ", uwState, uwStatus, m_uiDistance, m_uiPace, m_uiPower);
				for( int i = 0; i < uwRspDataSize; i++ ) {
					str2.sprintf("%02X ", uiRspData[i]);
					str += str2;
				}
				str += "]";
				m_pLogger->logentry("C2Erg::PollThread->RX from PM:", str );
			}
		}

		// Sleep for 0.5 seconds
		msleep(500);
	}
	if( m_bDebug ) {
		m_pLogger->logentry("C2Erg::PollThread->Exiting");
	}
	stopped = false;
}

void
PollThread::stop() {
  stopped = true;
}

Erg::Erg() {
  m_ui16NumPM3Ergs = 0;
  m_ui16NumPM4Ergs = 0;
  m_bConnected = 0;
  m_pollThread.stop();
}

void
Erg::init( bool bDebug, C2Logger* pLogger ) {
  QString str;
  ERRCODE_T ecode;
  char cErrorNameBuf[256];
  char cErrorTextBuf[256];

  m_bDebug = bDebug;
  m_pLogger = pLogger;

  if( m_bDebug ) {
	  m_pLogger->logentry( "C2Erg::Initializing DDI" );
  }
  if( ecode = tkcmdsetDDI_init() ) {
	  if( m_bDebug ) {
			tkcmdsetDDI_get_error_name( ecode, cErrorNameBuf, (UINT16_T)sizeof( cErrorNameBuf ) );
			tkcmdsetDDI_get_error_text( ecode, cErrorTextBuf, (UINT16_T)sizeof( cErrorTextBuf ) );
			str.sprintf( "C2Erg::Error (%d): %s %s", ecode, cErrorNameBuf, cErrorTextBuf );
			m_pLogger->logentry( str );
	  }
  }

  if( m_bDebug ) {
	  m_pLogger->logentry( "C2Erg::Initializing CSAFE" );
  }
  if( ecode = tkcmdsetCSAFE_init_protocol(100) ) {
	  if( m_bDebug ) {
			tkcmdsetDDI_get_error_name( ecode, cErrorNameBuf, (UINT16_T)sizeof( cErrorNameBuf ) );
			tkcmdsetDDI_get_error_text( ecode, cErrorTextBuf, (UINT16_T)sizeof( cErrorTextBuf ) );
			str.sprintf( "C2Erg::Error (%d): %s %s", ecode, cErrorNameBuf, cErrorTextBuf );
			m_pLogger->logentry( str );
	  }
  }
}
  
void
Erg::connect( void ) {
	QString str;
	ERRCODE_T ecode;
	char cErrorNameBuf[256];
    char cErrorTextBuf[256];
  
	if( m_bDebug ) {
		m_pLogger->logentry( "C2Erg::Discovering PMs" );
	}
	if( ecode = tkcmdsetDDI_discover_pm3s(TKCMDSET_PM3_PRODUCT_NAME2, 0, &m_ui16NumPM3Ergs) 
		     && tkcmdsetDDI_discover_pm3s(TKCMDSET_PM4_PRODUCT_NAME, 0, &m_ui16NumPM4Ergs ) ) {
		if( m_bDebug ) {
			tkcmdsetDDI_get_error_name( ecode, cErrorNameBuf, (UINT16_T)sizeof( cErrorNameBuf ) );
			tkcmdsetDDI_get_error_text( ecode, cErrorTextBuf, (UINT16_T)sizeof( cErrorTextBuf ) );
			str.sprintf( "C2Erg::Error (%d): %s %s", ecode, cErrorNameBuf, cErrorTextBuf );
			m_pLogger->logentry( str );
		}
	}
         if( m_bDebug && (m_ui16NumPM3Ergs || m_ui16NumPM4Ergs) ) {
			UINT8_T rspbuf[256];
			ecode |= tkcmdsetDDI_fw_version(0, rspbuf);
			str.sprintf("FW: %s", rspbuf);
			m_pLogger->logentry( "PM Firmware Version:", str );
			ecode |= tkcmdsetDDI_hw_version(0, rspbuf);
			str.sprintf("HW: %s", rspbuf);
			m_pLogger->logentry( "PM Hardware Version:", str );
			ecode |= tkcmdsetDDI_serial_number(0, rspbuf);
			str.sprintf("SN: %s", rspbuf);
			m_pLogger->logentry( "PM Serial Number:", str );
		}

  if( (m_ui16NumPM3Ergs + m_ui16NumPM4Ergs) && !ecode ) {
	//	m_pLogger->logstate("CONNECTED");
    m_bConnected = true;
  }

  if( m_bDebug ) {
	  str.sprintf("C2Erg::%d PM3s and %d PM4s discovered", m_ui16NumPM3Ergs, m_ui16NumPM4Ergs);
	  m_pLogger->logentry( str );
  }
}

bool
Erg::isConnected( void ) {
	return m_bConnected;
}

bool
Erg::pollstart( void ) {
	if( m_bConnected ) {
		if( m_bDebug ) {
			m_pLogger->logentry("C2Erg::Launching erg communcations thread");
			m_pollThread.setDebugging( true, m_pLogger );
		}
		m_pollThread.start();
	}
	return m_bConnected;
}

bool
Erg::pollstop( void ) {
	if( m_bDebug ) {
		m_pLogger->logentry("C2Erg::Killing erg communications thread");
	}
	if( isPolling() ) {
		m_pollThread.stop();
		return true;
	}
	else {
		return false;
	}
}
