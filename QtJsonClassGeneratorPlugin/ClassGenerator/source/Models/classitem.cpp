#include "classitem.h"
#include "requiredclass.h"
#include "classproperty.h"
#include "QString"

ClassItem::ClassItem()
{
    isGenerated = false;
    name = "";
    className = "";
}

ClassItem::~ClassItem()
{
    requiredClasses_clear();
    classProperties_clear();
}

//work with class name
#define FOLDINGSTART {
QString ClassItem::getName() const
{
    return name;
}

void ClassItem::setName(const QString &value)
{
    name = value;
    className = transformNameToClassNameGen(value);
}

QString ClassItem::getClassName() const
{
    return className;
}
#define FOLDINGEND }

//work with required class collections
#define FOLDINGSTART {
bool ClassItem::requiredClasses_add(RequiredClass* rClass)
{
    try {
        requiredClasses.push_back(rClass);
    } catch (std::exception & e)
    {
        throw e;
    }

    return true;
}

bool ClassItem::requiredClasses_insert(int index, RequiredClass* rClass)
{
    try {
        requiredClasses.insert(index, rClass);
    } catch (std::exception & e)
    {
        throw e;
    }
    return true;
}

RequiredClass* ClassItem::requiredClasses_get(int index)
{
    try {
        return requiredClasses.at(index);
    } catch (std::exception & e)
    {
        throw e;
    }
}

int ClassItem::requiredClasses_count()
{
    return requiredClasses.count();
}

bool ClassItem::requiredClasses_removeAt(int index)
{
    delete requiredClasses.at(index);
    requiredClasses.removeAt(index);

    return true;
}

bool ClassItem::requiredClasses_removeByName(const QString &name)
{
    for (int i = 0 ; i < requiredClasses.count() ; i++)
    {
        if (requiredClasses[i]->getName() == name)
        {
            delete requiredClasses.at(i);
            requiredClasses.removeAt(i);
        }
    }

    return true;
}

bool ClassItem::requiredClasses_clear()
{
    for(RequiredClass* ptrRClass : requiredClasses)
    {
        requiredClasses.removeOne(ptrRClass);
        delete ptrRClass; //Freeing memory
    }
    return true;
}
#define FOLDINGEND }

//work with class properties collections
#define FOLDINGSTART {
bool ClassItem::classProperties_add(ClassProperty* classP)
{
    try {
        classProperties.push_back(classP);
    } catch (std::exception & e)
    {
        throw e;
    }

    return true;
}

bool ClassItem::classProperties_insert(int index, ClassProperty* classP)
{
    try {
        classProperties.insert(index, classP);
    } catch (std::exception & e)
    {
        throw e;
    }
    return true;
}

ClassProperty* ClassItem::classProperties_get(int index)
{
    try {
        return classProperties.at(index);
    } catch (std::exception & e)
    {
        throw e;
    }
}

int ClassItem::classProperties_count()
{
    return classProperties.count();
}

bool ClassItem::classProperties_removeAt(int index)
{
    delete classProperties.at(index);
    classProperties.removeAt(index);

    return true;
}

bool ClassItem::classProperties_clear()
{
    for(ClassProperty* ptrClassP : classProperties)
    {
        classProperties.removeOne(ptrClassP);
        delete ptrClassP; //Freeing memory
    }
    return true;
}

#define FOLDINGEND }

std::string ClassItem::getHStream() const
{
    return hStream;
}

void ClassItem::setHStream(const std::string &value)
{
    hStream = value;
}

std::string ClassItem::getCppStream() const
{
    return cppStream;
}

void ClassItem::setCppStream(const std::string &value)
{
    cppStream = value;
}

QString ClassItem::getScriptFilePath() const
{
    return scriptFilePath;
}

void ClassItem::setScriptFilePath(const QString &value)
{
    scriptFilePath = value;
}

bool ClassItem::getChangesSaved() const
{
    return changesSaved;
}

void ClassItem::setChangesSaved(bool value)
{
    changesSaved = value;
}

QString ClassItem::getIncludeProjectDirPath() const
{
    return includeProjectDirPath;
}

void ClassItem::setIncludeProjectDirPath(const QString &value)
{
    includeProjectDirPath = value;
}

//QList<QString> ClassItem::getNamespaces() const
//{
//    return namespaces;
//}

//void ClassItem::setNamespaces(const QList<QString> &value)
//{
//    namespaces = value;
//}



//work with namespaces
#define FOLDINGSTART {
bool ClassItem::namespaces_add(const QString &nsStr)
{
    try {
        namespaces.push_back(nsStr);
    } catch (std::exception & e)
    {
        throw e;
    }

    return true;
}

bool ClassItem::namespaces_insert(int index, const QString &nsStr)
{
    try {
        namespaces.insert(index, nsStr);
    } catch (std::exception & e)
    {
        throw e;
    }
    return true;
}

QString ClassItem::namespaces_get(int index) const
{
    try {
        return namespaces.at(index);
    } catch (std::exception & e)
    {
        throw e;
    }
}

int ClassItem::namespaces_count()
{
    return namespaces.size();
}

bool ClassItem::namespaces_removeAt(int index)
{
//    delete classProperties.at(index);
    namespaces.removeAt(index);

    return true;
}

bool ClassItem::namespaces_clear()
{
    namespaces.clear();
//    for(ClassProperty* ptrClassP : classProperties)
//    {
//        namespaces_clear.removeOne(ptrClassP);
//        delete ptrClassP; //Freeing memory
//    }
    return true;
}
#define FOLDINGEND }

//work with is generated
#define FOLDINGSTART {
bool ClassItem::getIsGenerated() const
{
    return isGenerated;
}

void ClassItem::setIsGenerated(bool value)
{
    isGenerated = value;
}
#define FOLDINGEND }

QString ClassItem::transformNameToClassNameGen(const QString& name)
{
    QString clsName = name;

    clsName[0] = clsName[0].toUpper();

    for(int i = 0; i < clsName.size(); i++)
    {
        if(clsName[i] == ' ')
        {
            clsName = clsName.remove(i, 1);
            clsName[i] = clsName[i].toUpper();
            i--;
        }
    }

    return clsName;
}
