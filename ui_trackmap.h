/********************************************************************************
** Form generated from reading UI file 'trackmap.ui'
**
** Created: Sun Sep 8 19:15:04 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKMAP_H
#define UI_TRACKMAP_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrackMap
{
public:

    void setupUi(QWidget *TrackMap)
    {
        if (TrackMap->objectName().isEmpty())
            TrackMap->setObjectName(QString::fromUtf8("TrackMap"));
        TrackMap->resize(400, 300);

        retranslateUi(TrackMap);

        QMetaObject::connectSlotsByName(TrackMap);
    } // setupUi

    void retranslateUi(QWidget *TrackMap)
    {
        TrackMap->setWindowTitle(QApplication::translate("TrackMap", "Form", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TrackMap: public Ui_TrackMap {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKMAP_H
