/****************************************************************************
** Meta object code from reading C++ file 'StateCanvas.h'
**
** Created: Fri May 24 23:48:40 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "diagram/StateCanvas.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'StateCanvas.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_StateCanvas[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,
      24,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_StateCanvas[] = {
    "StateCanvas\0\0modified()\0deleted()\0"
};

void StateCanvas::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        StateCanvas *_t = static_cast<StateCanvas *>(_o);
        switch (_id) {
        case 0: _t->modified(); break;
        case 1: _t->deleted(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData StateCanvas::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject StateCanvas::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_StateCanvas,
      qt_meta_data_StateCanvas, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &StateCanvas::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *StateCanvas::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *StateCanvas::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_StateCanvas))
        return static_cast<void*>(const_cast< StateCanvas*>(this));
    if (!strcmp(_clname, "DiagramCanvas"))
        return static_cast< DiagramCanvas*>(const_cast< StateCanvas*>(this));
    if (!strcmp(_clname, "MultipleDependency<BasicData>"))
        return static_cast< MultipleDependency<BasicData>*>(const_cast< StateCanvas*>(this));
    return QObject::qt_metacast(_clname);
}

int StateCanvas::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE