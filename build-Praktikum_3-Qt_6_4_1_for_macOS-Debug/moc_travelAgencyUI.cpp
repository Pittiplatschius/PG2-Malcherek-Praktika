/****************************************************************************
** Meta object code from reading C++ file 'travelAgencyUI.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Praktikum_3/travelAgencyUI.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'travelAgencyUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.1. It"
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
struct qt_meta_stringdata_TravelAgencyUI_t {
    uint offsetsAndSizes[22];
    char stringdata0[15];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[25];
    char stringdata5[23];
    char stringdata6[27];
    char stringdata7[23];
    char stringdata8[24];
    char stringdata9[12];
    char stringdata10[3];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_TravelAgencyUI_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_TravelAgencyUI_t qt_meta_stringdata_TravelAgencyUI = {
    {
        QT_MOC_LITERAL(0, 14),  // "TravelAgencyUI"
        QT_MOC_LITERAL(15, 19),  // "pushButton_Einlesen"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 24),  // "pushButton_Alle_anzeigen"
        QT_MOC_LITERAL(61, 24),  // "pushButton_BuchungSuchen"
        QT_MOC_LITERAL(86, 22),  // "pushBotton_Exportieren"
        QT_MOC_LITERAL(109, 26),  // "pushButton_Liste_sortieren"
        QT_MOC_LITERAL(136, 22),  // "pushButton_KundeSuchen"
        QT_MOC_LITERAL(159, 23),  // "doubleClickedListWidget"
        QT_MOC_LITERAL(183, 11),  // "listDetails"
        QT_MOC_LITERAL(195, 2)   // "id"
    },
    "TravelAgencyUI",
    "pushButton_Einlesen",
    "",
    "pushButton_Alle_anzeigen",
    "pushButton_BuchungSuchen",
    "pushBotton_Exportieren",
    "pushButton_Liste_sortieren",
    "pushButton_KundeSuchen",
    "doubleClickedListWidget",
    "listDetails",
    "id"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_TravelAgencyUI[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x108,    7 /* Private | MethodIsConst  */,
       9,    1,   69,    2, 0x108,    8 /* Private | MethodIsConst  */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,

       0        // eod
};

Q_CONSTINIT const QMetaObject TravelAgencyUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TravelAgencyUI.offsetsAndSizes,
    qt_meta_data_TravelAgencyUI,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_TravelAgencyUI_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TravelAgencyUI, std::true_type>,
        // method 'pushButton_Einlesen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushButton_Alle_anzeigen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushButton_BuchungSuchen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushBotton_Exportieren'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushButton_Liste_sortieren'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushButton_KundeSuchen'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'doubleClickedListWidget'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'listDetails'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>
    >,
    nullptr
} };

void TravelAgencyUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TravelAgencyUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->pushButton_Einlesen(); break;
        case 1: _t->pushButton_Alle_anzeigen(); break;
        case 2: _t->pushButton_BuchungSuchen(); break;
        case 3: _t->pushBotton_Exportieren(); break;
        case 4: _t->pushButton_Liste_sortieren(); break;
        case 5: _t->pushButton_KundeSuchen(); break;
        case 6: _t->doubleClickedListWidget(); break;
        case 7: _t->listDetails((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *TravelAgencyUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TravelAgencyUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TravelAgencyUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TravelAgencyUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
