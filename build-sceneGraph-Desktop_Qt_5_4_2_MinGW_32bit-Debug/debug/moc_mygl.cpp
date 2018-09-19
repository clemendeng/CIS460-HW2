/****************************************************************************
** Meta object code from reading C++ file 'mygl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../assignment_package/src/mygl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyGL_t {
    QByteArrayData data[19];
    char stringdata[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGL_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGL_t qt_meta_stringdata_MyGL = {
    {
QT_MOC_LITERAL(0, 0, 4), // "MyGL"
QT_MOC_LITERAL(1, 5, 8), // "sendRoot"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 32, 1), // "r"
QT_MOC_LITERAL(5, 34, 16), // "slot_currentNode"
QT_MOC_LITERAL(6, 51, 4), // "curr"
QT_MOC_LITERAL(7, 56, 11), // "slot_rotate"
QT_MOC_LITERAL(8, 68, 3), // "deg"
QT_MOC_LITERAL(9, 72, 16), // "slot_translate_x"
QT_MOC_LITERAL(10, 89, 1), // "x"
QT_MOC_LITERAL(11, 91, 16), // "slot_translate_y"
QT_MOC_LITERAL(12, 108, 1), // "y"
QT_MOC_LITERAL(13, 110, 12), // "slot_scale_x"
QT_MOC_LITERAL(14, 123, 12), // "slot_scale_y"
QT_MOC_LITERAL(15, 136, 14), // "slot_addSquare"
QT_MOC_LITERAL(16, 151, 14), // "slot_addRotate"
QT_MOC_LITERAL(17, 166, 13), // "slot_addScale"
QT_MOC_LITERAL(18, 180, 17) // "slot_addTranslate"

    },
    "MyGL\0sendRoot\0\0QTreeWidgetItem*\0r\0"
    "slot_currentNode\0curr\0slot_rotate\0deg\0"
    "slot_translate_x\0x\0slot_translate_y\0"
    "y\0slot_scale_x\0slot_scale_y\0slot_addSquare\0"
    "slot_addRotate\0slot_addScale\0"
    "slot_addTranslate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   72,    2, 0x0a /* Public */,
       7,    1,   75,    2, 0x0a /* Public */,
       9,    1,   78,    2, 0x0a /* Public */,
      11,    1,   81,    2, 0x0a /* Public */,
      13,    1,   84,    2, 0x0a /* Public */,
      14,    1,   87,    2, 0x0a /* Public */,
      15,    0,   90,    2, 0x0a /* Public */,
      16,    0,   91,    2, 0x0a /* Public */,
      17,    0,   92,    2, 0x0a /* Public */,
      18,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGL *_t = static_cast<MyGL *>(_o);
        switch (_id) {
        case 0: _t->sendRoot((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->slot_currentNode((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->slot_rotate((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->slot_translate_x((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->slot_translate_y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->slot_scale_x((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->slot_scale_y((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->slot_addSquare(); break;
        case 8: _t->slot_addRotate(); break;
        case 9: _t->slot_addScale(); break;
        case 10: _t->slot_addTranslate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGL::*_t)(QTreeWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sendRoot)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MyGL::staticMetaObject = {
    { &OpenGLContext::staticMetaObject, qt_meta_stringdata_MyGL.data,
      qt_meta_data_MyGL,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGL::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyGL.stringdata))
        return static_cast<void*>(const_cast< MyGL*>(this));
    return OpenGLContext::qt_metacast(_clname);
}

int MyGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = OpenGLContext::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MyGL::sendRoot(QTreeWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
