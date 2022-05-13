#include "classgeneratorplugin.h"
#include "classgeneratorconstants.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>
#include "Ui/mainwindow.h"
#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/projecttree.h>
#include <projectexplorer/projectnodes.h>
#include <projectexplorer/project.h>
//#include <QDir>
//#include <projectexplorer/project.h>

//#include <QApplication>
using namespace ProjectExplorer;

namespace ClassGenerator {
namespace Internal {

ClassGeneratorPlugin::ClassGeneratorPlugin()
{
    // Create your members
}

ClassGeneratorPlugin::~ClassGeneratorPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool ClassGeneratorPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.
    w = NULL;

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    QAction *action = new QAction(tr("Open"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                             Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
    connect(action, &QAction::triggered, this, &ClassGeneratorPlugin::triggerAction);

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("ClassGenerator"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    return true;
}

void ClassGeneratorPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag ClassGeneratorPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    delete w;

    return SynchronousShutdown;
}

void ClassGeneratorPlugin::slotIncludeFilesInProject(const QVector<ClassItem*> &classItems)
{
    Project *proj = ProjectTree::currentProject();

    //myString.count(QLatin1Char('#'));
    //    FolderNode *folderNode = node ? node->asFolderNode() : nullptr;
    //    if (!folderNode) // can happen when project is not yet parsed
    //        folderNode = node->parentFolderNode();
    if (proj != nullptr)
    {

//        int arr[classItems.size()];

//        for (int i = 0; i < classItems.size(); i++)
//        {
//            arr[i] = classItems.at(i)->getScriptFilePath().count(QLatin1Char('/'));
//        }

//        int small = arr[0];
//        int smalInd = 0;
//        for(int i = 0; i < classItems.size(); i++)
//        {
//            if(arr[i] < small)
//            {
//                small = arr[i];
//                smalInd = i;
//            }
//        }

        QVector<QStringList> splittedPathes;

        for (int i = 0; i < classItems.size(); i++)
        {
            QString path = classItems.at(i)->getScriptFilePath();
            QStringList strList = path.split("/");
            splittedPathes.push_back(strList);
        }

        while(true)
        {
            bool removePart = true;
            for (int i = 1; i < splittedPathes.size(); i++)
            {
                if(splittedPathes.at(0).at(0) != splittedPathes.at(i).at(0))
                {
                    removePart = false;
                    break;
                }
            }

            if(removePart)
            {
                for (int i = 0; i < splittedPathes.size(); i++)
                {
                    QStringList slist = splittedPathes.at(i);
                    slist.removeFirst();
                    splittedPathes.removeAt(i);
                    splittedPathes.insert(i, slist);
                }
            }
            else
            {
                break;
            }
        }

        QString projDirPath = ProjectExplorer::ProjectTree::currentProject()->projectDirectory().toString();

        QStringList filePathes;
        for (int i = 0; i < splittedPathes.size(); i++)
        {
            filePathes.push_back(projDirPath + "/" + splittedPathes.at(i).join("/"));
        }

        ProjectNode *folderNode = proj->rootProjectNode();

        //        QFileInfo fi(classItems.at(smalInd)->getScriptFilePath());
        //        QFile someFIle

        //        QDir dir(fi.dir().absolutePath());

        //        QString LFName = dir.relativeFilePath(classItems.at(1)->getScriptFilePath());



        //        projDirPath.split("/"
        //        QFileInfo fiProj(proj->projectDirectory().fileName());
        //        QFile someFIle
        //        QString projDirPath = proj->projectFilePath();

        //        QFileInfo fiProj(projDirPath + "/" + LFName);
        //        QDir dirNewFile(fiProj.dir().absolutePath());
        //        QDir dirCreate = QDir::root();
        //        dirCreate.mkpath(dirNewFile.absolutePath());

        // create hierarchy directores
//        QString rootPath = clsItem->getIncludeProjectDirPath() + "/";
        QStringList includeFilePathes;

        for (int i = 0; i < filePathes.size(); i++)
        {
            ClassItem *clsItem = classItems.at(i);

            QFileInfo newFile(filePathes.at(i));
            QDir dirNewFile(newFile.dir().absolutePath());
            QDir dirCreate = QDir::root();
            dirCreate.mkpath(dirNewFile.absolutePath());

            clsItem->setIncludeProjectDirPath(dirNewFile.absolutePath());
            QString rootPath = clsItem->getIncludeProjectDirPath() + "/";

            QString hFilePath = rootPath + clsItem->getClassName() + ".h";
            std::ofstream fileHpp(hFilePath.toStdString());
            fileHpp << clsItem->getHStream();

            includeFilePathes.push_back(hFilePath);

            QString cppFilePath = rootPath + clsItem->getClassName() + ".cpp";
            std::ofstream fileCpp(cppFilePath.toStdString());
            fileCpp << clsItem->getCppStream();

            includeFilePathes.push_back(cppFilePath);
        }



        //        dirCreate.mkdir("/home/osboxes/Projects/NewCatalog/Catalog2");

        //    classItems.at(0)->getScriptFilePath();

        //        // TODO check on correct node (include hierarchy not only root project directory
        //        QStringList filePathes;

        //        filePathes.push_back("/home/osboxes/SriptClassesExample/testSettingsFolder/Family.h");
        //        filePathes.push_back("/home/osboxes/SriptClassesExample/testSettingsFolder/Family.cpp");

        //        //    QString path("/home/osboxes/ExampleClassScripts/testSettingsFolder1/");
        //        //    QDir dir = QDir::root();
        //        //    dir.mkdir(path);

        //        //    QFile::copy("/home/osboxes/ExampleClassScripts/testSettingsFolder/Effect.h", "/home/osboxes/ExampleClassScripts/testSettingsFolder1/Effect.h");

        ProjectExplorerPlugin::addExistingFiles(folderNode, includeFilePathes);
    }
}

void ClassGeneratorPlugin::triggerAction()
{
    //    QMessageBox::information(Core::ICore::mainWindow(),
    //                             tr("Action Triggered"),
    //                             tr("This is an action from ClassGenerator."));

    if(w)
    {
        w->activateWindow();
        return;
    }

    w = new MainWindow();
    connect(w, SIGNAL(signalIncludeFilesInProject(const QVector<ClassItem*>&)), this, SLOT(slotIncludeFilesInProject(const QVector<ClassItem*>&)));
    w->show();

    //    SettingsDialog *setingDial = new SettingsDialog();
    ////    setingDial->setWindowModality(Qt::ApplicationModal);
    //    setingDial->show();
}

} // namespace Internal
} // namespace ClassGenerator
