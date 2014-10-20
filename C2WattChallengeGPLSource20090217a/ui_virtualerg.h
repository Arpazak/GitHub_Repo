/********************************************************************************
** Form generated from reading ui file 'virtualerg.ui'
**
** Created: Mon Feb 16 22:29:40 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_VIRTUALERG_H
#define UI_VIRTUALERG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VirtualErg
{
public:
    QSlider *verticalSlider;
    QSpinBox *spinBox;
    QLabel *label;

    void setupUi(QWidget *VirtualErg)
    {
    if (VirtualErg->objectName().isEmpty())
        VirtualErg->setObjectName(QString::fromUtf8("VirtualErg"));
    VirtualErg->resize(180, 518);
    verticalSlider = new QSlider(VirtualErg);
    verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
    verticalSlider->setGeometry(QRect(80, 90, 21, 381));
    QFont font;
    font.setPointSize(6);
    verticalSlider->setFont(font);
    verticalSlider->setMaximum(100);
    verticalSlider->setOrientation(Qt::Vertical);
    verticalSlider->setTickPosition(QSlider::TicksAbove);
    verticalSlider->setTickInterval(50);
    spinBox = new QSpinBox(VirtualErg);
    spinBox->setObjectName(QString::fromUtf8("spinBox"));
    spinBox->setGeometry(QRect(50, 50, 81, 22));
    label = new QLabel(VirtualErg);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 10, 161, 31));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Arial"));
    font1.setPointSize(16);
    label->setFont(font1);
    label->setAlignment(Qt::AlignCenter);

    retranslateUi(VirtualErg);
    QObject::connect(spinBox, SIGNAL(valueChanged(int)), verticalSlider, SLOT(setValue(int)));
    QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    QMetaObject::connectSlotsByName(VirtualErg);
    } // setupUi

    void retranslateUi(QWidget *VirtualErg)
    {
    VirtualErg->setWindowTitle(QApplication::translate("VirtualErg", "Virtual Erg", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("VirtualErg", "V-Erg % Power", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(VirtualErg);
    } // retranslateUi

};

namespace Ui {
    class VirtualErg: public Ui_VirtualErg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIRTUALERG_H
