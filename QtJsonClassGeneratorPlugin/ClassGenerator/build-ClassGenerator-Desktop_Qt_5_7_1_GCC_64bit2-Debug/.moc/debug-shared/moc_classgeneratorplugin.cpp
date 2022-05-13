/****************************************************************************
** Meta object code from reading C++ file 'classgeneratorplugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../source/classgeneratorplugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'classgeneratorplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClassGenerator__Internal__ClassGeneratorPlugin_t {
    QByteArrayData data[1];
    char stringdata0[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClassGenerator__Internal__ClassGeneratorPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClassGenerator__Internal__ClassGeneratorPlugin_t qt_meta_stringdata_ClassGenerator__Internal__ClassGeneratorPlugin = {
    {
QT_MOC_LITERAL(0, 0, 46) // "ClassGenerator::Internal::Cla..."

    },
    "ClassGenerator::Internal::ClassGeneratorPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClassGenerator__Internal__ClassGeneratorPlugin[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ClassGenerator::Internal::ClassGeneratorPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ClassGenerator::Internal::ClassGeneratorPlugin::staticMetaObject = {
    { &ExtensionSystem::IPlugin::staticMetaObject, qt_meta_stringdata_ClassGenerator__Internal__ClassGeneratorPlugin.data,
      qt_meta_data_ClassGenerator__Internal__ClassGeneratorPlugin,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClassGenerator::Internal::ClassGeneratorPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClassGenerator::Internal::ClassGeneratorPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClassGenerator__Internal__ClassGeneratorPlugin.stringdata0))
        return static_cast<void*>(const_cast< ClassGeneratorPlugin*>(this));
    return ExtensionSystem::IPlugin::qt_metacast(_clname);
}

int ClassGenerator::Internal::ClassGeneratorPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ExtensionSystem::IPlugin::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}

QT_PLUGIN_METADATA_SECTION const uint qt_section_alignment_dummy = 42;

#ifdef QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    'P',  0x02, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    '<',  0x02, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '!',  0x00, 'o',  'r',  'g',  '.',  'q',  't', 
    '-',  'p',  'r',  'o',  'j',  'e',  'c',  't', 
    '.',  'Q',  't',  '.',  'Q',  't',  'C',  'r', 
    'e',  'a',  't',  'o',  'r',  'P',  'l',  'u', 
    'g',  'i',  'n',  0x00, 0x9b, 0x09, 0x00, 0x00,
    0x09, 0x00, 'c',  'l',  'a',  's',  's',  'N', 
    'a',  'm',  'e',  0x00, 0x14, 0x00, 'C',  'l', 
    'a',  's',  's',  'G',  'e',  'n',  'e',  'r', 
    'a',  't',  'o',  'r',  'P',  'l',  'u',  'g', 
    'i',  'n',  0x00, 0x00, ':',  0xe0, 0xa0, 0x00,
    0x07, 0x00, 'v',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00,
    0x05, 0x00, 'd',  'e',  'b',  'u',  'g',  0x00,
    0x15, 0x12, 0x00, 0x00, 0x08, 0x00, 'M',  'e', 
    't',  'a',  'D',  'a',  't',  'a',  0x00, 0x00,
    0xac, 0x01, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00,
    0x88, 0x01, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x04, 0x00, 'N',  'a',  'm',  'e',  0x00, 0x00,
    0x0e, 0x00, 'C',  'l',  'a',  's',  's',  'G', 
    'e',  'n',  'e',  'r',  'a',  't',  'o',  'r', 
    0x1b, 0x07, 0x00, 0x00, 0x07, 0x00, 'V',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x05, 0x00, '0',  '.',  '0',  '.',  '1',  0x00,
    0x9b, 0x0a, 0x00, 0x00, 0x0d, 0x00, 'C',  'o', 
    'm',  'p',  'a',  't',  'V',  'e',  'r',  's', 
    'i',  'o',  'n',  0x00, 0x05, 0x00, '0',  '.', 
    '0',  '.',  '1',  0x00, 0x1b, 0x0d, 0x00, 0x00,
    0x06, 0x00, 'V',  'e',  'n',  'd',  'o',  'r', 
    0x04, 0x00, 'C',  'P',  'C',  'S',  0x00, 0x00,
    0x1b, 0x10, 0x00, 0x00, 0x09, 0x00, 'C',  'o', 
    'p',  'y',  'r',  'i',  'g',  'h',  't',  0x00,
    0x08, 0x00, '(',  'C',  ')',  ' ',  'C',  'P', 
    'C',  'S',  0x00, 0x00, 0x9b, 0x13, 0x00, 0x00,
    0x07, 0x00, 'L',  'i',  'c',  'e',  'n',  's', 
    'e',  0x00, 0x00, 0x00, '!',  0x00, 'P',  'u', 
    't',  ' ',  'y',  'o',  'u',  'r',  ' ',  'l', 
    'i',  'c',  'e',  'n',  's',  'e',  ' ',  'i', 
    'n',  'f',  'o',  'r',  'm',  'a',  't',  'i', 
    'o',  'n',  ' ',  'h',  'e',  'r',  'e',  0x00,
    0x9b, 0x1a, 0x00, 0x00, 0x0b, 0x00, 'D',  'e', 
    's',  'c',  'r',  'i',  'p',  't',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, '+',  0x00, 'P',  'u', 
    't',  ' ',  'a',  ' ',  's',  'h',  'o',  'r', 
    't',  ' ',  'd',  'e',  's',  'c',  'r',  'i', 
    'p',  't',  'i',  'o',  'n',  ' ',  'o',  'f', 
    ' ',  'y',  'o',  'u',  'r',  ' ',  'p',  'l', 
    'u',  'g',  'i',  'n',  ' ',  'h',  'e',  'r', 
    'e',  0x00, 0x00, 0x00, 0x1b, '"',  0x00, 0x00,
    0x03, 0x00, 'U',  'r',  'l',  0x00, 0x00, 0x00,
    0x0f, 0x00, 'h',  't',  't',  'p',  ':',  '/', 
    '/',  'c',  'p',  'c',  's',  '.',  'w',  's', 
    '/',  0x00, 0x00, 0x00, 0x14, '\'', 0x00, 0x00,
    0x0c, 0x00, 'D',  'e',  'p',  'e',  'n',  'd', 
    'e',  'n',  'c',  'i',  'e',  's',  0x00, 0x00,
    'P',  0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
    'L',  0x00, 0x00, 0x00, '@',  0x00, 0x00, 0x00,
    0x05, 0x00, 0x00, 0x00, '8',  0x00, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 'N',  'a', 
    'm',  'e',  0x00, 0x00, 0x04, 0x00, 'C',  'o', 
    'r',  'e',  0x00, 0x00, 0x1b, 0x06, 0x00, 0x00,
    0x07, 0x00, 'V',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x05, 0x00, '4',  '.', 
    '2',  '.',  '1',  0x00, 0x0c, 0x00, 0x00, 0x00,
    ' ',  0x00, 0x00, 0x00, 0x85, 0x01, 0x00, 0x00,
    '@',  0x00, 0x00, 0x00, 'p',  0x00, 0x00, 0x00,
    '$',  0x01, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00,
    0x8c, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x04, 0x01, 0x00, 0x00, '\\', 0x00, 0x00, 0x00,
    '(',  0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    0x80, 0x00, 0x00, 0x00, '<',  0x00, 0x00, 0x00,
    't',  0x00, 0x00, 0x00, 'd',  0x00, 0x00, 0x00
};

#else // QT_NO_DEBUG

QT_PLUGIN_METADATA_SECTION
static const unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', ' ',
    'q',  'b',  'j',  's',  0x01, 0x00, 0x00, 0x00,
    'P',  0x02, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00,
    '<',  0x02, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x03, 0x00, 'I',  'I',  'D',  0x00, 0x00, 0x00,
    '!',  0x00, 'o',  'r',  'g',  '.',  'q',  't', 
    '-',  'p',  'r',  'o',  'j',  'e',  'c',  't', 
    '.',  'Q',  't',  '.',  'Q',  't',  'C',  'r', 
    'e',  'a',  't',  'o',  'r',  'P',  'l',  'u', 
    'g',  'i',  'n',  0x00, 0x95, 0x09, 0x00, 0x00,
    0x08, 0x00, 'M',  'e',  't',  'a',  'D',  'a', 
    't',  'a',  0x00, 0x00, 0xac, 0x01, 0x00, 0x00,
    0x13, 0x00, 0x00, 0x00, 0x88, 0x01, 0x00, 0x00,
    0x1b, 0x03, 0x00, 0x00, 0x04, 0x00, 'N',  'a', 
    'm',  'e',  0x00, 0x00, 0x0e, 0x00, 'C',  'l', 
    'a',  's',  's',  'G',  'e',  'n',  'e',  'r', 
    'a',  't',  'o',  'r',  0x1b, 0x07, 0x00, 0x00,
    0x07, 0x00, 'V',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x05, 0x00, '0',  '.', 
    '0',  '.',  '1',  0x00, 0x9b, 0x0a, 0x00, 0x00,
    0x0d, 0x00, 'C',  'o',  'm',  'p',  'a',  't', 
    'V',  'e',  'r',  's',  'i',  'o',  'n',  0x00,
    0x05, 0x00, '0',  '.',  '0',  '.',  '1',  0x00,
    0x1b, 0x0d, 0x00, 0x00, 0x06, 0x00, 'V',  'e', 
    'n',  'd',  'o',  'r',  0x04, 0x00, 'C',  'P', 
    'C',  'S',  0x00, 0x00, 0x1b, 0x10, 0x00, 0x00,
    0x09, 0x00, 'C',  'o',  'p',  'y',  'r',  'i', 
    'g',  'h',  't',  0x00, 0x08, 0x00, '(',  'C', 
    ')',  ' ',  'C',  'P',  'C',  'S',  0x00, 0x00,
    0x9b, 0x13, 0x00, 0x00, 0x07, 0x00, 'L',  'i', 
    'c',  'e',  'n',  's',  'e',  0x00, 0x00, 0x00,
    '!',  0x00, 'P',  'u',  't',  ' ',  'y',  'o', 
    'u',  'r',  ' ',  'l',  'i',  'c',  'e',  'n', 
    's',  'e',  ' ',  'i',  'n',  'f',  'o',  'r', 
    'm',  'a',  't',  'i',  'o',  'n',  ' ',  'h', 
    'e',  'r',  'e',  0x00, 0x9b, 0x1a, 0x00, 0x00,
    0x0b, 0x00, 'D',  'e',  's',  'c',  'r',  'i', 
    'p',  't',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    '+',  0x00, 'P',  'u',  't',  ' ',  'a',  ' ', 
    's',  'h',  'o',  'r',  't',  ' ',  'd',  'e', 
    's',  'c',  'r',  'i',  'p',  't',  'i',  'o', 
    'n',  ' ',  'o',  'f',  ' ',  'y',  'o',  'u', 
    'r',  ' ',  'p',  'l',  'u',  'g',  'i',  'n', 
    ' ',  'h',  'e',  'r',  'e',  0x00, 0x00, 0x00,
    0x1b, '"',  0x00, 0x00, 0x03, 0x00, 'U',  'r', 
    'l',  0x00, 0x00, 0x00, 0x0f, 0x00, 'h',  't', 
    't',  'p',  ':',  '/',  '/',  'c',  'p',  'c', 
    's',  '.',  'w',  's',  '/',  0x00, 0x00, 0x00,
    0x14, '\'', 0x00, 0x00, 0x0c, 0x00, 'D',  'e', 
    'p',  'e',  'n',  'd',  'e',  'n',  'c',  'i', 
    'e',  's',  0x00, 0x00, 'P',  0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 'L',  0x00, 0x00, 0x00,
    '@',  0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
    '8',  0x00, 0x00, 0x00, 0x1b, 0x03, 0x00, 0x00,
    0x04, 0x00, 'N',  'a',  'm',  'e',  0x00, 0x00,
    0x04, 0x00, 'C',  'o',  'r',  'e',  0x00, 0x00,
    0x1b, 0x06, 0x00, 0x00, 0x07, 0x00, 'V',  'e', 
    'r',  's',  'i',  'o',  'n',  0x00, 0x00, 0x00,
    0x05, 0x00, '4',  '.',  '2',  '.',  '1',  0x00,
    0x0c, 0x00, 0x00, 0x00, ' ',  0x00, 0x00, 0x00,
    0x85, 0x01, 0x00, 0x00, '@',  0x00, 0x00, 0x00,
    'p',  0x00, 0x00, 0x00, '$',  0x01, 0x00, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0x8c, 0x00, 0x00, 0x00,
    0x0c, 0x00, 0x00, 0x00, 0x04, 0x01, 0x00, 0x00,
    '\\', 0x00, 0x00, 0x00, '(',  0x00, 0x00, 0x00,
    0x1b, 'A',  0x00, 0x00, 0x09, 0x00, 'c',  'l', 
    'a',  's',  's',  'N',  'a',  'm',  'e',  0x00,
    0x14, 0x00, 'C',  'l',  'a',  's',  's',  'G', 
    'e',  'n',  'e',  'r',  'a',  't',  'o',  'r', 
    'P',  'l',  'u',  'g',  'i',  'n',  0x00, 0x00,
    '1',  0x00, 0x00, 0x00, 0x05, 0x00, 'd',  'e', 
    'b',  'u',  'g',  0x00, ':',  0xe0, 0xa0, 0x00,
    0x07, 0x00, 'v',  'e',  'r',  's',  'i',  'o', 
    'n',  0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
    '<',  0x00, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x00,
    ' ',  0x02, 0x00, 0x00, ',',  0x02, 0x00, 0x00
};
#endif // QT_NO_DEBUG

using namespace ClassGenerator;
using namespace ClassGenerator::Internal;
QT_MOC_EXPORT_PLUGIN(ClassGenerator::Internal::ClassGeneratorPlugin, ClassGeneratorPlugin)

QT_END_MOC_NAMESPACE
