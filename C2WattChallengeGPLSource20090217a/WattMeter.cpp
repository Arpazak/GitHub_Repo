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

#include "wattmeter.h"

WattMeter::WattMeter(QWidget *parent) : QWidget(parent) {
  setAttribute(Qt::WA_StaticContents);
  setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  m_iWatts = 0;
  m_iMaxWatts = 400;
  setTarget( 80 );
  m_fGrnScaleFactor = 0.0f;
  m_fYelScaleFactor = 0.0f;
  m_fRedScaleFactor = 0.0f;
}

QSize
WattMeter::sizeHint() const {
  QSize size;
  size.setWidth( 150 );
  size.setHeight( 400 );
  return size;
}

void
WattMeter::setWatts( int iWatts ) {
  m_iWatts = iWatts;
  update();
}

void
WattMeter::setTarget( int iTarget ) {
  m_iTarget = iTarget;
  m_iCaution = m_iTarget * 1.15;
}

void
WattMeter::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  QString qstr;

  // Get rid of compiler warning w/o turning it off
  event = event;

  // meter colors (light and dark: red, green, yellow & black)
  QColor dred( qRgb( 255,   0,   0 ) );
  QColor lred( qRgb( 255, 153, 153 ) );
  QColor dyel( qRgb( 255, 255,   0 ) );
  QColor lyel( qRgb( 255, 255, 153 ) );
  QColor dgrn( qRgb(   0, 255,   0 ) );
  QColor lgrn( qRgb( 153, 255, 153 ) );
  QColor blk(  qRgb(   0,   0,   0 ) );

  int iTextWidth   = 150;
  int iTextHeight  = 30;
  int iTextPadding = 5;

  int iHeight = this->height();
  int iWidth  = this->width();

  // Meter position - assumed meter is height of widget
  int iMeterLeftOffset = iTextWidth+iTextPadding;
  int iMeterHeight     = iHeight;
  int iMeterWidth      = iWidth-iMeterLeftOffset;
  int iMeterBase       = iHeight;
  int iMeterTop        = 0;

  // Scale factor for meter coordinate system
  m_fRedScaleFactor = ((float)iMeterHeight/3.0f) / (float)m_iTarget;
  m_fYelScaleFactor = ((float)iMeterHeight/2.0f - (float)iMeterHeight/3.0f) / (float)(m_iCaution-m_iTarget);
  m_fGrnScaleFactor = ((float)iMeterHeight/2.0f) / (float)(m_iMaxWatts-m_iCaution);

  // Figure out where in painter coordinates some important coords are
  // recall painter coords are (0,0) = upper left corner
  int iTargetWatts  = iMeterHeight - (iMeterHeight/3);
  int iCautionWatts = iMeterHeight - (iMeterHeight/2);
  
  // set up the meter zones: red=below target, yellow=below caution, green=in the clear
  QRect  redRect( iMeterLeftOffset, iTargetWatts,  iMeterWidth, iMeterBase-iTargetWatts    );
  QRect  yelRect( iMeterLeftOffset, iCautionWatts, iMeterWidth, iTargetWatts-iCautionWatts );
  QRect  grnRect( iMeterLeftOffset, iMeterTop,     iMeterWidth, iCautionWatts              );

  // for drawing partial rectangles for the current watts position
  QRect partialRect;

  painter.fillRect( redRect, lred );
  painter.fillRect( yelRect, lyel );
  painter.fillRect( grnRect, lgrn );
	  
  int iCurrentWatts = 0;
  if( m_iWatts  && (m_iWatts < m_iTarget) ) {
	  iCurrentWatts = iMeterHeight - m_iWatts*m_fRedScaleFactor;
	  partialRect.setRect( iMeterLeftOffset, iCurrentWatts, iMeterWidth, iMeterBase-iCurrentWatts );
	  painter.fillRect( partialRect, dred );
  }

  else if( (m_iWatts >= m_iTarget) && (m_iWatts < m_iCaution ) ) {
	  iCurrentWatts = iTargetWatts - ((m_iWatts-m_iTarget)*m_fYelScaleFactor);
	  partialRect.setRect(iMeterLeftOffset, iCurrentWatts, iMeterWidth, iTargetWatts-iCurrentWatts );
	  painter.fillRect( redRect, dred );
	  painter.fillRect( partialRect, dyel );
  }

  else if( m_iWatts >= m_iCaution ) {
	  iCurrentWatts = iCautionWatts - ((m_iWatts-m_iCaution)*m_fGrnScaleFactor);
	  partialRect.setRect(iMeterLeftOffset, iCurrentWatts, iMeterWidth, iCautionWatts-iCurrentWatts );
	  painter.fillRect( redRect, dred );
	  painter.fillRect( yelRect, dyel );
	  painter.fillRect( partialRect, dgrn );
  }

  // Draw some lines on the meter to show reference points
  QPen   tickPen;
  tickPen.setWidth(1);
  tickPen.setColor( qRgb( 128, 128, 128 ) );
  painter.setPen( tickPen );
  painter.drawLine( iMeterLeftOffset, iTargetWatts,  iWidth, iTargetWatts  );
  painter.drawLine( iMeterLeftOffset, iCautionWatts, iWidth, iCautionWatts );

  // Draw a line on the top of the meter bar
  tickPen.setWidth(2);
  painter.setPen( tickPen );
  painter.drawLine( iMeterLeftOffset, iCurrentWatts, iWidth, iCurrentWatts );

  // Add the meter graduation text
  QFont theFont("Gill Sans Ultra Bold Condensed", 20, QFont::Normal, false );
  QPen fontPen;
  fontPen.setWidth(1);
  fontPen.setColor( blk );
  painter.setPen( fontPen );
  painter.setFont( theFont );
  qstr.sprintf("%d Watts", m_iTarget );
  painter.drawText( 0, iTargetWatts-15,  iTextWidth, iTextHeight, Qt::AlignRight, qstr );
  qstr.sprintf("%d Watts", m_iCaution );
  painter.drawText( 0, iCautionWatts-15, iTextWidth, iTextHeight, Qt::AlignRight, qstr );
  painter.drawText( 0, iHeight-iTextHeight, iTextWidth, iTextHeight, Qt::AlignRight, "0 Watts" );
  painter.drawText( 0, 0, iTextWidth, iTextHeight, Qt::AlignRight, "400 Watts" );

  // Draw the meter's border
  QPen borderPen;
  borderPen.setColor( blk );
  borderPen.setWidth( 3 );
  painter.setPen( borderPen );
  painter.drawLine( iMeterLeftOffset, iMeterTop,    iMeterLeftOffset, iMeterBase-2 );
  painter.drawLine( iMeterLeftOffset, iMeterBase-2, iWidth-2,         iMeterBase-2 ); 
  painter.drawLine( iWidth-2,         iMeterBase-2, iWidth-2,         iMeterTop  );
  painter.drawLine( iWidth-2,         iMeterTop,    iMeterLeftOffset, iMeterTop  );
}

