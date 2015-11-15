/********************************************************************************
** Form generated from reading UI file 'hud.ui'
**
** Created: Sun Sep 15 01:22:00 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUD_H
#define UI_HUD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QWidget>
#include "speedometer.h"

QT_BEGIN_NAMESPACE

class Ui_HUD
{
public:
    QWidget *displayWindow;
    QLCDNumber *speed;
    QLabel *label;
    QLabel *label_2;
    QLCDNumber *points;
    QLabel *label_3;
    QLCDNumber *timeellipsis;
    SpeedoMeter *speedoMeter;
    QWidget *mapWindow;
    QLabel *Player_Name;

    void setupUi(QWidget *HUD)
    {
        if (HUD->objectName().isEmpty())
            HUD->setObjectName(QString::fromUtf8("HUD"));
        HUD->resize(1358, 856);
        displayWindow = new QWidget(HUD);
        displayWindow->setObjectName(QString::fromUtf8("displayWindow"));
        displayWindow->setGeometry(QRect(200, 0, 1151, 851));
        speed = new QLCDNumber(HUD);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setGeometry(QRect(30, 790, 121, 23));
        speed->setNumDigits(10);
        speed->setSegmentStyle(QLCDNumber::Flat);
        label = new QLabel(HUD);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 630, 121, 22));
        label_2 = new QLabel(HUD);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 170, 83, 22));
        points = new QLCDNumber(HUD);
        points->setObjectName(QString::fromUtf8("points"));
        points->setGeometry(QRect(10, 200, 121, 23));
        points->setNumDigits(10);
        points->setSegmentStyle(QLCDNumber::Flat);
        label_3 = new QLabel(HUD);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 230, 131, 22));
        timeellipsis = new QLCDNumber(HUD);
        timeellipsis->setObjectName(QString::fromUtf8("timeellipsis"));
        timeellipsis->setGeometry(QRect(10, 260, 121, 23));
        timeellipsis->setNumDigits(10);
        timeellipsis->setSegmentStyle(QLCDNumber::Flat);
        speedoMeter = new SpeedoMeter(HUD);
        speedoMeter->setObjectName(QString::fromUtf8("speedoMeter"));
        speedoMeter->setGeometry(QRect(10, 659, 181, 121));
        mapWindow = new QWidget(HUD);
        mapWindow->setObjectName(QString::fromUtf8("mapWindow"));
        mapWindow->setGeometry(QRect(10, 400, 181, 221));
        Player_Name = new QLabel(HUD);
        Player_Name->setObjectName(QString::fromUtf8("Player_Name"));
        Player_Name->setGeometry(QRect(10, 20, 171, 31));

        retranslateUi(HUD);

        QMetaObject::connectSlotsByName(HUD);
    } // setupUi

    void retranslateUi(QWidget *HUD)
    {
        HUD->setWindowTitle(QApplication::translate("HUD", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("HUD", "Speed :-", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("HUD", "Points :-", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("HUD", "Time Left :-", 0, QApplication::UnicodeUTF8));
        Player_Name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HUD: public Ui_HUD {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUD_H
