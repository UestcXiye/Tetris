/****************************************************************************
** Meta object code from reading C++ file 'myview.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../myGame/myview.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x0a,
      20,    7,    7,    7, 0x0a,
      36,    7,    7,    7, 0x0a,
      46,    7,    7,    7, 0x0a,
      57,    7,    7,    7, 0x0a,
      71,    7,    7,    7, 0x0a,
      84,    7,    7,    7, 0x0a,
      96,    7,    7,    7, 0x0a,
     109,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyView[] = {
    "MyView\0\0startGame()\0clearFullRows()\0"
    "moveBox()\0gameOver()\0restartGame()\0"
    "finishGame()\0pauseGame()\0returnGame()\0"
    "aboutToFinish()\0"
};

void MyView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyView *_t = static_cast<MyView *>(_o);
        switch (_id) {
        case 0: _t->startGame(); break;
        case 1: _t->clearFullRows(); break;
        case 2: _t->moveBox(); break;
        case 3: _t->gameOver(); break;
        case 4: _t->restartGame(); break;
        case 5: _t->finishGame(); break;
        case 6: _t->pauseGame(); break;
        case 7: _t->returnGame(); break;
        case 8: _t->aboutToFinish(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MyView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_MyView,
      qt_meta_data_MyView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyView))
        return static_cast<void*>(const_cast< MyView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int MyView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
