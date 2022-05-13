#include "generatedclasscontentdialog.h"
#include "ui_generatedclasscontentdialog.h"
#include <QFile>
#include "../Models/classitem.h"

GeneratedClassContentDialog::GeneratedClassContentDialog(ClassItem *classItem, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GeneratedClassContentDialog)
{
    ui->setupUi(this);
    clsItem = classItem;

    // hotkey open gen stream
    QAction *foo = new QAction(this);
    foo->setShortcut(Qt::Key_Q | Qt::CTRL);

    connect(foo, SIGNAL(triggered()), this, SLOT(closeDialog()));
    this->addAction(foo);

    // hotkey segue between .h .cpp
    QAction *chnContent = new QAction(this);
    chnContent->setShortcut(Qt::Key_W | Qt::CTRL);

    connect(chnContent, SIGNAL(triggered()), this, SLOT(changeContent()));
    this->addAction(chnContent);

    ui->textBrowser->setText(QString::fromStdString(clsItem->getHStream()));
    isHFile = true;
}

GeneratedClassContentDialog::~GeneratedClassContentDialog()
{
    delete ui;
}

void GeneratedClassContentDialog::closeDialog()
{
    this->close();
}

void GeneratedClassContentDialog::changeContent()
{
    if(isHFile)
    {
        ui->textBrowser->setText(QString::fromStdString(clsItem->getCppStream()));
        isHFile = false;
    }
    else
    {
        ui->textBrowser->setText(QString::fromStdString(clsItem->getHStream()));
        isHFile = true;
    }
}
