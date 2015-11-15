/********************************************************************************
** Form generated from reading UI file 'selecttrack.ui'
**
** Created: Tue Sep 10 03:02:45 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTTRACK_H
#define UI_SELECTTRACK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLayout>
#include <QtGui/QPushButton>
#include <QtGui/QToolBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectTrack
{
public:
    QPushButton *pushButton;
    QToolBox *toolBox;
    QWidget *Track_1;
    QWidget *Track_2;
    QWidget *Track_3;
    QWidget *widget;
    QWidget *Track_4;
    QWidget *Track_5;
    QWidget *Track_6;
    QWidget *Track_7;
    QWidget *Track_8;
    QWidget *Track_9;
    QWidget *Track_10;
    QPushButton *back;

    void setupUi(QDialog *SelectTrack)
    {
        if (SelectTrack->objectName().isEmpty())
            SelectTrack->setObjectName(QString::fromUtf8("SelectTrack"));
        SelectTrack->resize(1292, 825);
        pushButton = new QPushButton(SelectTrack);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(996, 790, 291, 32));
        pushButton->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        toolBox = new QToolBox(SelectTrack);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(20, 10, 1261, 771));
        Track_1 = new QWidget();
        Track_1->setObjectName(QString::fromUtf8("Track_1"));
        Track_1->setGeometry(QRect(0, 0, 1261, 411));
        toolBox->addItem(Track_1, QString::fromUtf8("Track 1"));
        Track_2 = new QWidget();
        Track_2->setObjectName(QString::fromUtf8("Track_2"));
        Track_2->setGeometry(QRect(0, 0, 1261, 411));
        toolBox->addItem(Track_2, QString::fromUtf8("Track 2"));
        Track_3 = new QWidget();
        Track_3->setObjectName(QString::fromUtf8("Track_3"));
        Track_3->setGeometry(QRect(0, 0, 1261, 411));
        widget = new QWidget(Track_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(380, 350, 120, 80));
        toolBox->addItem(Track_3, QString::fromUtf8("Track 3"));
        Track_4 = new QWidget();
        Track_4->setObjectName(QString::fromUtf8("Track_4"));
        Track_4->setGeometry(QRect(0, 0, 1261, 411));
        toolBox->addItem(Track_4, QString::fromUtf8("Track 4"));
        Track_5 = new QWidget();
        Track_5->setObjectName(QString::fromUtf8("Track_5"));
        Track_5->setGeometry(QRect(0, 0, 1261, 411));
        toolBox->addItem(Track_5, QString::fromUtf8("Track 5"));
        Track_6 = new QWidget();
        Track_6->setObjectName(QString::fromUtf8("Track_6"));
        Track_6->setGeometry(QRect(0, 0, 1261, 411));
        toolBox->addItem(Track_6, QString::fromUtf8("Track 6"));
        Track_7 = new QWidget();
        Track_7->setObjectName(QString::fromUtf8("Track_7"));
        Track_7->setGeometry(QRect(0, 0, 1261, 411));
        toolBox->addItem(Track_7, QString::fromUtf8("Track 7"));
        Track_8 = new QWidget();
        Track_8->setObjectName(QString::fromUtf8("Track_8"));
        Track_8->setGeometry(QRect(0, 0, 1261, 411));
        toolBox->addItem(Track_8, QString::fromUtf8("Track 8"));
        Track_9 = new QWidget();
        Track_9->setObjectName(QString::fromUtf8("Track_9"));
        Track_9->setGeometry(QRect(0, 0, 1261, 411));
        toolBox->addItem(Track_9, QString::fromUtf8("Track 9"));
        Track_10 = new QWidget();
        Track_10->setObjectName(QString::fromUtf8("Track_10"));
        Track_10->setGeometry(QRect(0, 0, 1261, 411));
        toolBox->addItem(Track_10, QString::fromUtf8("Track 10"));
        back = new QPushButton(SelectTrack);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(30, 790, 291, 32));
        back->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));

        retranslateUi(SelectTrack);

        toolBox->setCurrentIndex(9);


        QMetaObject::connectSlotsByName(SelectTrack);
    } // setupUi

    void retranslateUi(QDialog *SelectTrack)
    {
        SelectTrack->setWindowTitle(QApplication::translate("SelectTrack", "Select Track", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SelectTrack", "Play", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(Track_1), QApplication::translate("SelectTrack", "Track 1", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(Track_2), QApplication::translate("SelectTrack", "Track 2", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(Track_3), QApplication::translate("SelectTrack", "Track 3", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(Track_4), QApplication::translate("SelectTrack", "Track 4", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(Track_5), QApplication::translate("SelectTrack", "Track 5", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(Track_6), QApplication::translate("SelectTrack", "Track 6", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(Track_7), QApplication::translate("SelectTrack", "Track 7", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(Track_8), QApplication::translate("SelectTrack", "Track 8", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(Track_9), QApplication::translate("SelectTrack", "Track 9", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(Track_10), QApplication::translate("SelectTrack", "Track 10", 0, QApplication::UnicodeUTF8));
        back->setText(QApplication::translate("SelectTrack", "<< Back", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SelectTrack: public Ui_SelectTrack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTTRACK_H
