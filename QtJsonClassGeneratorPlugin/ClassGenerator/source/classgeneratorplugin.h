#pragma once

#include "classgenerator_global.h"

#include <extensionsystem/iplugin.h>
#include "Ui/mainwindow.h"

namespace ClassGenerator {
namespace Internal {

class ClassGeneratorPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "ClassGenerator.json")

public:
    ClassGeneratorPlugin();
    ~ClassGeneratorPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();
private slots:
    void slotIncludeFilesInProject(const QVector<ClassItem*> &classImets);

private:
    MainWindow *w;
    void triggerAction();
};

} // namespace Internal
} // namespace ClassGenerator
