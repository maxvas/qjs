/****************************************************************************
** Meta object code from reading C++ file 'qjssharednode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qjssharednode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qjssharednode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_QJSSharedNode_t {
    QByteArrayData data[12];
    char stringdata[108];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QJSSharedNode_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QJSSharedNode_t qt_meta_stringdata_QJSSharedNode = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 14),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 14),
QT_MOC_LITERAL(4, 45, 2),
QT_MOC_LITERAL(5, 48, 7),
QT_MOC_LITERAL(6, 56, 4),
QT_MOC_LITERAL(7, 61, 7),
QT_MOC_LITERAL(8, 69, 9),
QT_MOC_LITERAL(9, 79, 7),
QT_MOC_LITERAL(10, 87, 7),
QT_MOC_LITERAL(11, 95, 12)
    },
    "QJSSharedNode\0subscribeAdded\0\0"
    "QJSSharedNode*\0sn\0changed\0QJS*\0address\0"
    "operation\0newData\0oldData\0addSubscribe"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QJSSharedNode[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    4,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   41,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::QString, 0x80000000 | 6, 0x80000000 | 6,    7,    8,    9,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void QJSSharedNode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QJSSharedNode *_t = static_cast<QJSSharedNode *>(_o);
        switch (_id) {
        case 0: _t->subscribeAdded((*reinterpret_cast< QJSSharedNode*(*)>(_a[1]))); break;
        case 1: _t->changed((*reinterpret_cast< QJS*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QJS*(*)>(_a[3])),(*reinterpret_cast< QJS*(*)>(_a[4]))); break;
        case 2: _t->addSubscribe((*reinterpret_cast< QJSSharedNode*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QJSSharedNode* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
            case 2:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QJS* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QJSSharedNode* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QJSSharedNode::*_t)(QJSSharedNode * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QJSSharedNode::subscribeAdded)) {
                *result = 0;
            }
        }
        {
            typedef void (QJSSharedNode::*_t)(QJS * , QString , QJS * , QJS * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QJSSharedNode::changed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject QJSSharedNode::staticMetaObject = {
    { &QJS::staticMetaObject, qt_meta_stringdata_QJSSharedNode.data,
      qt_meta_data_QJSSharedNode,  qt_static_metacall, 0, 0}
};


const QMetaObject *QJSSharedNode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QJSSharedNode::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QJSSharedNode.stringdata))
        return static_cast<void*>(const_cast< QJSSharedNode*>(this));
    return QJS::qt_metacast(_clname);
}

int QJSSharedNode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QJS::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QJSSharedNode::subscribeAdded(QJSSharedNode * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QJSSharedNode::changed(QJS * _t1, QString _t2, QJS * _t3, QJS * _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
