#include "settings.h"
#include <QJsonDocument>
#include <QFile>
#include <QString>


QString Settings::saveDirectory;

bool Settings::useUncrustify;
QString Settings::commandUncrustify;
QString Settings::pathConfigUncrustify;
bool Settings::useLightGenerated;
bool Settings::includeFilesInCurrentProject;

QJsonDocument Settings::loadJson(QString fileName)
{
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}

void Settings::saveJson(QJsonDocument document, QString fileName)
{
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly);
    jsonFile.write(document.toJson());
}
