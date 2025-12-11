/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qt-simple-calculator/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[314];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 19), // "numberGroup_clicked"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 16), // "QAbstractButton*"
QT_MOC_LITERAL(4, 49, 19), // "actionGroup_clicked"
QT_MOC_LITERAL(5, 69, 20), // "on_actionDel_clicked"
QT_MOC_LITERAL(6, 90, 21), // "on_actionCalc_clicked"
QT_MOC_LITERAL(7, 112, 16), // "on_comma_clicked"
QT_MOC_LITERAL(8, 129, 22), // "on_actionClear_clicked"
QT_MOC_LITERAL(9, 152, 24), // "on_actionPercent_clicked"
QT_MOC_LITERAL(10, 177, 21), // "on_actionSign_clicked"
QT_MOC_LITERAL(11, 199, 15), // "on_save_clicked"
QT_MOC_LITERAL(12, 215, 15), // "on_show_clicked"
QT_MOC_LITERAL(13, 231, 15), // "on_hide_clicked"
QT_MOC_LITERAL(14, 247, 16), // "on_about_clicked"
QT_MOC_LITERAL(15, 264, 16), // "on_clear_clicked"
QT_MOC_LITERAL(16, 281, 15), // "on_item_clicked"
QT_MOC_LITERAL(17, 297, 16) // "QListWidgetItem*"

    },
    "MainWindow\0numberGroup_clicked\0\0"
    "QAbstractButton*\0actionGroup_clicked\0"
    "on_actionDel_clicked\0on_actionCalc_clicked\0"
    "on_comma_clicked\0on_actionClear_clicked\0"
    "on_actionPercent_clicked\0on_actionSign_clicked\0"
    "on_save_clicked\0on_show_clicked\0"
    "on_hide_clicked\0on_about_clicked\0"
    "on_clear_clicked\0on_item_clicked\0"
    "QListWidgetItem*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x08 /* Private */,
       4,    1,   87,    2, 0x08 /* Private */,
       5,    0,   90,    2, 0x08 /* Private */,
       6,    0,   91,    2, 0x08 /* Private */,
       7,    0,   92,    2, 0x08 /* Private */,
       8,    0,   93,    2, 0x08 /* Private */,
       9,    0,   94,    2, 0x08 /* Private */,
      10,    0,   95,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x08 /* Private */,
      12,    0,   97,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    1,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 17,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->numberGroup_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 1: _t->actionGroup_clicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 2: _t->on_actionDel_clicked(); break;
        case 3: _t->on_actionCalc_clicked(); break;
        case 4: _t->on_comma_clicked(); break;
        case 5: _t->on_actionClear_clicked(); break;
        case 6: _t->on_actionPercent_clicked(); break;
        case 7: _t->on_actionSign_clicked(); break;
        case 8: _t->on_save_clicked(); break;
        case 9: _t->on_show_clicked(); break;
        case 10: _t->on_hide_clicked(); break;
        case 11: _t->on_about_clicked(); break;
        case 12: _t->on_clear_clicked(); break;
        case 13: _t->on_item_clicked((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
