/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Interfaz v6/Proyecto/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[383];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "on_pb_pass_clicked"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 19), // "on_pb_alarm_clicked"
QT_MOC_LITERAL(4, 51, 19), // "on_pb_desac_clicked"
QT_MOC_LITERAL(5, 71, 8), // "showtime"
QT_MOC_LITERAL(6, 80, 33), // "on_actionIniciar_Sesi_n_trigg..."
QT_MOC_LITERAL(7, 114, 20), // "on_pb_browse_clicked"
QT_MOC_LITERAL(8, 135, 32), // "on_actionCerrar_Sesi_n_triggered"
QT_MOC_LITERAL(9, 168, 32), // "on_actionNuevo_Usuario_triggered"
QT_MOC_LITERAL(10, 201, 12), // "RecibirTrama"
QT_MOC_LITERAL(11, 214, 25), // "on_button_connect_clicked"
QT_MOC_LITERAL(12, 240, 16), // "onDatosRecibidos"
QT_MOC_LITERAL(13, 257, 31), // "on_button_refresh_ports_clicked"
QT_MOC_LITERAL(14, 289, 20), // "on_pb_enviar_clicked"
QT_MOC_LITERAL(15, 310, 11), // "EnviarTrama"
QT_MOC_LITERAL(16, 322, 12), // "EnviarTrama2"
QT_MOC_LITERAL(17, 335, 12), // "EnviarTrama3"
QT_MOC_LITERAL(18, 348, 12), // "EnviarTrama4"
QT_MOC_LITERAL(19, 361, 21) // "on_pb_setpeso_clicked"

    },
    "MainWindow\0on_pb_pass_clicked\0\0"
    "on_pb_alarm_clicked\0on_pb_desac_clicked\0"
    "showtime\0on_actionIniciar_Sesi_n_triggered\0"
    "on_pb_browse_clicked\0"
    "on_actionCerrar_Sesi_n_triggered\0"
    "on_actionNuevo_Usuario_triggered\0"
    "RecibirTrama\0on_button_connect_clicked\0"
    "onDatosRecibidos\0on_button_refresh_ports_clicked\0"
    "on_pb_enviar_clicked\0EnviarTrama\0"
    "EnviarTrama2\0EnviarTrama3\0EnviarTrama4\0"
    "on_pb_setpeso_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    0,  120,    2, 0x08 /* Private */,
      19,    0,  121,    2, 0x08 /* Private */,

 // slots: parameters
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 0: _t->on_pb_pass_clicked(); break;
        case 1: _t->on_pb_alarm_clicked(); break;
        case 2: _t->on_pb_desac_clicked(); break;
        case 3: _t->showtime(); break;
        case 4: _t->on_actionIniciar_Sesi_n_triggered(); break;
        case 5: _t->on_pb_browse_clicked(); break;
        case 6: _t->on_actionCerrar_Sesi_n_triggered(); break;
        case 7: _t->on_actionNuevo_Usuario_triggered(); break;
        case 8: _t->RecibirTrama(); break;
        case 9: _t->on_button_connect_clicked(); break;
        case 10: _t->onDatosRecibidos(); break;
        case 11: _t->on_button_refresh_ports_clicked(); break;
        case 12: _t->on_pb_enviar_clicked(); break;
        case 13: _t->EnviarTrama(); break;
        case 14: _t->EnviarTrama2(); break;
        case 15: _t->EnviarTrama3(); break;
        case 16: _t->EnviarTrama4(); break;
        case 17: _t->on_pb_setpeso_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
