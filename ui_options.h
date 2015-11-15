/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created: Sat Sep 14 04:09:48 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(400, 300);
        Options->setStyleSheet(QString::fromUtf8("background-image:url(option-bike.jpg)"));
        label = new QLabel(Options);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 80, 61, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setPointSize(28);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 75 28pt \"Ubuntu\";\n"
"border:3px solid white;\n"
"border-radius:15px;"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Options);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 140, 61, 51));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("font: 75 28pt \"Ubuntu\";\n"
"border:3px solid white;\n"
"border-radius:15px;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Options);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 140, 61, 51));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("font: 75 28pt \"Ubuntu\";\n"
"border:3px solid white;\n"
"border-radius:15px;"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(Options);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 140, 61, 51));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("font: 75 28pt \"Ubuntu\";\n"
"border:3px solid white;\n"
"border-radius:15px;"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(Options);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(190, 90, 83, 22));
        label_6 = new QLabel(Options);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 200, 83, 22));
        label_7 = new QLabel(Options);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(250, 160, 83, 22));
        label_8 = new QLabel(Options);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 110, 83, 22));
        label_9 = new QLabel(Options);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(130, 20, 171, 22));
        pushButton = new QPushButton(Options);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(140, 240, 117, 32));
        pushButton->setStyleSheet(QString::fromUtf8("border:3px solid white;\n"
"border-radius:15px;"));

        retranslateUi(Options);

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Options", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Options", "W", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Options", "S", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Options", "D", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Options", "A", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Options", "Forward", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Options", "Backward", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Options", "Left", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Options", "Right", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Options", "Key Board Controls", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Options", "O.K.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
