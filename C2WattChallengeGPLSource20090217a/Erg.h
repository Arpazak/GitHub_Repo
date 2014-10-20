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
#ifndef ERG_H_
#define ERG_H_

#include <QThread.h>
//#include <QMutex.h>

#include "pm3ddi.h"
#include "pm3csafe.h"

#include "C2Logger.h"


class PollThread : public QThread {
  Q_OBJECT

  public:
	PollThread();
	void setDebugging( bool bDebug, C2Logger *pLogger );
    void stop();
    float getAvgCals();
    int   getWatts();
	bool  isStopped() { return stopped; }
	// TODO: make these thread safe
	unsigned int getPace();
	unsigned int getPower();
	unsigned int getDistance();
  protected:
    void run();
	unsigned int m_uiPace;
	unsigned int m_uiPower;
	unsigned int m_uiDistance;
private:
    volatile bool stopped;
	bool     m_bDebug;
	C2Logger *m_pLogger;
	//QMutex m_mutex;
};

class Erg {
  public:
    Erg();
	void init( bool bDebug = false, C2Logger* pLogger = NULL );
    void connect( void );
    bool isConnected( void );
    bool pollstart( void );
    bool pollstop( void );
	bool isPolling( void ) { return !m_pollThread.isStopped(); }
	unsigned int getPace() { return m_pollThread.getPace(); }
	unsigned int getPower() { return m_pollThread.getPower(); }
	unsigned int getDistance() { return m_pollThread.getDistance(); }
  protected:
    UINT16_T m_ui16NumPM3Ergs;
    UINT16_T m_ui16NumPM4Ergs;
    bool m_bConnected;
    PollThread m_pollThread;
  private:
	bool      m_bDebug;
    C2Logger* m_pLogger;
};

#endif
