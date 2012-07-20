/****************************************************************************
** Meta object code from reading C++ file 'rc_server.h'
**
** Created: Thu Jul 19 16:40:49 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "rc_server.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rc_server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_rc_server[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      27,   10,   10,   10, 0x08,
      46,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_rc_server[] = {
    "rc_server\0\0addConnection()\0"
    "removeConnection()\0receiveMessage()\0"
};

void rc_server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        rc_server *_t = static_cast<rc_server *>(_o);
        switch (_id) {
        case 0: _t->addConnection(); break;
        case 1: _t->removeConnection(); break;
        case 2: _t->receiveMessage(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData rc_server::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject rc_server::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_rc_server,
      qt_meta_data_rc_server, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &rc_server::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *rc_server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *rc_server::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_rc_server))
        return static_cast<void*>(const_cast< rc_server*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int rc_server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
