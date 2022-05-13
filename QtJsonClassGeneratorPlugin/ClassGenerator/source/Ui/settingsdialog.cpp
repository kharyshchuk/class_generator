#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include "QFileDialog"
#include <QJsonObject>
#include <QJsonDocument>
#include "../Settings/settings.h"
#include "QMessageBox"


SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    ui->lineEditSaveDirectory->setText(Settings::saveDirectory);
    ui->checkBoxUncrustify->setChecked(Settings::useUncrustify);
    ui->checkBoxLightGeneration->setChecked(Settings::useLightGenerated);
    ui->checkBoxIncludeInCurProj->setChecked(Settings::includeFilesInCurrentProject);

    setUncrustifyElementsEnable(ui->checkBoxUncrustify->isChecked());

    ui->lineEditUncrustifyCommand->setText(Settings::commandUncrustify);
    ui->lineEditUncrustifyConfigFile->setText(Settings::pathConfigUncrustify);

    checkExistingUncrustify();
    checkPathConfigUncrustify();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_pbChooseFolder_clicked()
{
    QString dir_path = QFileDialog::getExistingDirectory(this, "Select derectory", !Settings::saveDirectory.isEmpty() ? Settings::saveDirectory : QDir::homePath());

    if (!dir_path.isEmpty())
        ui->lineEditSaveDirectory->setText(dir_path);
}

void SettingsDialog::on_pbSaveSettings_clicked()
{
    QVariantMap map;

    Settings::saveDirectory = ui->lineEditSaveDirectory->text();

    Settings::useUncrustify = ui->checkBoxUncrustify->isChecked();
    Settings::commandUncrustify = ui->lineEditUncrustifyCommand->text();
    Settings::pathConfigUncrustify = ui->lineEditUncrustifyConfigFile->text();
    Settings::useLightGenerated = ui->checkBoxLightGeneration->isChecked();
    Settings::includeFilesInCurrentProject = ui->checkBoxIncludeInCurProj->isChecked();

    map.insert("savedirectory", Settings::saveDirectory);
    map.insert("useuncrustify", Settings::useUncrustify);
    map.insert("commanduncrustify", Settings::commandUncrustify);
    map.insert("pathconfiguncrustify", Settings::pathConfigUncrustify);
    map.insert("uselightgenerated", Settings::useLightGenerated);
    map.insert("includefilesincurrentproject", Settings::includeFilesInCurrentProject);

    QJsonObject object = QJsonObject::fromVariantMap(map);

    QJsonDocument document;
    document.setObject(object);

    Settings::saveJson(document, "ClassGenSettings.jsn");

    this->close();
}

void SettingsDialog::on_checkBoxUncrustify_clicked()
{

    if (ui->checkBoxUncrustify->isChecked())
        setUncrustifyElementsEnable(true);
    else
        setUncrustifyElementsEnable(false);
}

void SettingsDialog::on_pbChooseUncrustifyPath_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(this, "Select Uncrustify executing file", !Settings::commandUncrustify.isEmpty() ? Settings::commandUncrustify : QDir::homePath());

    if (file_path.isEmpty())
        return;

    ui->lineEditUncrustifyCommand->setText(file_path);

    checkExistingUncrustify();
}

void SettingsDialog::on_pbChooseUncrustifyConfig_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(this, "Select Uncrustify config file", QDir::homePath(), "*.cfg");

    if (file_path.isEmpty())
        return;

    ui->lineEditUncrustifyConfigFile->setText(file_path);
    checkPathConfigUncrustify();
}

void SettingsDialog::on_lineEditUncrustifyCommand_editingFinished()
{
    checkExistingUncrustify();
}

void SettingsDialog::on_lineEditUncrustifyConfigFile_editingFinished()
{
    checkPathConfigUncrustify();
}

void SettingsDialog::setUncrustifyElementsEnable(bool enabled)
{
    ui->label_3->setEnabled(enabled);
    ui->lineEditUncrustifyCommand->setEnabled(enabled);

    ui->label_2->setEnabled(enabled);
    ui->lineEditUncrustifyConfigFile->setEnabled(enabled);
}

void SettingsDialog::checkExistingUncrustify()
{
    QString command = "which " + ui->lineEditUncrustifyCommand->text();

    //Create QPalette here and set its Color and Color Role
    QPalette *palette = new QPalette();

    if (system(command.toStdString().c_str()) != 0)
    {
        palette->setColor(QPalette::Text,Qt::red);
        ui->lineEditUncrustifyCommand->setPalette(*palette);
    }
    else
    {
        palette->setColor(QPalette::Text,Qt::black);
        ui->lineEditUncrustifyCommand->setPalette(*palette);
    }
}

void SettingsDialog::checkPathConfigUncrustify()
{
    QFile file (ui->lineEditUncrustifyConfigFile->text());

    //Create QPalette here and set its Color and Color Role
    QPalette *palette = new QPalette();

    if (file.exists())
    {
        palette->setColor(QPalette::Text,Qt::black);
        ui->lineEditUncrustifyConfigFile->setPalette(*palette);
    }
    else
    {
        palette->setColor(QPalette::Text,Qt::red);
        ui->lineEditUncrustifyConfigFile->setPalette(*palette);
    }
}

