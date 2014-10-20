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
#include "C2Logger.h"

#include <QTime>
#include <QDate>

C2Logger::C2Logger() {
	pLogfile = NULL;
	pLogstream = NULL;
}

void
C2Logger::openLogfile( QString filename ) {
	pLogfile = new QFile( filename );
	pLogfile->open( QIODevice::WriteOnly | QIODevice::Truncate );
	pLogstream = new QTextStream( pLogfile );

	QDate theDate = QDate::currentDate();
	QTime theTime = QTime::currentTime();

    *pLogstream << "<HTML>" << endl
	            << "  <HEAD>" << endl
	            << "    <TITLE>C2WattChallenge Debug Output</TITLE>" << endl
	            << "  </HEAD>" << endl
	            << "  <BODY>" << endl
	            << "    <CENTER>" << endl
	            << "      <H2>C2 Watt Challenge Debug Output</H2>" << endl
	            << "      <H3>Created: " << QDate::longMonthName( theDate.month() ) << ' ' << theDate.day() << ", " << theDate.year() << "</H3>" << endl 
	            << "    </CENTER>" << endl
	            << "    <HR></HR>" << endl
	            << "    <TABLE WIDTH=100% BORDER=1>" << endl
	            << "      <TR>" << endl
	            << "        <TD ALIGN=CENTER>TIME</TD>" << endl
	            << "        <TD ALIGN=CENTER>STATE</TD>" << endl
	            << "        <TD ALIGN=CENTER>EVENT</TD>" << endl
	            << "        <TD ALIGN=CENTER>RAW DATA</TD>" << endl
                << "     </TR>" << endl << endl
	            << "  <TR>" << endl;
}

void
C2Logger::logentry( QString entry ) {
	logentry( entry, "&nbsp;" );	
}

void
C2Logger::logentry( const char *entry ) {
	QString theString = entry;
	logentry( theString, "&nbsp;" );
}

void 
C2Logger::logentry( const char *entry, QString rawdata ) {
	QString theString = entry;
	logentry( theString, rawdata );
}

void
C2Logger::logentry( QString entry, const char *rawdata ) {
	QString theRawData = rawdata;
	logentry( entry, theRawData );
}

void
C2Logger::logentry( QString entry, QString rawdata ) {
	QTime theTime = QTime::currentTime();

	*pLogstream << "  <TR>" << endl
	            << "    <TD>" << theTime.hour() << ":" << theTime.minute() << ":" << theTime.second() << "." << theTime.msec() << "</TD>" << endl
	            << "    <TD>-</TD>" << endl
	            << "    <TD>" << entry << "</TD>" << endl
	            << "    <TD>" << rawdata << "</TD>" << endl
	            << "  </TR>" << endl << endl;
}

void
C2Logger::logstate( const char *state ) {
	QTime theTime = QTime::currentTime();
	*pLogstream << "  <TR>" << endl
	            << "    <TD>" << theTime.hour() << ":" << theTime.minute() << ":" << theTime.second() << "." << theTime.msec() << "</TD>" << endl
	            << "    <TD>" << state << "</TD>" << endl
	            << "    <TD>-</TD>" << endl
	            << "    <TD>-</TD>" << endl
	            << "  </TR>" << endl << endl;
}



