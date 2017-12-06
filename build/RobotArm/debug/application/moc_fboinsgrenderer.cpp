/****************************************************************************
** Meta object code from reading C++ file 'fboinsgrenderer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../application/fboinsgrenderer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fboinsgrenderer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_FboInSGRenderer_t {
    QByteArrayData data[18];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FboInSGRenderer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FboInSGRenderer_t qt_meta_stringdata_FboInSGRenderer = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FboInSGRenderer"
QT_MOC_LITERAL(1, 16, 14), // "signKeyPressed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 4), // "name"
QT_MOC_LITERAL(4, 37, 10), // "QKeyEvent*"
QT_MOC_LITERAL(5, 48, 5), // "event"
QT_MOC_LITERAL(6, 54, 15), // "signKeyReleased"
QT_MOC_LITERAL(7, 70, 22), // "signMouseDoubleClicked"
QT_MOC_LITERAL(8, 93, 12), // "QMouseEvent*"
QT_MOC_LITERAL(9, 106, 14), // "signMouseMoved"
QT_MOC_LITERAL(10, 121, 16), // "signMousePressed"
QT_MOC_LITERAL(11, 138, 17), // "signMouseReleased"
QT_MOC_LITERAL(12, 156, 22), // "signWheelEventOccurred"
QT_MOC_LITERAL(13, 179, 12), // "QWheelEvent*"
QT_MOC_LITERAL(14, 192, 15), // "onWindowChanged"
QT_MOC_LITERAL(15, 208, 13), // "QQuickWindow*"
QT_MOC_LITERAL(16, 222, 6), // "window"
QT_MOC_LITERAL(17, 229, 11) // "rcpair_name"

    },
    "FboInSGRenderer\0signKeyPressed\0\0name\0"
    "QKeyEvent*\0event\0signKeyReleased\0"
    "signMouseDoubleClicked\0QMouseEvent*\0"
    "signMouseMoved\0signMousePressed\0"
    "signMouseReleased\0signWheelEventOccurred\0"
    "QWheelEvent*\0onWindowChanged\0QQuickWindow*\0"
    "window\0rcpair_name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FboInSGRenderer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       1,   92, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       6,    2,   59,    2, 0x06 /* Public */,
       7,    2,   64,    2, 0x06 /* Public */,
       9,    2,   69,    2, 0x06 /* Public */,
      10,    2,   74,    2, 0x06 /* Public */,
      11,    2,   79,    2, 0x06 /* Public */,
      12,    2,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   89,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 8,    3,    5,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    3,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,   16,

 // properties: name, type, flags
      17, QMetaType::QString, 0x00095003,

       0        // eod
};

void FboInSGRenderer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FboInSGRenderer *_t = static_cast<FboInSGRenderer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signKeyPressed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QKeyEvent*(*)>(_a[2]))); break;
        case 1: _t->signKeyReleased((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QKeyEvent*(*)>(_a[2]))); break;
        case 2: _t->signMouseDoubleClicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 3: _t->signMouseMoved((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 4: _t->signMousePressed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 5: _t->signMouseReleased((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 6: _t->signWheelEventOccurred((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QWheelEvent*(*)>(_a[2]))); break;
        case 7: _t->onWindowChanged((*reinterpret_cast< QQuickWindow*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FboInSGRenderer::*_t)(const QString & , QKeyEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FboInSGRenderer::signKeyPressed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FboInSGRenderer::*_t)(const QString & , QKeyEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FboInSGRenderer::signKeyReleased)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FboInSGRenderer::*_t)(const QString & , QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FboInSGRenderer::signMouseDoubleClicked)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FboInSGRenderer::*_t)(const QString & , QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FboInSGRenderer::signMouseMoved)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (FboInSGRenderer::*_t)(const QString & , QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FboInSGRenderer::signMousePressed)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (FboInSGRenderer::*_t)(const QString & , QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FboInSGRenderer::signMouseReleased)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (FboInSGRenderer::*_t)(const QString & , QWheelEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FboInSGRenderer::signWheelEventOccurred)) {
                *result = 6;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        FboInSGRenderer *_t = static_cast<FboInSGRenderer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->rcPairName(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        FboInSGRenderer *_t = static_cast<FboInSGRenderer *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRcPairName(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject FboInSGRenderer::staticMetaObject = {
    { &QQuickFramebufferObject::staticMetaObject, qt_meta_stringdata_FboInSGRenderer.data,
      qt_meta_data_FboInSGRenderer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FboInSGRenderer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FboInSGRenderer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FboInSGRenderer.stringdata0))
        return static_cast<void*>(const_cast< FboInSGRenderer*>(this));
    return QQuickFramebufferObject::qt_metacast(_clname);
}

int FboInSGRenderer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickFramebufferObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void FboInSGRenderer::signKeyPressed(const QString & _t1, QKeyEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FboInSGRenderer::signKeyReleased(const QString & _t1, QKeyEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FboInSGRenderer::signMouseDoubleClicked(const QString & _t1, QMouseEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FboInSGRenderer::signMouseMoved(const QString & _t1, QMouseEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FboInSGRenderer::signMousePressed(const QString & _t1, QMouseEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void FboInSGRenderer::signMouseReleased(const QString & _t1, QMouseEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void FboInSGRenderer::signWheelEventOccurred(const QString & _t1, QWheelEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
