/****************************************************************************
** Meta object code from reading C++ file 'myhisto.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "myhisto.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myhisto.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_myHisto_t {
    QByteArrayData data[8];
    char stringdata[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myHisto_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myHisto_t qt_meta_stringdata_myHisto = {
    {
QT_MOC_LITERAL(0, 0, 7), // "myHisto"
QT_MOC_LITERAL(1, 8, 8), // "setScale"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 11), // "increasePan"
QT_MOC_LITERAL(4, 30, 11), // "decreasePan"
QT_MOC_LITERAL(5, 42, 7), // "setData"
QT_MOC_LITERAL(6, 50, 16), // "QVector<QPoint>*"
QT_MOC_LITERAL(7, 67, 4) // "data"

    },
    "myHisto\0setScale\0\0increasePan\0decreasePan\0"
    "setData\0QVector<QPoint>*\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myHisto[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       3,    0,   37,    2, 0x0a /* Public */,
       4,    0,   38,    2, 0x0a /* Public */,
       5,    1,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void myHisto::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        myHisto *_t = static_cast<myHisto *>(_o);
        switch (_id) {
        case 0: _t->setScale((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->increasePan(); break;
        case 2: _t->decreasePan(); break;
        case 3: _t->setData((*reinterpret_cast< QVector<QPoint>*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject myHisto::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_myHisto.data,
      qt_meta_data_myHisto,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *myHisto::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myHisto::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_myHisto.stringdata))
        return static_cast<void*>(const_cast< myHisto*>(this));
    return QLabel::qt_metacast(_clname);
}

int myHisto::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
