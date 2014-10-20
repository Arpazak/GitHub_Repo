/********************************************************************************
** Form generated from reading ui file 'summary.ui'
**
** Created: Mon Feb 16 22:29:40 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SUMMARY_H
#define UI_SUMMARY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SummaryDialog
{
public:
    QLabel *label_2;
    QPushButton *resetButton;
    QLabel *label_7;
    QPushButton *closeButton;
    QLabel *labelTime;
    QLabel *labelMeters;
    QLabel *labelCalories;

    void setupUi(QWidget *SummaryDialog)
    {
    if (SummaryDialog->objectName().isEmpty())
        SummaryDialog->setObjectName(QString::fromUtf8("SummaryDialog"));
    SummaryDialog->setWindowModality(Qt::ApplicationModal);
    SummaryDialog->resize(412, 292);
    SummaryDialog->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(172, 173, 213, 255), stop:1 rgba(255, 255, 255, 255));"));
    label_2 = new QLabel(SummaryDialog);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(120, 30, 201, 21));
    QFont font;
    font.setFamily(QString::fromUtf8("Arial"));
    font.setPointSize(16);
    font.setBold(true);
    font.setWeight(75);
    label_2->setFont(font);
    label_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    resetButton = new QPushButton(SummaryDialog);
    resetButton->setObjectName(QString::fromUtf8("resetButton"));
    resetButton->setEnabled(true);
    resetButton->setGeometry(QRect(98, 236, 81, 31));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Arial"));
    font1.setPointSize(12);
    resetButton->setFont(font1);
    resetButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"border: 2px solid #000000;\n"
""));
    label_7 = new QLabel(SummaryDialog);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(160, 70, 111, 21));
    label_7->setFont(font);
    label_7->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    closeButton = new QPushButton(SummaryDialog);
    closeButton->setObjectName(QString::fromUtf8("closeButton"));
    closeButton->setEnabled(true);
    closeButton->setGeometry(QRect(228, 236, 81, 31));
    closeButton->setFont(font1);
    closeButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"border: 2px solid #000000;\n"
""));
    labelTime = new QLabel(SummaryDialog);
    labelTime->setObjectName(QString::fromUtf8("labelTime"));
    labelTime->setGeometry(QRect(110, 120, 231, 21));
    labelTime->setFont(font);
    labelTime->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    labelMeters = new QLabel(SummaryDialog);
    labelMeters->setObjectName(QString::fromUtf8("labelMeters"));
    labelMeters->setGeometry(QRect(110, 150, 231, 21));
    labelMeters->setFont(font);
    labelMeters->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    labelCalories = new QLabel(SummaryDialog);
    labelCalories->setObjectName(QString::fromUtf8("labelCalories"));
    labelCalories->setGeometry(QRect(110, 180, 231, 21));
    labelCalories->setFont(font);
    labelCalories->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));

    retranslateUi(SummaryDialog);

    QMetaObject::connectSlotsByName(SummaryDialog);
    } // setupUi

    void retranslateUi(QWidget *SummaryDialog)
    {
    SummaryDialog->setWindowTitle(QApplication::translate("SummaryDialog", "C2 Watt Challenge", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("SummaryDialog", "Challenge is Over!", 0, QApplication::UnicodeUTF8));
    resetButton->setText(QApplication::translate("SummaryDialog", "Try Again", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("SummaryDialog", "Your Stats:", 0, QApplication::UnicodeUTF8));
    closeButton->setText(QApplication::translate("SummaryDialog", "Close", 0, QApplication::UnicodeUTF8));
    labelTime->setText(QApplication::translate("SummaryDialog", "Time Rowed: 19:16", 0, QApplication::UnicodeUTF8));
    labelMeters->setText(QApplication::translate("SummaryDialog", "Meters Rowed: 2597", 0, QApplication::UnicodeUTF8));
    labelCalories->setText(QApplication::translate("SummaryDialog", "Calories Burned: 317", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(SummaryDialog);
    } // retranslateUi

};

namespace Ui {
    class SummaryDialog: public Ui_SummaryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMMARY_H
