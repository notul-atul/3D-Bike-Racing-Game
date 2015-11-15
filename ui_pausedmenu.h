/********************************************************************************
** Form generated from reading UI file 'pausedmenu.ui'
**
** Created: Thu Sep 12 15:50:11 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSEDMENU_H
#define UI_PAUSEDMENU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_PausedMenu
{
public:
    QPushButton *yes;
    QPushButton *no;
    QLabel *label;
    QLabel *pauseinfo;

    void setupUi(QDialog *PausedMenu)
    {
        if (PausedMenu->objectName().isEmpty())
            PausedMenu->setObjectName(QString::fromUtf8("PausedMenu"));
        PausedMenu->resize(400, 300);
        PausedMenu->setStyleSheet(QString::fromUtf8("background-image:url(pause-bike.jpg)\n"
""));
        yes = new QPushButton(PausedMenu);
        yes->setObjectName(QString::fromUtf8("yes"));
        yes->setGeometry(QRect(10, 260, 171, 32));
        yes->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        no = new QPushButton(PausedMenu);
        no->setObjectName(QString::fromUtf8("no"));
        no->setGeometry(QRect(200, 260, 181, 32));
        no->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        label = new QLabel(PausedMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 40, 361, 22));
        label->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;\n"
"background-color: rgba(255, 255, 255, 0);"));
        label->setAlignment(Qt::AlignCenter);
        pauseinfo = new QLabel(PausedMenu);
        pauseinfo->setObjectName(QString::fromUtf8("pauseinfo"));
        pauseinfo->setGeometry(QRect(80, 70, 221, 71));
        pauseinfo->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;\n"
"background-color: rgba(255, 255, 255, 0);"));

        retranslateUi(PausedMenu);

        QMetaObject::connectSlotsByName(PausedMenu);
    } // setupUi

    void retranslateUi(QDialog *PausedMenu)
    {
        PausedMenu->setWindowTitle(QApplication::translate("PausedMenu", "Paused", 0, QApplication::UnicodeUTF8));
        yes->setText(QApplication::translate("PausedMenu", "Yes", 0, QApplication::UnicodeUTF8));
        no->setText(QApplication::translate("PausedMenu", "No", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PausedMenu", "Do You Want To Quit", 0, QApplication::UnicodeUTF8));
        pauseinfo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PausedMenu: public Ui_PausedMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSEDMENU_H
