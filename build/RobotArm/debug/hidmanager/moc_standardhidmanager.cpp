/****************************************************************************
** Meta object code from reading C++ file 'standardhidmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../hidmanager/standardhidmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'standardhidmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_StandardHidManager_t {
    QByteArrayData data[14];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StandardHidManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StandardHidManager_t qt_meta_stringdata_StandardHidManager = {
    {
QT_MOC_LITERAL(0, 0, 18), // "StandardHidManager"
QT_MOC_LITERAL(1, 19, 23), // "registerMousePressEvent"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 4), // "name"
QT_MOC_LITERAL(4, 49, 12), // "QMouseEvent*"
QT_MOC_LITERAL(5, 62, 5), // "event"
QT_MOC_LITERAL(6, 68, 25), // "registerMouseReleaseEvent"
QT_MOC_LITERAL(7, 94, 29), // "registerMouseDoubleClickEvent"
QT_MOC_LITERAL(8, 124, 22), // "registerMouseMoveEvent"
QT_MOC_LITERAL(9, 147, 21), // "registerKeyPressEvent"
QT_MOC_LITERAL(10, 169, 10), // "QKeyEvent*"
QT_MOC_LITERAL(11, 180, 23), // "registerKeyReleaseEvent"
QT_MOC_LITERAL(12, 204, 18), // "registerWheelEvent"
QT_MOC_LITERAL(13, 223, 12) // "QWheelEvent*"

    },
    "StandardHidManager\0registerMousePressEvent\0"
    "\0name\0QMouseEvent*\0event\0"
    "registerMouseReleaseEvent\0"
    "registerMouseDoubleClickEvent\0"
    "registerMouseMoveEvent\0registerKeyPressEvent\0"
    "QKeyEvent*\0registerKeyReleaseEvent\0"
    "registerWheelEvent\0QWheelEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StandardHidManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   49,    2, 0x0a /* Public */,
       6,    2,   54,    2, 0x0a /* Public */,
       7,    2,   59,    2, 0x0a /* Public */,
       8,    2,   64,    2, 0x0a /* Public */,
       9,    2,   69,    2, 0x0a /* Public */,
      11,    2,   74,    2, 0x0a /* Public */,
      12,    2,   79,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 10,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    3,    5,

       0        // eod
};

void StandardHidManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StandardHidManager *_t = static_cast<StandardHidManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->registerMousePressEvent((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 1: _t->registerMouseReleaseEvent((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 2: _t->registerMouseDoubleClickEvent((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 3: _t->registerMouseMoveEvent((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 4: _t->registerKeyPressEvent((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QKeyEvent*(*)>(_a[2]))); break;
        case 5: _t->registerKeyReleaseEvent((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QKeyEvent*(*)>(_a[2]))); break;
        case 6: _t->registerWheelEvent((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QWheelEvent*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject StandardHidManager::staticMetaObject = {
    { &HidManager::staticMetaObject, qt_meta_stringdata_StandardHidManager.data,
      qt_meta_data_StandardHidManager,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StandardHidManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StandardHidManager::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StandardHidManager.stringdata0))
        return static_cast<void*>(const_cast< StandardHidManager*>(this));
    return HidManager::qt_metacast(_clname);
}

int StandardHidManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = HidManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
