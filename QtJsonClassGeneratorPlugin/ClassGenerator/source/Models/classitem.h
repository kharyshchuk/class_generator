#ifndef CLASSITEM_H
#define CLASSITEM_H

#include <QString>
#include "classitem.h"
#include "requiredclass.h"
#include "classproperty.h"
#include <QList>

#include <QObject>

class ClassItem : public QObject
{
    Q_OBJECT
public:
    ClassItem();
    ~ClassItem();

    QString getName() const;
    void setName(const QString &value);

    QString getClassName() const;

    //work with required class collections
    bool requiredClasses_add(RequiredClass* rClass);
    bool requiredClasses_insert(int index, RequiredClass* rClass);
    RequiredClass* requiredClasses_get(int index);
    int requiredClasses_count();
    bool requiredClasses_removeAt(int index);
    bool requiredClasses_removeByName(const QString &name);
    bool requiredClasses_clear();

    //work with class properties collections
    bool classProperties_add(ClassProperty* rClass);
    bool classProperties_insert(int index, ClassProperty* rClass);
    ClassProperty* classProperties_get(int index);
    int classProperties_count();
    bool classProperties_removeAt(int index);    
    bool classProperties_clear();

    //work with namespaces
    bool namespaces_add(const QString &nsStr);
    bool namespaces_insert(int index, const QString &nsStr);
    QString namespaces_get(int index) const;
    int namespaces_count();
    bool namespaces_removeAt(int index);
    bool namespaces_clear();

    // work with is generated
    bool getIsGenerated() const;
    void setIsGenerated(bool value);

    // work wit string files .h and .cpp
    std::string getHStream() const;
    void setHStream(const std::string &value);

    std::string getCppStream() const;
    void setCppStream(const std::string &value);

    QString getScriptFilePath() const;
    void setScriptFilePath(const QString &value);

//    QList<QString> getNamespaces() const;
//    void setNamespaces(const QList<QString> &value);

    bool getChangesSaved() const;
    void setChangesSaved(bool value);

    QString getIncludeProjectDirPath() const;
    void setIncludeProjectDirPath(const QString &value);

signals:
    void signalCreateNewTabClassByRequiredFilePath(const QString& filePath);
    bool signalGenerateClass();
    bool signalProxyGenerateClass(int indexCls);

private:
    QString name;
    QString className;
    QString scriptFilePath;
    QString includeProjectDirPath;

    QList<RequiredClass*> requiredClasses;
    QList<ClassProperty*> classProperties;
    QList<QString> namespaces;

    bool changesSaved;
    bool isGenerated;
    std::string hStream;
    std::string cppStream;

    QString transformNameToClassNameGen(const QString& name);
};

#endif // CLASSITEM_H
