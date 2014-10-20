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

#include "configchallenge.h"

ConfigChallengeDialog::ConfigChallengeDialog(QWidget *parent) : QDialog(parent, Qt::CustomizeWindowHint) {
  setupUi(this);

  QRegExp regExpWeight("[1-9][0-9]{1,2}");
  weightEdit->setValidator(new QRegExpValidator(regExpWeight, this));

  QRegExp regExpWatts("[1-3][0-9]{2}|[1-9][0-9]");
  wattCustomEdit->setValidator(new QRegExpValidator(regExpWatts, this));


  connect(startButton, SIGNAL(clicked()), this, SLOT(accept()));
}

void
ConfigChallengeDialog::on_weightEdit_textChanged() {
  startButton->setEnabled(weightEdit->hasAcceptableInput());
}
