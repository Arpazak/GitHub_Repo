/********************************************************************************
** Form generated from reading ui file 'wattchallenge.ui'
**
** Created: Mon Feb 16 22:29:40 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WATTCHALLENGE_H
#define UI_WATTCHALLENGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "wattmeter.h"

QT_BEGIN_NAMESPACE

class Ui_WattChallengeDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_0;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *timeRowedLabel;
    QLabel *metersRowedLabel;
    QLabel *caloriesBurnedLabel;
    QSpacerItem *verticalSpacer_13;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    WattMeter *wattmeter;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_7;
    QLabel *label;
    QLabel *currentWattsLabel;
    QSpacerItem *verticalSpacer_18;
    QSpacerItem *verticalSpacer_17;
    QSpacerItem *verticalSpacer_16;
    QSpacerItem *verticalSpacer_11;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *WattChallengeDialog)
    {
    if (WattChallengeDialog->objectName().isEmpty())
        WattChallengeDialog->setObjectName(QString::fromUtf8("WattChallengeDialog"));
    WattChallengeDialog->resize(1014, 662);
    WattChallengeDialog->setContextMenuPolicy(Qt::DefaultContextMenu);
    WattChallengeDialog->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
    horizontalLayout = new QHBoxLayout(WattChallengeDialog);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalSpacer_0 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_0);

    verticalLayout = new QVBoxLayout();
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalSpacer_3 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer_3);

    timeRowedLabel = new QLabel(WattChallengeDialog);
    timeRowedLabel->setObjectName(QString::fromUtf8("timeRowedLabel"));
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(timeRowedLabel->sizePolicy().hasHeightForWidth());
    timeRowedLabel->setSizePolicy(sizePolicy);
    timeRowedLabel->setMinimumSize(QSize(340, 0));
    QFont font;
    font.setFamily(QString::fromUtf8("Gill Sans Ultra Bold Condensed"));
    font.setPointSize(26);
    timeRowedLabel->setFont(font);

    verticalLayout->addWidget(timeRowedLabel);

    metersRowedLabel = new QLabel(WattChallengeDialog);
    metersRowedLabel->setObjectName(QString::fromUtf8("metersRowedLabel"));
    metersRowedLabel->setMinimumSize(QSize(340, 0));
    metersRowedLabel->setFont(font);

    verticalLayout->addWidget(metersRowedLabel);

    caloriesBurnedLabel = new QLabel(WattChallengeDialog);
    caloriesBurnedLabel->setObjectName(QString::fromUtf8("caloriesBurnedLabel"));
    caloriesBurnedLabel->setMinimumSize(QSize(340, 0));
    caloriesBurnedLabel->setBaseSize(QSize(0, 0));
    caloriesBurnedLabel->setFont(font);

    verticalLayout->addWidget(caloriesBurnedLabel);

    verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer_13);

    verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer_12);

    verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer_6);

    verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer_5);

    label_2 = new QLabel(WattChallengeDialog);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setPixmap(QPixmap(QString::fromUtf8("C2LogoWattChallenge.PNG")));

    verticalLayout->addWidget(label_2);

    verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer_4);

    verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout->addItem(verticalSpacer);


    horizontalLayout->addLayout(verticalLayout);

    horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer);

    wattmeter = new WattMeter(WattChallengeDialog);
    wattmeter->setObjectName(QString::fromUtf8("wattmeter"));
    wattmeter->setProperty("sizeHint", QVariant(QSize(350, 400)));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(wattmeter->sizePolicy().hasHeightForWidth());
    wattmeter->setSizePolicy(sizePolicy1);
    wattmeter->setMinimumSize(QSize(350, 400));

    horizontalLayout->addWidget(wattmeter);

    horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_2);

    verticalLayout_2 = new QVBoxLayout();
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalSpacer_7 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_7);

    label = new QLabel(WattChallengeDialog);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Gill Sans Ultra Bold Condensed"));
    font1.setPointSize(32);
    label->setFont(font1);

    verticalLayout_2->addWidget(label);

    currentWattsLabel = new QLabel(WattChallengeDialog);
    currentWattsLabel->setObjectName(QString::fromUtf8("currentWattsLabel"));
    QPalette palette;
    QBrush brush(QColor(255, 0, 0, 255));
    brush.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
    QBrush brush1(QColor(255, 255, 255, 255));
    brush1.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Active, QPalette::Window, brush1);
    palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
    palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
    QBrush brush2(QColor(118, 116, 108, 255));
    brush2.setStyle(Qt::SolidPattern);
    palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
    palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
    currentWattsLabel->setPalette(palette);
    QFont font2;
    font2.setFamily(QString::fromUtf8("Gill Sans Ultra Bold Condensed"));
    font2.setPointSize(48);
    currentWattsLabel->setFont(font2);
    currentWattsLabel->setStyleSheet(QString::fromUtf8(""));
    currentWattsLabel->setAlignment(Qt::AlignCenter);

    verticalLayout_2->addWidget(currentWattsLabel);

    verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_18);

    verticalSpacer_17 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_17);

    verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_16);

    verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_11);

    verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_10);

    verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_9);

    verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_8);

    verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

    verticalLayout_2->addItem(verticalSpacer_2);


    horizontalLayout->addLayout(verticalLayout_2);

    horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

    horizontalLayout->addItem(horizontalSpacer_3);


    retranslateUi(WattChallengeDialog);

    QMetaObject::connectSlotsByName(WattChallengeDialog);
    } // setupUi

    void retranslateUi(QWidget *WattChallengeDialog)
    {
    WattChallengeDialog->setWindowTitle(QApplication::translate("WattChallengeDialog", "C2 Watt Challenge", 0, QApplication::UnicodeUTF8));
    timeRowedLabel->setText(QApplication::translate("WattChallengeDialog", "Time Rowed: 00:00", 0, QApplication::UnicodeUTF8));
    metersRowedLabel->setText(QApplication::translate("WattChallengeDialog", "Meters Rowed: 0", 0, QApplication::UnicodeUTF8));
    caloriesBurnedLabel->setText(QApplication::translate("WattChallengeDialog", "Calories Burned: 0", 0, QApplication::UnicodeUTF8));
    label_2->setText(QString());
    label->setText(QApplication::translate("WattChallengeDialog", "Current Watts:", 0, QApplication::UnicodeUTF8));
    currentWattsLabel->setText(QApplication::translate("WattChallengeDialog", "0", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(WattChallengeDialog);
    } // retranslateUi

};

namespace Ui {
    class WattChallengeDialog: public Ui_WattChallengeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WATTCHALLENGE_H
