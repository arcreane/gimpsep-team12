/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../test2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[418];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 37), // "on_actionDilatation_Erosion_t..."
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 27), // "on_actionLighting_triggered"
QT_MOC_LITERAL(4, 78, 24), // "on_add_picture_triggered"
QT_MOC_LITERAL(5, 103, 31), // "on_show_org_image_page0_clicked"
QT_MOC_LITERAL(6, 135, 28), // "on_Dilatation_button_clicked"
QT_MOC_LITERAL(7, 164, 25), // "on_Erosion_button_clicked"
QT_MOC_LITERAL(8, 190, 31), // "on_show_cha_image_page0_clicked"
QT_MOC_LITERAL(9, 222, 25), // "on_download_page0_clicked"
QT_MOC_LITERAL(10, 248, 26), // "adjustBrightnessFromSlider"
QT_MOC_LITERAL(11, 275, 5), // "value"
QT_MOC_LITERAL(12, 281, 25), // "adjustBrightnessFromInput"
QT_MOC_LITERAL(13, 307, 20), // "onApplyButtonClicked"
QT_MOC_LITERAL(14, 328, 31), // "on_show_org_image_page1_clicked"
QT_MOC_LITERAL(15, 360, 31), // "on_show_cha_image_page1_clicked"
QT_MOC_LITERAL(16, 392, 25) // "on_download_page1_clicked"

    },
    "MainWindow\0on_actionDilatation_Erosion_triggered\0"
    "\0on_actionLighting_triggered\0"
    "on_add_picture_triggered\0"
    "on_show_org_image_page0_clicked\0"
    "on_Dilatation_button_clicked\0"
    "on_Erosion_button_clicked\0"
    "on_show_cha_image_page0_clicked\0"
    "on_download_page0_clicked\0"
    "adjustBrightnessFromSlider\0value\0"
    "adjustBrightnessFromInput\0"
    "onApplyButtonClicked\0"
    "on_show_org_image_page1_clicked\0"
    "on_show_cha_image_page1_clicked\0"
    "on_download_page1_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    1,   92,    2, 0x08 /* Private */,
      12,    1,   95,    2, 0x08 /* Private */,
      13,    0,   98,    2, 0x08 /* Private */,
      14,    0,   99,    2, 0x08 /* Private */,
      15,    0,  100,    2, 0x08 /* Private */,
      16,    0,  101,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void, QMetaType::Int,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionDilatation_Erosion_triggered(); break;
        case 1: _t->on_actionLighting_triggered(); break;
        case 2: _t->on_add_picture_triggered(); break;
        case 3: _t->on_show_org_image_page0_clicked(); break;
        case 4: _t->on_Dilatation_button_clicked(); break;
        case 5: _t->on_Erosion_button_clicked(); break;
        case 6: _t->on_show_cha_image_page0_clicked(); break;
        case 7: _t->on_download_page0_clicked(); break;
        case 8: _t->adjustBrightnessFromSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->adjustBrightnessFromInput((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->onApplyButtonClicked(); break;
        case 11: _t->on_show_org_image_page1_clicked(); break;
        case 12: _t->on_show_cha_image_page1_clicked(); break;
        case 13: _t->on_download_page1_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
