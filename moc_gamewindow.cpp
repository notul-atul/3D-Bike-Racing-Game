/****************************************************************************
** Meta object code from reading C++ file 'gamewindow.h'
**
** Created: Sun Sep 15 14:36:48 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gamewindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_gameWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   12,   11,   11, 0x05,
      39,   11,   11,   11, 0x05,
      57,   11,   11,   11, 0x05,
      76,   73,   11,   11, 0x05,
     105,   11,   11,   11, 0x05,
     125,  120,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     141,   11,   11,   11, 0x0a,
     170,   11,   11,   11, 0x0a,
     201,   11,   11,   11, 0x08,
     211,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_gameWindow[] = {
    "gameWindow\0\0speed\0speedChanged(double)\0"
    "giveTimeLeft(int)\0givePoints(int)\0,,\0"
    "giveCoordinates(int,int,int)\0"
    "timeOver(bool)\0info\0giveInfo(char*)\0"
    "getkeyPressEvent(QKeyEvent*)\0"
    "getkeyReleaseEvent(QKeyEvent*)\0update1()\0"
    "emmitTimeLeft()\0"
};

void gameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        gameWindow *_t = static_cast<gameWindow *>(_o);
        switch (_id) {
        case 0: _t->speedChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->giveTimeLeft((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->givePoints((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->giveCoordinates((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->timeOver((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->giveInfo((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 6: _t->getkeyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 7: _t->getkeyReleaseEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 8: _t->update1(); break;
        case 9: _t->emmitTimeLeft(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData gameWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject gameWindow::staticMetaObject = {
    { &QGLWidget::staticMetaObject, qt_meta_stringdata_gameWindow,
      qt_meta_data_gameWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &gameWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *gameWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *gameWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_gameWindow))
        return static_cast<void*>(const_cast< gameWindow*>(this));
    return QGLWidget::qt_metacast(_clname);
}

int gameWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void gameWindow::speedChanged(double _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void gameWindow::giveTimeLeft(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void gameWindow::givePoints(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void gameWindow::giveCoordinates(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void gameWindow::timeOver(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void gameWindow::giveInfo(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
