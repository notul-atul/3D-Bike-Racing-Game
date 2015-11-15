/********************************************************************************
** Form generated from reading UI file 'newprofile.ui'
**
** Created: Sat Sep 14 04:02:51 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROFILE_H
#define UI_NEWPROFILE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_NewProfile
{
public:
    QPushButton *start;
    QPushButton *back;
    QLabel *label;
    QLineEdit *lineEdit;
    QRadioButton *easy;
    QRadioButton *hard;

    void setupUi(QDialog *NewProfile)
    {
        if (NewProfile->objectName().isEmpty())
            NewProfile->setObjectName(QString::fromUtf8("NewProfile"));
        NewProfile->resize(555, 384);
        NewProfile->setStyleSheet(QString::fromUtf8("background-image:url(bike2.jpg)"));
        start = new QPushButton(NewProfile);
        start->setObjectName(QString::fromUtf8("start"));
        start->setEnabled(false);
        start->setGeometry(QRect(316, 310, 211, 32));
        start->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        back = new QPushButton(NewProfile);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(20, 310, 201, 32));
        back->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        label = new QLabel(NewProfile);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 531, 21));
        label->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(NewProfile);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(290, 40, 261, 32));
        lineEdit->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        easy = new QRadioButton(NewProfile);
        easy->setObjectName(QString::fromUtf8("easy"));
        easy->setGeometry(QRect(460, 80, 91, 27));
        easy->setChecked(true);
        hard = new QRadioButton(NewProfile);
        hard->setObjectName(QString::fromUtf8("hard"));
        hard->setGeometry(QRect(460, 110, 91, 27));

        retranslateUi(NewProfile);

        QMetaObject::connectSlotsByName(NewProfile);
    } // setupUi

    void retranslateUi(QDialog *NewProfile)
    {
        NewProfile->setWindowTitle(QApplication::translate("NewProfile", "Create New Profile", 0, QApplication::UnicodeUTF8));
        start->setText(QApplication::translate("NewProfile", "Start>>", 0, QApplication::UnicodeUTF8));
        back->setText(QApplication::translate("NewProfile", "<<Back", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewProfile", "Enter Your Profile Name :-", 0, QApplication::UnicodeUTF8));
        easy->setText(QApplication::translate("NewProfile", "Easy", 0, QApplication::UnicodeUTF8));
        hard->setText(QApplication::translate("NewProfile", "Hard", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewProfile: public Ui_NewProfile {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROFILE_H
