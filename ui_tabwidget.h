/********************************************************************************
** Form generated from reading UI file 'tabwidget.ui'
**
** Created: Wed Sep 4 15:53:51 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABWIDGET_H
#define UI_TABWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabWidget
{
public:
    QWidget *tab;
    QPushButton *pushButton;
    QWidget *tab1;

    void setupUi(QTabWidget *TabWidget)
    {
        if (TabWidget->objectName().isEmpty())
            TabWidget->setObjectName(QString::fromUtf8("TabWidget"));
        TabWidget->resize(400, 300);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 230, 117, 32));
        TabWidget->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        TabWidget->addTab(tab1, QString());

        retranslateUi(TabWidget);

        QMetaObject::connectSlotsByName(TabWidget);
    } // setupUi

    void retranslateUi(QTabWidget *TabWidget)
    {
        TabWidget->setWindowTitle(QApplication::translate("TabWidget", "TabWidget", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("TabWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        TabWidget->setTabText(TabWidget->indexOf(tab), QApplication::translate("TabWidget", "Tab 1", 0, QApplication::UnicodeUTF8));
        TabWidget->setTabText(TabWidget->indexOf(tab1), QApplication::translate("TabWidget", "Tab 2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TabWidget: public Ui_TabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABWIDGET_H
