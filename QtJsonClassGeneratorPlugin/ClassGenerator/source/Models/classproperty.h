#ifndef CLASSPROPERTY_H
#define CLASSPROPERTY_H

#include <QString>
#include <map>

class ClassProperty
{
public:
    ClassProperty();

    QString getName() const;
    void setName(const QString &value);

    QString getType() const;
    void setType(const QString &value);

    bool getIsCollection() const;
    void setIsCollection(bool value);

private:
    QString name;
    QString type;
    bool isCollection;
};

#endif // CLASSPROPERTY_H
