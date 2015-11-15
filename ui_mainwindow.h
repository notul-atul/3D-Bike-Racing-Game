/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu Sep 12 16:02:31 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *newGame;
    QPushButton *freeRome;
    QPushButton *load;
    QPushButton *options;
    QPushButton *highScore;
    QPushButton *quit;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1349, 970);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image:url(bike-race.jpeg)\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        newGame = new QPushButton(centralWidget);
        newGame->setObjectName(QString::fromUtf8("newGame"));
        newGame->setGeometry(QRect(570, 360, 301, 32));
        newGame->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:3px solid white;\n"
"border-radius:15px;\n"
"}"));
        freeRome = new QPushButton(centralWidget);
        freeRome->setObjectName(QString::fromUtf8("freeRome"));
        freeRome->setGeometry(QRect(570, 420, 301, 32));
        freeRome->setStyleSheet(QString::fromUtf8("border:3px solid white ;\n"
"border-radius:15px"));
        load = new QPushButton(centralWidget);
        load->setObjectName(QString::fromUtf8("load"));
        load->setGeometry(QRect(570, 490, 301, 32));
        load->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        options = new QPushButton(centralWidget);
        options->setObjectName(QString::fromUtf8("options"));
        options->setGeometry(QRect(570, 550, 301, 32));
        options->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        highScore = new QPushButton(centralWidget);
        highScore->setObjectName(QString::fromUtf8("highScore"));
        highScore->setGeometry(QRect(570, 610, 301, 32));
        highScore->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        quit = new QPushButton(centralWidget);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(570, 670, 301, 32));
        quit->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);
        QObject::connect(quit, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        newGame->setText(QApplication::translate("MainWindow", "Start New Game", 0, QApplication::UnicodeUTF8));
        freeRome->setText(QApplication::translate("MainWindow", "Practice", 0, QApplication::UnicodeUTF8));
        load->setText(QApplication::translate("MainWindow", "Load", 0, QApplication::UnicodeUTF8));
        options->setText(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        highScore->setText(QApplication::translate("MainWindow", "High Score", 0, QApplication::UnicodeUTF8));
        quit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
