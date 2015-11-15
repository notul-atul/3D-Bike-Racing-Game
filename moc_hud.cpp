/****************************************************************************
** Meta object code from reading C++ file 'hud.h'
**
** Created: Sun Sep 15 14:36:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hud.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hud.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HUD[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x05,
      35,    4,    4,    4, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HUD[] = {
    "HUD\0\0givekeyPressEvent(QKeyEvent*)\0"
    "givekeyReleaseEvent(QKeyEvent*)\0"
    "getPausedMenuResponce()\0"
};

void HUD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HUD *_t = static_cast<HUD *>(_o);
        switch (_id) {
        case 0: _t->givekeyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 1: _t->givekeyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 2: _t->getPausedMenuResponce(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HUD::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HUD::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HUD,
      qt_meta_data_HUD, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HUD::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HUD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HUD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HUD))
        return static_cast<void*>(const_cast< HUD*>(this));
    return QWidget::qt_metacast(_clname);
}

int HUD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HUD::givekeyPressEvent(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HUD::givekeyReleaseEvent(QKeyEvent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
