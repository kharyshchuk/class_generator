#ifndef TABCLASSLAYOUT_H
#define TABCLASSLAYOUT_H

#include <QWidget>
#include <QtWidgets/QTableWidget>
#include "../JsonClassGenerator/qtjsonclassgenerator.h"
#include <QComboBox>
#include "../Models/classitem.h"
#include <QSignalMapper>
#include <QPushButton>

namespace Ui {
class TabClassLayout;
}

class TabClassLayout : public QWidget
{
    Q_OBJECT

public:
    explicit TabClassLayout(QWidget *parent = 0);
    ~TabClassLayout();
    ClassItem* getMyClassItem();
    void setTabIndex(int tabIndex);

//    QVector<ClassItem*>* getClassItems();
//    void setClassItems(QVector<ClassItem*>* &value);
    void generateClass();

    QVector<ClassItem *> *getClassItems() const;
    void setClassItems(QVector<ClassItem *> *value);

    int getMyIndex() const;
    void setMyIndex(int value);

    QString getOldHFilePath() const;
    QString getOldCppFilePath() const;

signals:
    void signalSetTabClassName(int tabIndex, const QString& className);
    void signalSetCurrentTabPage(const QString& className);

private slots:
    void on_pbDwnlFromFIle_clicked();
    void on_pbSaveClassFiles_clicked();
    void on_pbSaveChanges_clicked();
    void on_pbDiscardChanges_clicked();
    void on_lineEditClassName_textChanged(const QString &arg1);
    void on_tableWidget_required_cellChanged(int row, int column);
    void on_tableWidget_fields_cellChanged(int row, int column);
    void on_pbOpenGenFiles_clicked();

    void slotDisplayMenuTbl_required(const QPoint &pos);
    void slotDisplayMenuTbl_fields(const QPoint &pos);
    void slotUploadClassFromFile(const QString &filePath);
    void slotFillModelFromFormElements();
    void slotFillFormElementsFromModel();
    void slotSaveScriptFile();
    void slotSaveHppAndCppFiles();
//    void slotIncludeFilesInProject();
    void slotOpenGeneratedClassFile();
    void slotSetGenerated(bool isGen);
    void slotCurrentIndexChanged(const QString& text);
    void slotUpdateDataClasses();
    void slotBtnOutClick(int btn);

    void on_lineEditNamespaces_textChanged(const QString &arg1);

    void on_tableWidget_required_itemActivated(QTableWidgetItem *item);

private:
    Ui::TabClassLayout *ui;
//    QString oldScriptFilePath;
    QString oldHFilePath;
    QString oldCppFilePath;

    QVector<ClassItem*>* classItems;
//    QVector<QPushButton*> bntRequiredItems;
    int myIndex;
    ClassItem *clsItem;

    void process_line(QString& line);
    bool checkCorrectFormData();
    void saveScriptFile(const QString& name);
    QString transformNameForFile(const QString& str);
    QSignalMapper *_btnRequiredGroup;
};

#endif // TABCLASSLAYOUT_H
