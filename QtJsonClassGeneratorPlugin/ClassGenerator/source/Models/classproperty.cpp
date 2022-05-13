#include "classproperty.h"

ClassProperty::ClassProperty()
{

}

//work with class name
#define FOLDINGSTART {
QString ClassProperty::getName() const
{
    return name;
}

void ClassProperty::setName(const QString &value)
{
    name = value;
}
#define FOLDINGEND }

//work with type
#define FOLDINGSTART {
QString ClassProperty::getType() const
{
    return type;
}

void ClassProperty::setType(const QString &value)
{
    type = value;
}
#define FOLDINGEND }

//work with is collection
#define FOLDINGSTART {
bool ClassProperty::getIsCollection() const
{
    return isCollection;
}

void ClassProperty::setIsCollection(bool value)
{
    isCollection = value;
}
#define FOLDINGEND }
