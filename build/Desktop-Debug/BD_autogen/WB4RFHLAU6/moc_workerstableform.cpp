/****************************************************************************
** Meta object code from reading C++ file 'workerstableform.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../View/workerstableform.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'workerstableform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_WorkersTableForm_t {
    uint offsetsAndSizes[26];
    char stringdata0[17];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[17];
    char stringdata5[12];
    char stringdata6[8];
    char stringdata7[9];
    char stringdata8[24];
    char stringdata9[23];
    char stringdata10[28];
    char stringdata11[15];
    char stringdata12[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_WorkersTableForm_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_WorkersTableForm_t qt_meta_stringdata_WorkersTableForm = {
    {
        QT_MOC_LITERAL(0, 16),  // "WorkersTableForm"
        QT_MOC_LITERAL(17, 23),  // "on_AddRowButton_clicked"
        QT_MOC_LITERAL(41, 0),  // ""
        QT_MOC_LITERAL(42, 26),  // "on_DeleteRowButton_clicked"
        QT_MOC_LITERAL(69, 16),  // "updateDetailView"
        QT_MOC_LITERAL(86, 11),  // "QModelIndex"
        QT_MOC_LITERAL(98, 7),  // "current"
        QT_MOC_LITERAL(106, 8),  // "previous"
        QT_MOC_LITERAL(115, 23),  // "on_SearchButton_clicked"
        QT_MOC_LITERAL(139, 22),  // "on_ResetButton_clicked"
        QT_MOC_LITERAL(162, 27),  // "on_ChangePostButton_clicked"
        QT_MOC_LITERAL(190, 14),  // "onPostSelected"
        QT_MOC_LITERAL(205, 6)   // "postId"
    },
    "WorkersTableForm",
    "on_AddRowButton_clicked",
    "",
    "on_DeleteRowButton_clicked",
    "updateDetailView",
    "QModelIndex",
    "current",
    "previous",
    "on_SearchButton_clicked",
    "on_ResetButton_clicked",
    "on_ChangePostButton_clicked",
    "onPostSelected",
    "postId"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_WorkersTableForm[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    2,   58,    2, 0x08,    3 /* Private */,
       8,    0,   63,    2, 0x08,    6 /* Private */,
       9,    0,   64,    2, 0x08,    7 /* Private */,
      10,    0,   65,    2, 0x08,    8 /* Private */,
      11,    1,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

Q_CONSTINIT const QMetaObject WorkersTableForm::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WorkersTableForm.offsetsAndSizes,
    qt_meta_data_WorkersTableForm,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_WorkersTableForm_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<WorkersTableForm, std::true_type>,
        // method 'on_AddRowButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_DeleteRowButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateDetailView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_SearchButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ResetButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ChangePostButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPostSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void WorkersTableForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WorkersTableForm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_AddRowButton_clicked(); break;
        case 1: _t->on_DeleteRowButton_clicked(); break;
        case 2: _t->updateDetailView((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[2]))); break;
        case 3: _t->on_SearchButton_clicked(); break;
        case 4: _t->on_ResetButton_clicked(); break;
        case 5: _t->on_ChangePostButton_clicked(); break;
        case 6: _t->onPostSelected((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *WorkersTableForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WorkersTableForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WorkersTableForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WorkersTableForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
