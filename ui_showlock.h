/********************************************************************************
** Form generated from reading UI file 'showlock.ui'
**
** Created: Mon Sep 9 06:43:26 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWLOCK_H
#define UI_SHOWLOCK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showLock
{
public:

    void setupUi(QWidget *showLock)
    {
        if (showLock->objectName().isEmpty())
            showLock->setObjectName(QString::fromUtf8("showLock"));
        showLock->resize(400, 300);
        showLock->setStyleSheet(QString::fromUtf8("background-image:url(lock.jpg)"));

        retranslateUi(showLock);

        QMetaObject::connectSlotsByName(showLock);
    } // setupUi

    void retranslateUi(QWidget *showLock)
    {
        showLock->setWindowTitle(QApplication::translate("showLock", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class showLock: public Ui_showLock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWLOCK_H
