/********************************************************************************
** Form generated from reading ui file 'configchallenge.ui'
**
** Created: Mon Feb 16 22:29:40 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONFIGCHALLENGE_H
#define UI_CONFIGCHALLENGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigChallengeDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *weightEdit;
    QLabel *label_3;
    QFrame *line;
    QRadioButton *Watts80Button;
    QRadioButton *WattsCustomButton;
    QLineEdit *wattCustomEdit;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *startButton;

    void setupUi(QWidget *ConfigChallengeDialog)
    {
    if (ConfigChallengeDialog->objectName().isEmpty())
        ConfigChallengeDialog->setObjectName(QString::fromUtf8("ConfigChallengeDialog"));
    ConfigChallengeDialog->setWindowModality(Qt::WindowModal);
    ConfigChallengeDialog->resize(412, 292);
    ConfigChallengeDialog->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(172, 173, 213, 255), stop:1 rgba(255, 255, 255, 255));"));
    label = new QLabel(ConfigChallengeDialog);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(60, 30, 301, 31));
    QFont font;
    font.setFamily(QString::fromUtf8("Arial"));
    font.setPointSize(19);
    font.setBold(true);
    font.setWeight(75);
    label->setFont(font);
    label->setAutoFillBackground(false);
    label->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    label->setTextFormat(Qt::AutoText);
    label_2 = new QLabel(ConfigChallengeDialog);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(100, 80, 221, 21));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Arial"));
    font1.setPointSize(12);
    font1.setBold(true);
    font1.setWeight(75);
    label_2->setFont(font1);
    label_2->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    weightEdit = new QLineEdit(ConfigChallengeDialog);
    weightEdit->setObjectName(QString::fromUtf8("weightEdit"));
    weightEdit->setGeometry(QRect(161, 110, 66, 26));
    QFont font2;
    font2.setFamily(QString::fromUtf8("Arial"));
    font2.setPointSize(10);
    weightEdit->setFont(font2);
    weightEdit->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(255,255, 255,0), stop:1 rgba(255, 255, 255, 255));\n"
"border: 1px solid #000000\n"
"\n"
""));
    weightEdit->setAlignment(Qt::AlignCenter);
    label_3 = new QLabel(ConfigChallengeDialog);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(233, 110, 27, 26));
    label_3->setFont(font1);
    label_3->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(255,255,255,0), stop:1 rgba(255, 255, 255, 255));"));
    line = new QFrame(ConfigChallengeDialog);
    line->setObjectName(QString::fromUtf8("line"));
    line->setGeometry(QRect(190, 160, 16, 71));
    line->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(255, 255, 255, 0), stop:1 rgba(255, 255, 255, 255));"));
    line->setLineWidth(1);
    line->setMidLineWidth(5);
    line->setFrameShape(QFrame::VLine);
    line->setFrameShadow(QFrame::Sunken);
    Watts80Button = new QRadioButton(ConfigChallengeDialog);
    Watts80Button->setObjectName(QString::fromUtf8("Watts80Button"));
    Watts80Button->setGeometry(QRect(140, 206, 21, 18));
    Watts80Button->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    Watts80Button->setChecked(true);
    WattsCustomButton = new QRadioButton(ConfigChallengeDialog);
    WattsCustomButton->setObjectName(QString::fromUtf8("WattsCustomButton"));
    WattsCustomButton->setGeometry(QRect(221, 206, 26, 16));
    WattsCustomButton->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    wattCustomEdit = new QLineEdit(ConfigChallengeDialog);
    wattCustomEdit->setObjectName(QString::fromUtf8("wattCustomEdit"));
    wattCustomEdit->setGeometry(QRect(253, 201, 62, 26));
    wattCustomEdit->setFont(font2);
    wattCustomEdit->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(255,255,255,50), stop:1 rgba(255, 255, 255, 255));\n"
"border: 1px solid #000000;"));
    wattCustomEdit->setAlignment(Qt::AlignCenter);
    label_4 = new QLabel(ConfigChallengeDialog);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(321, 201, 39, 26));
    QFont font3;
    font3.setFamily(QString::fromUtf8("Arial"));
    font3.setPointSize(12);
    label_4->setFont(font3);
    label_4->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    label_5 = new QLabel(ConfigChallengeDialog);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(230, 170, 141, 20));
    label_5->setFont(font3);
    label_5->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    label_6 = new QLabel(ConfigChallengeDialog);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(120, 170, 61, 20));
    label_6->setFont(font3);
    label_6->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0, stop:0 rgba(0, 0, 0, 0), stop:1 rgba(255, 255, 255, 255));"));
    startButton = new QPushButton(ConfigChallengeDialog);
    startButton->setObjectName(QString::fromUtf8("startButton"));
    startButton->setEnabled(false);
    startButton->setGeometry(QRect(156, 244, 81, 31));
    startButton->setFont(font3);
    startButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 170, 255);\n"
"color: rgb(255, 255, 255);\n"
"border-radius: 15px;\n"
"border: 2px solid #000000;\n"
""));

#ifndef QT_NO_SHORTCUT
    label_3->setBuddy(weightEdit);
    label_4->setBuddy(wattCustomEdit);
#endif // QT_NO_SHORTCUT


    retranslateUi(ConfigChallengeDialog);

    QMetaObject::connectSlotsByName(ConfigChallengeDialog);
    } // setupUi

    void retranslateUi(QWidget *ConfigChallengeDialog)
    {
    ConfigChallengeDialog->setWindowTitle(QApplication::translate("ConfigChallengeDialog", "C2 Watt Challenge", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("ConfigChallengeDialog", "Concept2 Watt Challenge", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("ConfigChallengeDialog", "To begin, enter your weight:", 0, QApplication::UnicodeUTF8));
    weightEdit->setText(QString());
    label_3->setText(QApplication::translate("ConfigChallengeDialog", "lbs.", 0, QApplication::UnicodeUTF8));
    Watts80Button->setText(QString());
    WattsCustomButton->setText(QString());
    wattCustomEdit->setText(QApplication::translate("ConfigChallengeDialog", "120", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("ConfigChallengeDialog", "Watts", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("ConfigChallengeDialog", "Custom Challenge", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("ConfigChallengeDialog", "80 Watts", 0, QApplication::UnicodeUTF8));
    startButton->setText(QApplication::translate("ConfigChallengeDialog", "Start!", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(ConfigChallengeDialog);
    } // retranslateUi

};

namespace Ui {
    class ConfigChallengeDialog: public Ui_ConfigChallengeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGCHALLENGE_H
