#ifndef GENERATEDCLASSCONTENTDIALOG_H
#define GENERATEDCLASSCONTENTDIALOG_H

#include <QDialog>
#include "../Models/classitem.h"

namespace Ui {
class GeneratedClassContentDialog;
}

class GeneratedClassContentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GeneratedClassContentDialog(ClassItem *classItem, QWidget *parent = 0);
    ~GeneratedClassContentDialog();

private slots:
    void closeDialog();
    void changeContent();

private:
    Ui::GeneratedClassContentDialog *ui;
    ClassItem *clsItem;
    bool isHFile;
};

#endif // GENERATEDCLASSCONTENTDIALOG_H
