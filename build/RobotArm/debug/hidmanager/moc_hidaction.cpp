/****************************************************************************
** Meta object code from reading C++ file 'hidaction.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../hidmanager/hidaction.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hidaction.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HidAction_t {
    QByteArrayData data[5];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HidAction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HidAction_t qt_meta_stringdata_HidAction = {
    {
QT_MOC_LITERAL(0, 0, 9), // "HidAction"
QT_MOC_LITERAL(1, 10, 11), // "signTrigger"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 29), // "HidInputEvent::HidInputParams"
QT_MOC_LITERAL(4, 53, 6) // "params"

    },
    "HidAction\0signTrigger\0\0"
    "HidInputEvent::HidInputParams\0params"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HidAction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void HidAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HidAction *_t = static_cast<HidAction *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signTrigger((*reinterpret_cast< const HidInputEvent::HidInputParams(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HidAction::*_t)(const HidInputEvent::HidInputParams & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HidAction::signTrigger)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject HidAction::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HidAction.data,
      qt_meta_data_HidAction,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HidAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HidAction::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HidAction.stringdata0))
        return static_cast<void*>(const_cast< HidAction*>(this));
    return QObject::qt_metacast(_clname);
}

int HidAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void HidAction::signTrigger(const HidInputEvent::HidInputParams & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< HidAction *>(this), &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
