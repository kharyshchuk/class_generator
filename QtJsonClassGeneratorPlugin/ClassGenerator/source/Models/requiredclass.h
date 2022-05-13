#ifndef REQUIREDCLASS_H
#define REQUIREDCLASS_H

#include <QString>

class RequiredClass
{
public:
    RequiredClass();

    QString getName() const;
    void setName(const QString &value);

    QString getFileName() const;
    void setFileName(const QString &value);

    QString getClassnameForGen() const;

    QString getAbsoluteFilePath() const;
    void setAbsoluteFilePath(const QString &value);

private:
    QString name;
    QString fileName;
    QString absoluteFilePath;
    QString classnameForGen;
    QString transformFileNametoName(const QString& fName);
    QString transformNameToClassNameGen(const QString& name);
};

#endif // REQUIREDCLASS_H
