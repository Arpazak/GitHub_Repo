/********************************************************************************
** Form generated from reading ui file 'startchallenge.ui'
**
** Created: Mon Feb 16 22:29:40 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_STARTCHALLENGE_H
#define UI_STARTCHALLENGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartChallengeDialog
{
public:
    QLabel *label;
    QLabel *instructionsLabel;

    void setupUi(QWidget *StartChallengeDialog)
    {
    if (StartChallengeDialog->objectName().isEmpty())
        StartChallengeDialog->setObjectName(QString::fromUtf8("StartChallengeDialog"));
    StartChallengeDialog->setWindowModality(Qt::NonModal);
    StartChallengeDialog->resize(480, 184);
    StartChallengeDialog->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(172, 173, 213, 255), stop:1 rgba(255, 255, 255, 255));"));
    label = new QLabel(StartChallengeDialog);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(90, 20, 301, 31));
    QFont font;
    font.setFamily(QString::fromUtf8("Arial"));
    font.setPointSize(19);
    font.setBold(true);
    font.setWeight(75);
    label->setFont(font);
    label->setAutoFillBackground(false);
    label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    label->setTextFormat(Qt::AutoText);
    instructionsLabel = new QLabel(StartChallengeDialog);
    instructionsLabel->setObjectName(QString::fromUtf8("instructionsLabel"));
    instructionsLabel->setGeometry(QRect(40, 40, 391, 121));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Arial"));
    font1.setPointSize(12);
    font1.setBold(true);
    font1.setWeight(75);
    instructionsLabel->setFont(font1);
    instructionsLabel->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    instructionsLabel->setAlignment(Qt::AlignCenter);
    instructionsLabel->setWordWrap(true);

    retranslateUi(StartChallengeDialog);

    QMetaObject::connectSlotsByName(StartChallengeDialog);
    } // setupUi

    void retranslateUi(QWidget *StartChallengeDialog)
    {
    StartChallengeDialog->setWindowTitle(QApplication::translate("StartChallengeDialog", "C2 Watt Challenge", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("StartChallengeDialog", "Concept2 Watt Challenge", 0, QApplication::UnicodeUTF8));
    instructionsLabel->setText(QApplication::translate("StartChallengeDialog", "Row as long as you can without dropping below the watt level you set.  Once the watt meter drops into the red, the challenge is over. Good Luck!", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(StartChallengeDialog);
    } // retranslateUi

};

namespace Ui {
    class StartChallengeDialog: public Ui_StartChallengeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTCHALLENGE_H
