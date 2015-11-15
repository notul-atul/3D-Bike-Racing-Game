/****************************************************************************
** Meta object code from reading C++ file 'selectprofile.h'
**
** Created: Sun Sep 15 15:30:09 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "selectprofile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'selectprofile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SelectProfile[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      33,   14,   14,   14, 0x08,
      57,   51,   14,   14, 0x08,
      99,   14,   14,   14, 0x08,
     121,   14,   14,   14, 0x08,
     139,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SelectProfile[] = {
    "SelectProfile\0\0on_back_clicked()\0"
    "on_load_clicked()\0index\0"
    "on_profilesNames_currentIndexChanged(int)\0"
    "on_delete_2_clicked()\0on_easy_clicked()\0"
    "on_hard_clicked()\0"
};

void SelectProfile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SelectProfile *_t = static_cast<SelectProfile *>(_o);
        switch (_id) {
        case 0: _t->on_back_clicked(); break;
        case 1: _t->on_load_clicked(); break;
        case 2: _t->on_profilesNames_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_delete_2_clicked(); break;
        case 4: _t->on_easy_clicked(); break;
        case 5: _t->on_hard_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SelectProfile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SelectProfile::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SelectProfile,
      qt_meta_data_SelectProfile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SelectProfile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SelectProfile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SelectProfile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SelectProfile))
        return static_cast<void*>(const_cast< SelectProfile*>(this));
    return QDialog::qt_metacast(_clname);
}

int SelectProfile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
