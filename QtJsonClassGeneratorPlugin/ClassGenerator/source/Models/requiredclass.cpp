#include "requiredclass.h"

RequiredClass::RequiredClass() {
    name            = "";
    classnameForGen = "";
    fileName        = "";
}

//work with class name
#define FOLDINGSTART    {
QString RequiredClass::getName() const {
    return(name);
}

void RequiredClass::setName(const QString &value) {
    name            = value;
    classnameForGen = transformNameToClassNameGen(name);
//    fileName        = classnameForGen + ".jcd";
}

#define FOLDINGEND      }

//work with file name
#define FOLDINGSTART    {
QString RequiredClass::getFileName() const {
    return(fileName);
}

QString RequiredClass::getClassnameForGen() const {
    return(classnameForGen);
}

QString RequiredClass::getAbsoluteFilePath() const
{
    return absoluteFilePath;
}

void RequiredClass::setAbsoluteFilePath(const QString &value)
{
    absoluteFilePath = value;
}

void RequiredClass::setFileName(const QString &value) {
    fileName        = value;
    name            = transformFileNametoName(value);
    classnameForGen = transformNameToClassNameGen(name);
}

#define FOLDINGEND    }

QString RequiredClass::transformFileNametoName(const QString &fName) {
    QString path;

    int lastPoint = fName.lastIndexOf("/");
    path = fName.right(fName.size() - lastPoint - 1);

    lastPoint = path.lastIndexOf(".");
    path = path.left(lastPoint);

    for (int i = 0; i < path.size(); i++) {
        if (path[i].isUpper()) {
            path[i] = path[i].toLower();
            if (i > 0) {
                path.insert(i, " ");
                i++;
            }
        }
    }

    return(path);
}

QString RequiredClass::transformNameToClassNameGen(const QString &name) {
    QString className = name;

    className[0] = className[0].toUpper();

    for (int i = 0; i < className.size(); i++) {
        if (className[i] == ' ') {
            className.remove(i, 1);
            className[i] = className[i].toUpper();
            i--;
        }
    }

    return(className);
}
