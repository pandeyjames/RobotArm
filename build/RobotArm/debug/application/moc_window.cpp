/****************************************************************************
** Meta object code from reading C++ file 'window.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../application/window.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Window_t {
    QByteArrayData data[19];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Window_t qt_meta_stringdata_Window = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Window"
QT_MOC_LITERAL(1, 7, 28), // "signRcPairActiveStateChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4), // "name"
QT_MOC_LITERAL(4, 42, 5), // "state"
QT_MOC_LITERAL(5, 48, 25), // "signRcPairViewportChanged"
QT_MOC_LITERAL(6, 74, 8), // "geometry"
QT_MOC_LITERAL(7, 83, 14), // "signFrameReady"
QT_MOC_LITERAL(8, 98, 14), // "signKeyPressed"
QT_MOC_LITERAL(9, 113, 10), // "QKeyEvent*"
QT_MOC_LITERAL(10, 124, 5), // "event"
QT_MOC_LITERAL(11, 130, 15), // "signKeyReleased"
QT_MOC_LITERAL(12, 146, 22), // "signMouseDoubleClicked"
QT_MOC_LITERAL(13, 169, 12), // "QMouseEvent*"
QT_MOC_LITERAL(14, 182, 14), // "signMouseMoved"
QT_MOC_LITERAL(15, 197, 16), // "signMousePressed"
QT_MOC_LITERAL(16, 214, 17), // "signMouseReleased"
QT_MOC_LITERAL(17, 232, 22), // "signWheelEventOccurred"
QT_MOC_LITERAL(18, 255, 12) // "QWheelEvent*"

    },
    "Window\0signRcPairActiveStateChanged\0"
    "\0name\0state\0signRcPairViewportChanged\0"
    "geometry\0signFrameReady\0signKeyPressed\0"
    "QKeyEvent*\0event\0signKeyReleased\0"
    "signMouseDoubleClicked\0QMouseEvent*\0"
    "signMouseMoved\0signMousePressed\0"
    "signMouseReleased\0signWheelEventOccurred\0"
    "QWheelEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   64,    2, 0x06 /* Public */,
       5,    2,   69,    2, 0x06 /* Public */,
       7,    0,   74,    2, 0x06 /* Public */,
       8,    2,   75,    2, 0x06 /* Public */,
      11,    2,   80,    2, 0x06 /* Public */,
      12,    2,   85,    2, 0x06 /* Public */,
      14,    2,   90,    2, 0x06 /* Public */,
      15,    2,   95,    2, 0x06 /* Public */,
      16,    2,  100,    2, 0x06 /* Public */,
      17,    2,  105,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QRectF,    3,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    3,   10,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 9,    3,   10,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    3,   10,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    3,   10,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    3,   10,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 13,    3,   10,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 18,    3,   10,

       0        // eod
};

void Window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Window *_t = static_cast<Window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signRcPairActiveStateChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->signRcPairViewportChanged((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QRectF(*)>(_a[2]))); break;
        case 2: _t->signFrameReady(); break;
        case 3: _t->signKeyPressed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QKeyEvent*(*)>(_a[2]))); break;
        case 4: _t->signKeyReleased((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QKeyEvent*(*)>(_a[2]))); break;
        case 5: _t->signMouseDoubleClicked((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 6: _t->signMouseMoved((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 7: _t->signMousePressed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 8: _t->signMouseReleased((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QMouseEvent*(*)>(_a[2]))); break;
        case 9: _t->signWheelEventOccurred((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< QWheelEvent*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Window::*_t)(const QString & , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Window::signRcPairActiveStateChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Window::*_t)(const QString & , const QRectF & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Window::signRcPairViewportChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Window::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Window::signFrameReady)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Window::*_t)(const QString & , QKeyEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Window::signKeyPressed)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Window::*_t)(const QString & , QKeyEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Window::signKeyReleased)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Window::*_t)(const QString & , QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Window::signMouseDoubleClicked)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Window::*_t)(const QString & , QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Window::signMouseMoved)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Window::*_t)(const QString & , QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Window::signMousePressed)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (Window::*_t)(const QString & , QMouseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Window::signMouseReleased)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (Window::*_t)(const QString & , QWheelEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Window::signWheelEventOccurred)) {
                *result = 9;
                return;
            }
        }
    }
}

const QMetaObject Window::staticMetaObject = {
    { &QQuickView::staticMetaObject, qt_meta_stringdata_Window.data,
      qt_meta_data_Window,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Window::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Window.stringdata0))
        return static_cast<void*>(const_cast< Window*>(this));
    return QQuickView::qt_metacast(_clname);
}

int Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Window::signRcPairActiveStateChanged(const QString & _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Window::signRcPairViewportChanged(const QString & _t1, const QRectF & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Window::signFrameReady()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Window::signKeyPressed(const QString & _t1, QKeyEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Window::signKeyReleased(const QString & _t1, QKeyEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Window::signMouseDoubleClicked(const QString & _t1, QMouseEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Window::signMouseMoved(const QString & _t1, QMouseEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Window::signMousePressed(const QString & _t1, QMouseEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Window::signMouseReleased(const QString & _t1, QMouseEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Window::signWheelEventOccurred(const QString & _t1, QWheelEvent * _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
