/****************************************************************************
** Meta object code from reading C++ file 'myview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myGame/myview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyView_t {
    QByteArrayData data[10];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyView_t qt_meta_stringdata_MyView = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MyView"
QT_MOC_LITERAL(1, 7, 9), // "startGame"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 13), // "clearFullRows"
QT_MOC_LITERAL(4, 32, 7), // "moveBox"
QT_MOC_LITERAL(5, 40, 8), // "gameOver"
QT_MOC_LITERAL(6, 49, 11), // "restartGame"
QT_MOC_LITERAL(7, 61, 10), // "finishGame"
QT_MOC_LITERAL(8, 72, 9), // "pauseGame"
QT_MOC_LITERAL(9, 82, 10) // "returnGame"

    },
    "MyView\0startGame\0\0clearFullRows\0moveBox\0"
    "gameOver\0restartGame\0finishGame\0"
    "pauseGame\0returnGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    0,   60,    2, 0x0a /* Public */,
       9,    0,   61,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyView *_t = static_cast<MyView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startGame(); break;
        case 1: _t->clearFullRows(); break;
        case 2: _t->moveBox(); break;
        case 3: _t->gameOver(); break;
        case 4: _t->restartGame(); break;
        case 5: _t->finishGame(); break;
        case 6: _t->pauseGame(); break;
        case 7: _t->returnGame(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_MyView.data,
      qt_meta_data_MyView,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MyView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int MyView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
