/********************************************************************************
** Form generated from reading UI file 'selectprofile.ui'
**
** Created: Sat Sep 14 04:06:01 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPROFILE_H
#define UI_SELECTPROFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SelectProfile
{
public:
    QComboBox *profilesNames;
    QPushButton *delete_2;
    QPushButton *load;
    QPushButton *back;
    QLabel *desc;
    QRadioButton *easy;
    QRadioButton *hard;

    void setupUi(QDialog *SelectProfile)
    {
        if (SelectProfile->objectName().isEmpty())
            SelectProfile->setObjectName(QString::fromUtf8("SelectProfile"));
        SelectProfile->resize(400, 300);
        SelectProfile->setStyleSheet(QString::fromUtf8("background-image:url(load-bike.jpg)\n"
""));
        profilesNames = new QComboBox(SelectProfile);
        profilesNames->setObjectName(QString::fromUtf8("profilesNames"));
        profilesNames->setGeometry(QRect(30, 30, 341, 32));
        profilesNames->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        profilesNames->setEditable(false);
        profilesNames->setMaxVisibleItems(10);
        delete_2 = new QPushButton(SelectProfile);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setGeometry(QRect(240, 200, 151, 32));
        delete_2->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        load = new QPushButton(SelectProfile);
        load->setObjectName(QString::fromUtf8("load"));
        load->setGeometry(QRect(240, 250, 151, 32));
        load->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        back = new QPushButton(SelectProfile);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(10, 250, 151, 32));
        back->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        desc = new QLabel(SelectProfile);
        desc->setObjectName(QString::fromUtf8("desc"));
        desc->setGeometry(QRect(250, 70, 131, 71));
        desc->setStyleSheet(QString::fromUtf8("background:white"));
        easy = new QRadioButton(SelectProfile);
        easy->setObjectName(QString::fromUtf8("easy"));
        easy->setGeometry(QRect(250, 140, 131, 27));
        easy->setStyleSheet(QString::fromUtf8(""));
        easy->setChecked(true);
        hard = new QRadioButton(SelectProfile);
        hard->setObjectName(QString::fromUtf8("hard"));
        hard->setGeometry(QRect(250, 170, 131, 27));
        hard->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(SelectProfile);

        profilesNames->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SelectProfile);
    } // setupUi

    void retranslateUi(QDialog *SelectProfile)
    {
        SelectProfile->setWindowTitle(QApplication::translate("SelectProfile", "Select Profile", 0, QApplication::UnicodeUTF8));
        profilesNames->clear();
        profilesNames->insertItems(0, QStringList()
         << QApplication::translate("SelectProfile", " - Select Profile Name - ", 0, QApplication::UnicodeUTF8)
        );
        delete_2->setText(QApplication::translate("SelectProfile", "Delete", 0, QApplication::UnicodeUTF8));
        load->setText(QApplication::translate("SelectProfile", "Load", 0, QApplication::UnicodeUTF8));
        back->setText(QApplication::translate("SelectProfile", "<< Back", 0, QApplication::UnicodeUTF8));
        desc->setText(QApplication::translate("SelectProfile", "<html><head/><body><p>   No Profile</p><p>     Selected</p></body></html>", 0, QApplication::UnicodeUTF8));
        easy->setText(QApplication::translate("SelectProfile", "Easy", 0, QApplication::UnicodeUTF8));
        hard->setText(QApplication::translate("SelectProfile", "Hard", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SelectProfile: public Ui_SelectProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPROFILE_H
