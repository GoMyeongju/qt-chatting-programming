/****************************************************************************
** Meta object code from reading C++ file 'chatting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../chatting_program/chatting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chatting_t {
    QByteArrayData data[7];
    char stringdata0[110];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chatting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chatting_t qt_meta_stringdata_Chatting = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Chatting"
QT_MOC_LITERAL(1, 9, 9), // "readyRead"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "connected"
QT_MOC_LITERAL(4, 30, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(5, 55, 21), // "on_sendButton_clicked"
QT_MOC_LITERAL(6, 77, 32) // "on_messageLineEdit_returnPressed"

    },
    "Chatting\0readyRead\0\0connected\0"
    "on_connectButton_clicked\0on_sendButton_clicked\0"
    "on_messageLineEdit_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chatting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x08 /* Private */,
       6,    0,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Chatting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Chatting *_t = static_cast<Chatting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readyRead(); break;
        case 1: _t->connected(); break;
        case 2: _t->on_connectButton_clicked(); break;
        case 3: _t->on_sendButton_clicked(); break;
        case 4: _t->on_messageLineEdit_returnPressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Chatting::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Chatting.data,
      qt_meta_data_Chatting,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Chatting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chatting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Chatting.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Chatting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
