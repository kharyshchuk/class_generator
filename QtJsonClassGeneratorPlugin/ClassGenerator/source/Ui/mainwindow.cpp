#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tabclasslayout.h"
#include "memory"
#include "QFileDialog"
#include <QTimer>
#include "../Models/classitem.h"
#include <QDebug>
#include "settingsdialog.h"
#include "../Settings/settings.h"
#include "QJsonObject"
#include "QJsonDocument"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label->setVisible(false);

    //Load settings
    QJsonDocument document = Settings::loadJson("ClassGenSettings.jsn");
    QJsonObject jo = document.object();
    QJsonValue value = jo.value("savedirectory");
    Settings::saveDirectory = value.toString();

    value = jo.value("useuncrustify");
    Settings::useUncrustify = value.toBool();

    value = jo.value("commanduncrustify");
    Settings::commandUncrustify = value.toString();

    value = jo.value("pathconfiguncrustify");
    Settings::pathConfigUncrustify = value.toString();

    value = jo.value("uselightgenerated");
    Settings::useLightGenerated = value.toBool();

    value = jo.value("includefilesincurrentproject");
    Settings::includeFilesInCurrentProject = value.toBool();

    connect(ui->tabWidgetClasses->tabBar(), SIGNAL(tabMoved(int, int)), this, SLOT(slotRelabelTabs(int, int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// slot
void MainWindow::on_pbSettings_clicked()
{
    SettingsDialog *setingDial = new SettingsDialog(this);
    setingDial->setWindowModality(Qt::ApplicationModal);
    setingDial->show();
}

// slot
void MainWindow::on_pbAddClass_clicked()
{
    MainWindow::createTabPageClass();
    ui->pbGenerateAllClasses->setEnabled(true);
    ui->pbSaveAllClassFiles->setEnabled(true);
}

void MainWindow::slotCreateTabClass(const QString &filePath)
{
    MainWindow::createTabPageClass(filePath);
    ui->pbGenerateAllClasses->setEnabled(true);
    ui->pbSaveAllClassFiles->setEnabled(true);
}

void MainWindow::createTabPageClass(const QString &filePath)
{
    TabClassLayout *curTbl = new TabClassLayout(this);
    curTbl->setMyIndex(ui->tabWidgetClasses->count());

    tblArr.push_back(curTbl);

    ClassItem *clsItem = curTbl->getMyClassItem();
    clsItem->setScriptFilePath(filePath);
    classItems.push_back(clsItem);

    curTbl->setClassItems(&classItems);

    // signals -> slots
    connect(clsItem, SIGNAL(signalProxyGenerateClass(int)), this, SLOT(slotProxyGenerateClass(int)));
    connect(this, SIGNAL(signalFillModelFromFormElements()), curTbl, SLOT(slotFillModelFromFormElements()));
    connect(this, SIGNAL(signalUpdateDataClasses()), curTbl, SLOT(slotUpdateDataClasses()));

    connect(clsItem, SIGNAL(signalCreateNewTabClassByRequiredFilePath(const QString&)), this, SLOT(slotCreateTabClass(const QString&)));
    //
    connect(curTbl, SIGNAL(signalSetTabClassName(int,const QString&)), SLOT(slotSetTabClassName(int ,const QString&)));
    connect(curTbl, SIGNAL(signalSetCurrentTabPage(const QString&)), SLOT(slotSetCurrentTabPage(const QString&)));

    connect(this, SIGNAL(signalSaveTabScriptFile()), curTbl, SLOT(slotSaveScriptFile()));
    connect(this, SIGNAL(signalSaveTabHppAndCppFiles()), curTbl, SLOT(slotSaveHppAndCppFiles()));

    ui->tabWidgetClasses->addTab(curTbl, "");
    ui->tabWidgetClasses->setCurrentIndex(ui->tabWidgetClasses->count() - 1);

    //TODO may be bad practice
    if (!filePath.isEmpty())
    {
        connect(this, SIGNAL(signalUploadTabClassFromFile(const QString&)), curTbl, SLOT(slotUploadClassFromFile(const QString&)));
        emit signalUploadTabClassFromFile(filePath);
        disconnect(this, SIGNAL(signalUploadTabClassFromFile(const QString&)), curTbl, SLOT(slotUploadClassFromFile(const QString&)));
    }
}

// slot
void MainWindow::on_pbDwnlScriptFiles_clicked()
{
    QStringList file_path_list = QFileDialog::getOpenFileNames(this, "Select sript files", QDir::homePath(), "*.jcd");

    if (file_path_list.count() == 0)
        return;

    for(auto& filePath : file_path_list)
    {
        MainWindow::createTabPageClass(filePath);
    }
    ui->pbGenerateAllClasses->setEnabled(true);
    ui->pbSaveAllClassFiles->setEnabled(true);
}

// slot
bool MainWindow::slotProxyGenerateClass(int indexCls)
{
    tblArr[indexCls]->generateClass();

    //    connect(this, SIGNAL(signalFillModelFromFormElements()), tblArr[indexCls], SLOT(slotFillModelFromFormElements()));
    //    emit signalFillModelFromFormElements();
    //    disconnect(this, SIGNAL(signalFillModelFromFormElements()), tblArr[indexCls], SLOT(slotFillModelFromFormElements()));

    return classItems[indexCls]->getIsGenerated();
}

// slot
void MainWindow::on_pbGenerateAllClasses_clicked()
{
    emit signalFillModelFromFormElements();

    for (int i = 0; i < classItems.count(); i++)
    {
        slotProxyGenerateClass(i);

        if (!classItems[i]->getIsGenerated())
            break;
    }
}

// slot
//bool MainWindow::slotGenerateClass(int indexCls)
//{
//    ClassItem *clsItem = classItems.at(indexCls);



//    if (!clsItem->getChangesSaved())
//    {
//        return false;
//    }

//    bool resGen = QtJsonClassGenerator::compile(classItems, indexCls);

//    // clear fake required classes
//    // TODO optimize this, may be architecture
//    if (resGen)
//    {
//        for (int i = 0 ; i < clsItem->requiredClasses_count() ; i++)
//        {
//            bool exist = false;
//            QString rName = clsItem->requiredClasses_get(i)->getName();

//            int j;
//            for (j = 0 ; j < classItems.count() ; j++)
//            {
//                if (rName == classItems[j]->getName())
//                {
//                    exist = true;
//                    break;
//                }
//            }

//            j--;

//            if (!exist)
//            {
//                resGen = false;

////                clsItem->requiredClasses_removeAt(i);
////                i--;

////                connect(this, SIGNAL(signalFillFormElementsFromModel()), tblArr[indexCls], SLOT(slotFillFormElementsFromModel()));
////                emit signalFillFormElementsFromModel();
////                disconnect(this, SIGNAL(signalFillFormElementsFromModel()), tblArr[indexCls], SLOT(slotFillFormElementsFromModel()));
//            }
//        }
//    }

//    connect(this, SIGNAL(signalSetTabGenerated(bool)), tblArr[indexCls], SLOT(slotSetGenerated(bool)));
//    emit signalSetTabGenerated(resGen);
//    disconnect(this, SIGNAL(signalSetTabGenerated(bool)), tblArr[indexCls], SLOT(slotSetGenerated(bool)));

//    return true;
//}

// slot
void MainWindow::on_pbSaveAllClassFiles_clicked()
{
    bool existIsGen = false;
    for (int i = 0; i < classItems.count(); i++)
    {
        ClassItem *clsItem = classItems.at(i);
        if (clsItem->getIsGenerated() == true)
        {
            existIsGen = true;
            break;
        }
    }

    if (!existIsGen)
    {
        ui->label->setText("<font color='red'>Not generated classes!</font>");
        ui->label->setVisible(true);
        QTimer::singleShot(2000,ui->label,SLOT(hide()));

        return;
    }

    // save script file
    emit signalSaveTabScriptFile();

    // include in project
    includeFilesInProject();

    // save .h and .cpp files
    emit signalSaveTabHppAndCppFiles();

//    // fill required class pathes
//    emit signalUpdateDataClasses();

    ui->label->setText("<font color='green'>Generated class files saved!</font>");
    ui->label->setVisible(true);
    QTimer::singleShot(2000,ui->label,SLOT(hide()));

}

void MainWindow::includeFilesInProject()
{
//    QStringList filePathes;

    emit signalIncludeFilesInProject(classItems);
}

// slot
void MainWindow::slotSetCurrentTabPage(const QString& className)
{
    // set current tab

    for (int i = 0 ; i < tblArr.size() ; i++)
    {
        if (ui->tabWidgetClasses->tabText(i) == className)
        {
            ui->tabWidgetClasses->setCurrentIndex(i);
            break;
        }
    }

    //    ui->tabWidgetClasses->setCurrentIndex(tabIndex);
}

// slot
void MainWindow::slotSetTabClassName(int tabIndex, const QString& tabClassName)
{
    // set tab title text
    ui->tabWidgetClasses->setTabText(tabIndex, tabClassName);
}

// slot
void MainWindow::slotRelabelTabs(int from, int to)
{
    TabClassLayout *tabFrom = tblArr.at(from);
    TabClassLayout *tabTo = tblArr.at(to);

    tblArr.replace(from, tabTo);
    tblArr.replace(to, tabFrom);

    tabFrom->setTabIndex(to);
    tabTo->setTabIndex(from);

    tabFrom->setMyIndex(to);
    tabTo->setMyIndex(from);

    ClassItem *clsFrom = classItems.at(from);
    ClassItem *clsTo= classItems.at(to);

    classItems.replace(from, clsTo);
    classItems.replace(to, clsFrom);
}

// slot
void MainWindow::on_tabWidgetClasses_tabCloseRequested(int index)
{
    ui->tabWidgetClasses->removeTab(index);

    delete tblArr[index]; //may be bad practice, may be not
    tblArr.remove(index);

    delete classItems[index];
    classItems.remove(index);

    if (tblArr.count() == 0)
    {
        ui->pbGenerateAllClasses->setEnabled(false);
        ui->pbSaveAllClassFiles->setEnabled(false);
    }

    emit signalSetTabGenerated(false);

    for (int i = 0; i < tblArr.count(); i++)
    {
        connect(this, SIGNAL(signalSetTabGenerated(bool)), tblArr[i], SLOT(slotSetGenerated(bool)));
        emit signalSetTabGenerated(false);
        disconnect(this, SIGNAL(signalSetTabGenerated(bool)), tblArr[i], SLOT(slotSetGenerated(bool)));
    }
}
