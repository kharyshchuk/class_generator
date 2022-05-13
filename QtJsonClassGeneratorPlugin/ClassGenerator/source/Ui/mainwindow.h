#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tabclasslayout.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void signalUploadTabClassFromFile(const QString& filePathe);
    void signalSaveTabScriptFile();
    void signalSaveTabHppAndCppFiles();
    void signalIncludeFilesInProject(const QVector<ClassItem*> &classImets);
    void signalFillModelFromFormElements();
    void signalFillFormElementsFromModel();
    void signalSetTabGenerated(bool isGen);
    void signalProxyGenerateClass(int indexCls);
    void signalGenerateClass();
    void signalUpdateDataClasses();
//    void signalSetTabIndex(int tabIndex);

private slots:
    void on_pbSettings_clicked();
    void on_pbAddClass_clicked();
    void on_pbDwnlScriptFiles_clicked();
    void on_pbGenerateAllClasses_clicked();
    void on_pbSaveAllClassFiles_clicked();
    void on_tabWidgetClasses_tabCloseRequested(int index);

    void slotSetTabClassName(int tabIndex, const QString& tabClassName);
    void slotCreateTabClass(const QString &filePath);
    bool slotProxyGenerateClass(int indexCls);
    void slotSetCurrentTabPage(const QString& className);
    void slotRelabelTabs(int from, int to);
//    void slotIncludeFilesInProject(const QVector<ClassItem*> &classImets);

private:
    Ui::MainWindow *ui;
    QVector<ClassItem*> classItems;
    QVector<TabClassLayout*> tblArr;
    void createTabPageClass(const QString &filePath = "");
    void includeFilesInProject();

};

#endif // MAINWINDOW_H
