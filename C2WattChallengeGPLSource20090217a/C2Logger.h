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
#ifndef C2LOGGER_H_
#define C2LOGGER_H_

#include <QFile>
#include <QString>
#include <QTextStream>

class C2Logger : public QObject {
public:
	C2Logger();
	void openLogfile( QString filename );
	void logentry( QString entry );
	void logentry( const char *entry );
	void logentry( QString entry, QString rawdata );
	void logentry( const char *entry, QString rawdata );
	void logentry( QString entry, const char *rawdata );
	void logstate( const char *state );

protected:
	QFile *pLogfile;
	QTextStream *pLogstream;
};

#endif