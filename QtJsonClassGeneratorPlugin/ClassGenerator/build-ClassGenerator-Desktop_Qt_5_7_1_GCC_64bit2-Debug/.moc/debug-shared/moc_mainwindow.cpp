/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/Ui/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[434];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 28), // "signalUploadTabClassFromFile"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 9), // "filePathe"
QT_MOC_LITERAL(4, 51, 23), // "signalSaveTabScriptFile"
QT_MOC_LITERAL(5, 75, 27), // "signalSaveTabHppAndCppFiles"
QT_MOC_LITERAL(6, 103, 25), // "signalSaveTabClassChanges"
QT_MOC_LITERAL(7, 129, 21), // "signalSetTabGenerated"
QT_MOC_LITERAL(8, 151, 5), // "isGen"
QT_MOC_LITERAL(9, 157, 21), // "on_pbSettings_clicked"
QT_MOC_LITERAL(10, 179, 21), // "on_pbAddClass_clicked"
QT_MOC_LITERAL(11, 201, 28), // "on_pbDwnlScriptFiles_clicked"
QT_MOC_LITERAL(12, 230, 31), // "on_pbGenerateAllClasses_clicked"
QT_MOC_LITERAL(13, 262, 30), // "on_pbSaveAllClassFiles_clicked"
QT_MOC_LITERAL(14, 293, 37), // "on_tabWidgetClasses_tabCloseR..."
QT_MOC_LITERAL(15, 331, 5), // "index"
QT_MOC_LITERAL(16, 337, 19), // "slotSetTabClassName"
QT_MOC_LITERAL(17, 357, 8), // "tabIndex"
QT_MOC_LITERAL(18, 366, 12), // "tabClassName"
QT_MOC_LITERAL(19, 379, 18), // "slotCreateTabClass"
QT_MOC_LITERAL(20, 398, 8), // "filePath"
QT_MOC_LITERAL(21, 407, 17), // "slotGenerateClass"
QT_MOC_LITERAL(22, 425, 8) // "indexCls"

    },
    "MainWindow\0signalUploadTabClassFromFile\0"
    "\0filePathe\0signalSaveTabScriptFile\0"
    "signalSaveTabHppAndCppFiles\0"
    "signalSaveTabClassChanges\0"
    "signalSetTabGenerated\0isGen\0"
    "on_pbSettings_clicked\0on_pbAddClass_clicked\0"
    "on_pbDwnlScriptFiles_clicked\0"
    "on_pbGenerateAllClasses_clicked\0"
    "on_pbSaveAllClassFiles_clicked\0"
    "on_tabWidgetClasses_tabCloseRequested\0"
    "index\0slotSetTabClassName\0tabIndex\0"
    "tabClassName\0slotCreateTabClass\0"
    "filePath\0slotGenerateClass\0indexCls"
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
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    0,   87,    2, 0x06 /* Public */,
       5,    0,   88,    2, 0x06 /* Public */,
       6,    0,   89,    2, 0x06 /* Public */,
       7,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   93,    2, 0x08 /* Private */,
      10,    0,   94,    2, 0x08 /* Private */,
      11,    0,   95,    2, 0x08 /* Private */,
      12,    0,   96,    2, 0x08 /* Private */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    1,   98,    2, 0x08 /* Private */,
      16,    2,  101,    2, 0x08 /* Private */,
      19,    1,  106,    2, 0x08 /* Private */,
      21,    1,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   17,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Bool, QMetaType::Int,   22,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalUploadTabClassFromFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->signalSaveTabScriptFile(); break;
        case 2: _t->signalSaveTabHppAndCppFiles(); break;
        case 3: _t->signalSaveTabClassChanges(); break;
        case 4: _t->signalSetTabGenerated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_pbSettings_clicked(); break;
        case 6: _t->on_pbAddClass_clicked(); break;
        case 7: _t->on_pbDwnlScriptFiles_clicked(); break;
        case 8: _t->on_pbGenerateAllClasses_clicked(); break;
        case 9: _t->on_pbSaveAllClassFiles_clicked(); break;
        case 10: _t->on_tabWidgetClasses_tabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->slotSetTabClassName((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 12: _t->slotCreateTabClass((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: { bool _r = _t->slotGenerateClass((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalUploadTabClassFromFile)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalSaveTabScriptFile)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalSaveTabHppAndCppFiles)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalSaveTabClassChanges)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalSetTabGenerated)) {
                *result = 4;
                return;
            }
        }
    }
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

// SIGNAL 0
void MainWindow::signalUploadTabClassFromFile(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signalSaveTabScriptFile()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MainWindow::signalSaveTabHppAndCppFiles()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MainWindow::signalSaveTabClassChanges()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MainWindow::signalSetTabGenerated(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
