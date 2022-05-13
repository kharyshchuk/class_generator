#ifndef QTJSONCLASSGENERATOR_H
#define QTJSONCLASSGENERATOR_H

#include "qtjsonclassgenerator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <experimental/filesystem>
#include <list>
#include <map>
#include <QMap>
#include "../Settings/settings.h"

#include <QtGlobal>
#include "../Models/classitem.h"
#include <QWidget>

class QtJsonClassGenerator
{

public:
    static bool compile(QVector<ClassItem*>* &classItems, int clsItemIndex);
    static std::map<std::string, std::string> _supported_types;
    static QMap<QString, QString> supported_types;

};

#endif // QTJSONCLASSGENERATOR_H
