/****************************************************************************
** Meta object code from reading C++ file 'guiapplication.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../application/guiapplication.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guiapplication.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GuiApplication_t {
    QByteArrayData data[6];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GuiApplication_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GuiApplication_t qt_meta_stringdata_GuiApplication = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GuiApplication"
QT_MOC_LITERAL(1, 15, 31), // "signOnSceneGraphInitializedDone"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 23), // "onSceneGraphInitialized"
QT_MOC_LITERAL(4, 72, 23), // "onSceneGraphInvalidated"
QT_MOC_LITERAL(5, 96, 28) // "afterOnSceneGraphInitialized"

    },
    "GuiApplication\0signOnSceneGraphInitializedDone\0"
    "\0onSceneGraphInitialized\0"
    "onSceneGraphInvalidated\0"
    "afterOnSceneGraphInitialized"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GuiApplication[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x08 /* Private */,
       4,    0,   36,    2, 0x08 /* Private */,
       5,    0,   37,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GuiApplication::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GuiApplication *_t = static_cast<GuiApplication *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signOnSceneGraphInitializedDone(); break;
        case 1: _t->onSceneGraphInitialized(); break;
        case 2: _t->onSceneGraphInvalidated(); break;
        case 3: _t->afterOnSceneGraphInitialized(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (GuiApplication::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&GuiApplication::signOnSceneGraphInitializedDone)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject GuiApplication::staticMetaObject = {
    { &QGuiApplication::staticMetaObject, qt_meta_stringdata_GuiApplication.data,
      qt_meta_data_GuiApplication,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *GuiApplication::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GuiApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_GuiApplication.stringdata0))
        return static_cast<void*>(const_cast< GuiApplication*>(this));
    return QGuiApplication::qt_metacast(_clname);
}

int GuiApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGuiApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void GuiApplication::signOnSceneGraphInitializedDone()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
