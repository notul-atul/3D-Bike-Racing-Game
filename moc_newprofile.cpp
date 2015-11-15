/****************************************************************************
** Meta object code from reading C++ file 'newprofile.h'
**
** Created: Sun Sep 15 01:22:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "newprofile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'newprofile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NewProfile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      30,   11,   11,   11, 0x08,
      51,   11,   11,   11, 0x08,
      70,   11,   11,   11, 0x08,
      88,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NewProfile[] = {
    "NewProfile\0\0on_back_clicked()\0"
    "enableStart(QString)\0on_start_clicked()\0"
    "on_easy_clicked()\0on_hard_clicked()\0"
};

void NewProfile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        NewProfile *_t = static_cast<NewProfile *>(_o);
        switch (_id) {
        case 0: _t->on_back_clicked(); break;
        case 1: _t->enableStart((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_start_clicked(); break;
        case 3: _t->on_easy_clicked(); break;
        case 4: _t->on_hard_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData NewProfile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject NewProfile::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_NewProfile,
      qt_meta_data_NewProfile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NewProfile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NewProfile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NewProfile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NewProfile))
        return static_cast<void*>(const_cast< NewProfile*>(this));
    return QDialog::qt_metacast(_clname);
}

int NewProfile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
