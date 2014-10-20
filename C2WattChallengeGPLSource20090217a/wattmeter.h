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
#ifndef WATTMETER_H_
#define WATTMETER_H_

#include <QColor>
#include <QWidget>

class WattMeter : public QWidget {
  Q_OBJECT
  Q_PROPERTY(int watts READ getWatts WRITE setWatts )
  Q_PROPERTY(int target READ getTarget WRITE setTarget )

  public:
    WattMeter(QWidget *parent = 0);
    void setWatts( int iWatts );
    int  getWatts() const { return m_iWatts; }
    void setTarget( int iTarget );
    int getTarget() const { return m_iTarget; }
    QSize sizeHint() const;
  protected:
    void paintEvent(QPaintEvent *event);
  private:
    int m_iWatts;
    int m_iTarget;
    int m_iCaution;
	int m_iMaxWatts;

	float m_fGrnScaleFactor;
	float m_fYelScaleFactor;
	float m_fRedScaleFactor;
};
    

#endif
