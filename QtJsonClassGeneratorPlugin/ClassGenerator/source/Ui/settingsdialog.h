#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
//#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

private slots:
    void on_pbChooseFolder_clicked();

    void on_pbSaveSettings_clicked();

    void on_pbChooseUncrustifyConfig_clicked();

    void on_checkBoxUncrustify_clicked();

    void on_pbChooseUncrustifyPath_clicked();

    void on_lineEditUncrustifyCommand_editingFinished();

    void on_lineEditUncrustifyConfigFile_editingFinished();

private:
    Ui::SettingsDialog *ui;
    void setUncrustifyElementsEnable(bool enabled);
    void checkExistingUncrustify();
    void checkPathConfigUncrustify();
};

#endif // SETTINGSDIALOG_H
