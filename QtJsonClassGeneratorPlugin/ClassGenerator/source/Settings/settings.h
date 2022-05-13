#ifndef SETTINGS_H
#define SETTINGS_H

#include <QString>
#include <QJsonDocument>

class Settings
{
public:
    static QString saveDirectory;

    static bool useUncrustify;
    static QString commandUncrustify;
    static QString pathConfigUncrustify;
    static bool useLightGenerated;
    static bool includeFilesInCurrentProject;

    static QJsonDocument loadJson(QString fileName);
    static void saveJson(QJsonDocument document, QString fileName);
};

#endif // SETTINGS_H
