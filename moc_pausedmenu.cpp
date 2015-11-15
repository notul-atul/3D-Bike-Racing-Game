/****************************************************************************
** Meta object code from reading C++ file 'pausedmenu.h'
**
** Created: Sat Sep 14 23:45:22 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "pausedmenu.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pausedmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PausedMenu[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   11,   11,   11, 0x08,
      47,   11,   11,   11, 0x08,
      63,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_PausedMenu[] = {
    "PausedMenu\0\0actionPerformed()\0"
    "on_yes_clicked()\0on_no_clicked()\0"
    "getInfo(char*)\0"
};

void PausedMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PausedMenu *_t = static_cast<PausedMenu *>(_o);
        switch (_id) {
        case 0: _t->actionPerformed(); break;
        case 1: _t->on_yes_clicked(); break;
        case 2: _t->on_no_clicked(); break;
        case 3: _t->getInfo((*reinterpret_cast< char*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PausedMenu::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PausedMenu::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_PausedMenu,
      qt_meta_data_PausedMenu, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PausedMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PausedMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PausedMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PausedMenu))
        return static_cast<void*>(const_cast< PausedMenu*>(this));
    return QDialog::qt_metacast(_clname);
}

int PausedMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PausedMenu::actionPerformed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
