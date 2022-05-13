#include "tabclasslayout.h"
#include "ui_tabclasslayout.h"
#include "mainwindow.h"
#include "QFileDialog"
#include <QDebug>
#include <QMenu>
#include <QMessageBox>
#include <QTimer>
#include "generatedclasscontentdialog.h"
#include <QComboBox>
#include <map>
#include "../Models/classitem.h"
#include "../Events/mousewheelwidgetadjustmentguard.h"
#include "QFileInfo"
//#include "qfileinfo.h"
#include "../Settings/settings.h"
//#include <QFile>


#define _KEYWORD_REQUIRE_       "require"

TabClassLayout::TabClassLayout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabClassLayout)
{
    ui->setupUi(this);
    ui->labelClassCreated->setVisible(false);

    QAction *foo = new QAction(this);
    foo->setShortcut(Qt::Key_Q | Qt::CTRL);

    connect(foo, SIGNAL(triggered()), this, SLOT(slotOpenGeneratedClassFile()));
    this->addAction(foo);

    //    TabClassLayout::slotSetGenerated(false);

    //    myIndex = tabIndex;
    // setting context menu
    ui->tableWidget_required->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_required->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_required->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget_required, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotDisplayMenuTbl_required(QPoint)));

    ui->tableWidget_fields->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_fields->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget_fields->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget_fields, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotDisplayMenuTbl_fields(QPoint)));

    _btnRequiredGroup = new QSignalMapper(this);
    connect(_btnRequiredGroup, SIGNAL(mapped(int)), this, SLOT(slotBtnOutClick(int)));

    clsItem = new ClassItem();
}

TabClassLayout::~TabClassLayout()
{
    delete ui;
}

ClassItem* TabClassLayout::getMyClassItem()
{
    return clsItem;
}

void TabClassLayout::setMyIndex(int value)
{
    myIndex = value;
}

//standart slots
#define FOLDINGSTART {
// slot
void TabClassLayout::on_pbDwnlFromFIle_clicked()
{
    QString file_path = QFileDialog::getOpenFileName(this, "Select sript file", QDir::homePath(), "*.jcd");

    if (file_path.isEmpty())
        return;

    slotUploadClassFromFile(file_path);
}

// slot
void TabClassLayout::on_pbSaveClassFiles_clicked()
{
    // checking on correct class name
    if (ui->lineEditClassName->text().isEmpty() || ui->lineEditClassName->text()[0] == ' ')
    {
        QMessageBox::warning(
                    this,
                    tr("Json Class Generator"),
                    tr("Invalid class name format!") );

        return;
    }

    slotSaveScriptFile();

    ui->labelClassCreated->setText("<font color='red'>Script file saved!</font>");
    ui->labelClassCreated->setVisible(true);

    QTimer::singleShot(1000,ui->labelClassCreated,SLOT(hide()));
}

// slot
void TabClassLayout::on_pbSaveChanges_clicked()
{
    slotFillModelFromFormElements();
}

// slot
void TabClassLayout::on_pbDiscardChanges_clicked()
{
    slotFillFormElementsFromModel();
}

// slot
void TabClassLayout::on_lineEditClassName_textChanged(const QString &arg1)
{
    emit signalSetTabClassName(myIndex, ui->lineEditClassName->text());
    TabClassLayout::slotSetGenerated(false);
}

// slot
void TabClassLayout::on_tableWidget_required_cellChanged(int row, int column)
{

    QString nameReqCls = ui->tableWidget_required->item(row, column)->text();

    for (int i = 0 ; i < ui->tableWidget_required->rowCount() ; i ++)
    {
        if (i == row)
            continue;

        if (ui->tableWidget_required->item(i, column) != nullptr)
        {
            if (ui->tableWidget_required->item(i, column)->text() == nameReqCls)
            {
                ui->tableWidget_required->item(row, column)->setText("");

                QMessageBox* msg = new QMessageBox();
                msg->setWindowTitle("Warning !");
                msg->setText("Required class with that name already exists");
                msg->show();

                return;
            }
        }
    }

    ui->pbSaveChanges->setEnabled(true);
    ui->pbDiscardChanges->setEnabled(true);
    TabClassLayout::slotSetGenerated(false);
}

// slot
void TabClassLayout::on_tableWidget_fields_cellChanged(int row, int column)
{
    TabClassLayout::slotSetGenerated(false);
}

// slot
void TabClassLayout::on_pbOpenGenFiles_clicked()
{
    TabClassLayout::slotOpenGeneratedClassFile();
}
#define FOLDINGEND }

void TabClassLayout::generateClass()
{
    slotFillModelFromFormElements();

    if (!clsItem->getChangesSaved())
    {
        return;
    }

    bool resGen = QtJsonClassGenerator::compile(classItems, myIndex);

    // clear fake required classes
    // TODO optimize this, may be architecture
    if (resGen)
    {
        for (int i = 0 ; i < clsItem->requiredClasses_count() ; i++)
        {
            bool exist = false;
            QString rName = clsItem->requiredClasses_get(i)->getName();

            int j;
            for (j = 0 ; j < classItems->count() ; j++)
            {
                if (rName == classItems->at(j)->getName())
                {
                    exist = true;
                    break;
                }
            }

            j--;

            if (!exist)
            {
                resGen = false;

                QMessageBox* msg = new QMessageBox();
                msg->setWindowTitle("Generation class "  + clsItem->getName() + ". Warning!" );
                msg->setText("Required class " + rName + " not exist");
                msg->show();

                //                return;
                //                clsItem->requiredClasses_removeAt(i);
                //                i--;

                //                connect(this, SIGNAL(signalFillFormElementsFromModel()), tblArr[indexCls], SLOT(slotFillFormElementsFromModel()));
                //                emit signalFillFormElementsFromModel();
                //                disconnect(this, SIGNAL(signalFillFormElementsFromModel()), tblArr[indexCls], SLOT(slotFillFormElementsFromModel()));
            }
        }
    }

    TabClassLayout::slotSetGenerated(resGen);

    //    connect(this, SIGNAL(signalSetTabGenerated(bool)), tblArr[indexCls], SLOT(slotSetGenerated(bool)));
    //    emit signalSetTabGenerated(resGen);
    //    disconnect(this, SIGNAL(signalSetTabGenerated(bool)), tblArr[indexCls], SLOT(slotSetGenerated(bool)));

}

//custom slots and logic
#define FOLDINGSTART {
void TabClassLayout::slotDisplayMenuTbl_required(const QPoint &pos)
{
    QMenu menu(this);

    QAction *add = menu.addAction("Add");
    QAction *rem;
    QAction *gtCls;

    if(ui->tableWidget_required->rowCount() > 0)
    {
        rem = menu.addAction("Remove");
        gtCls = menu.addAction("Go to class");
    }

    QAction *a = menu.exec(ui->tableWidget_required->viewport()->mapToGlobal(pos));

    if (a == add)
    {
        int rowCount = ui->tableWidget_required->rowCount();

        ui->tableWidget_required->insertRow(rowCount);
        ui->tableWidget_required->setCurrentCell(rowCount, 0);

        //        QTableWidgetItem *newItem = new QTableWidgetItem();
        //        newItem->setText("");
        //        ui->tableWidget_required->setItem(rowCount - 1, 0, newItem);
        //        QTableWidgetItem *newItem2 = new QTableWidgetItem();
        //        newItem2->setText("");
        //        ui->tableWidget_required->setItem(rowCount - 1, 1, newItem2);

        TabClassLayout::slotSetGenerated(false);
    }
    else if (a == rem)
    {
        QModelIndexList selection = ui->tableWidget_required->selectionModel()->selectedRows();

        if (selection.count() > 0) {
            QModelIndex index = selection.at(0);

            //row selected
            int row = index.row();

            if (ui->tableWidget_required->item(row, 0) != nullptr)
            {
                QString clsName = ui->tableWidget_required->item(row, 0)->text();
                clsItem->requiredClasses_removeByName(clsName);
            }

            ui->tableWidget_required->removeRow(row);

//            QPushButton *btn_edit = bntRequiredItems.at(row);
//////            disconnect(_btnRequiredGroup, SIGNAL(mapped(int)), this, SLOT(slotBtnOutClick(int)));
//            _btnRequiredGroup->children()->removeAt(row);
//            disconnect( btn_edit, SIGNAL(clicked()), _btnRequiredGroup, SLOT(map()));
//            bntRequiredItems.removeAt(row);
//            delete btn_edit;

            slotFillFormElementsFromModel();
            TabClassLayout::slotSetGenerated(false);
        }
    }
    else if (a == gtCls)
    {
        QModelIndexList selection = ui->tableWidget_required->selectionModel()->selectedRows();
        QModelIndex index = selection.at(0);
        //row selected
        int row = index.row();
        QString clsName = ui->tableWidget_required->item(row, 0)->text();

        emit signalSetCurrentTabPage(clsName);

        //        for (int i = 0 ; i < clsItem->requiredClasses_count() ; i ++)
        //        {
        //            if (clsItem->requiredClasses_get(i)->getName() == clsName)
        //            {
        //                emit signalSetCurrentTabPage(i);
        //                break;
        //            }
        //        }

        //        for(int i = 0 ; i < ui->tableWidget_required->rowCount() ; i++)
        //        {
        //            RequiredClass *rClass = new RequiredClass();
        //            rClass->setName(ui->tableWidget_required->item(i, 0)->text());
        //            rClass->setFileName(ui->tableWidget_required->item(i, 1)->text());
        //            clsItem->requiredClasses_add(rClass);
        //        }
    }
}

void TabClassLayout::slotDisplayMenuTbl_fields(const QPoint &pos)
{
    QMenu menu(this);

    QAction *add = menu.addAction("Add");
    QAction *rem;

    if(ui->tableWidget_fields->rowCount() > 0)
        rem = menu.addAction("Remove");

    QAction *a = menu.exec(ui->tableWidget_fields->viewport()->mapToGlobal(pos));

    if (a == add)
    {
        // fill tableWidget_fields
        int newRowCount = ui->tableWidget_fields->rowCount() + 1;
        ui->tableWidget_fields->setRowCount(newRowCount);

        QTableWidgetItem *newItem = new QTableWidgetItem();
        ui->tableWidget_fields->setItem(newRowCount - 1, 0, newItem);

        newItem = new QTableWidgetItem();
        ui->tableWidget_fields->setItem(newRowCount - 1, 1, newItem);

        newItem = new QTableWidgetItem();
        ui->tableWidget_fields->setItem(newRowCount - 1, 2, newItem);

        // hardcode-------- refactor this urgently
        QComboBox *cmb = new QComboBox(ui->tableWidget_fields);
        cmb->addItems(QtJsonClassGenerator::supported_types.keys().toVector().toList());
        connect(cmb, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(slotCurrentIndexChanged(const QString&)));

        // add required class types
        for(int i = 0; i < clsItem->requiredClasses_count(); i++)
        {
            cmb->addItem(clsItem->requiredClasses_get(i)->getName());
        }

        cmb->setFocusPolicy(Qt::StrongFocus);
        cmb->installEventFilter(new MouseWheelWidgetAdjustmentGuard(cmb));
        ui->tableWidget_fields->setCellWidget(newRowCount - 1, 1, cmb);

        cmb = new QComboBox(ui->tableWidget_fields);
        cmb->addItem("true");
        cmb->addItem("false");

        cmb->setFocusPolicy(Qt::StrongFocus);
        cmb->installEventFilter(new MouseWheelWidgetAdjustmentGuard(cmb));
        ui->tableWidget_fields->setCellWidget(newRowCount - 1, 2, cmb);
        ui->tableWidget_fields->setCurrentCell(newRowCount - 1, 0);

        TabClassLayout::slotSetGenerated(false);
    }
    else if (a == rem)
    {
        QModelIndexList selection = ui->tableWidget_fields->selectionModel()->selectedRows();

        if (selection.count() > 0) {
            QModelIndex index = selection.at(0);

            //row selected
            int row = index.row();
            ui->tableWidget_fields->removeRow(row);

            TabClassLayout::slotSetGenerated(false);
        }
    }
}

void TabClassLayout::slotUploadClassFromFile(const QString &filePath)
{
    clsItem->setScriptFilePath(filePath);

    clsItem->setName("");
    clsItem->requiredClasses_clear();
    clsItem->classProperties_clear();

    ui->tableWidget_required->setRowCount(0);
    ui->tableWidget_fields->setRowCount(0);

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    while (!file.atEnd()) {
        QString line = QString::fromStdString(file.readLine().toStdString());
        process_line(line);
    }

    slotFillFormElementsFromModel();

    ui->pbSaveChanges->setEnabled(false);
    ui->pbDiscardChanges->setEnabled(false);
}

void TabClassLayout::process_line(QString& line)
{
    // static int row = 0;
    QStringList words = line.split(',');

    // trim all
    for(auto& str : words)
        str = str.trimmed();

    if (words.size() == 1) {
        if (line.split(' ').front() == QString(_KEYWORD_REQUIRE_))
        {
            words = line.split(' ');
            QString reqString = words.at(1).trimmed();
            RequiredClass *rClass = new RequiredClass();
            rClass->setFileName(reqString);

            QFile rFile(reqString);
            // check on absolute path
            if(rFile.exists())
                rClass->setAbsoluteFilePath(reqString);
            else
            {
                // check on relative path
                QFileInfo fi(clsItem->getScriptFilePath());
//                QDir dir(fi.dir().absolutePath());
                QString path = fi.dir().path() + "/" + reqString;
                QFile relativeFile(path);
                if(relativeFile.exists())
                {
                    QFileInfo fiRel(path);
                    rClass->setAbsoluteFilePath(fiRel.absoluteFilePath());
                }
            }

//            QString LFName = dir.relativeFilePath(classItems->at(i)->getScriptFilePath());
//            rClass->setAbsoluteFilePath(dir + rClass->getFileName());

//            clsItem->requiredClasses_get(r)->setFileName(LFName);

            for (int i = 0 ; i < clsItem->requiredClasses_count() ; i++)
            {
                if (clsItem->requiredClasses_get(i)->getName() == rClass->getName())
                    return;
            }

            clsItem->requiredClasses_add(rClass);
        }
        else
        {
            clsItem->setName(words[0]);
        }
    }
    else
    {
        // refactor
        ClassProperty *cPropery = new ClassProperty();
        cPropery->setName(words.at(0).trimmed());
        cPropery->setType(words.at(1).trimmed());
        cPropery->setIsCollection(static_cast<QVariant>(words.at(2).trimmed()).toBool());

        clsItem->classProperties_add(cPropery);
    }
}

bool TabClassLayout::checkCorrectFormData()
{
    // TODO add validations

    QString warnText;

    bool result = true;
    clsItem->setChangesSaved(true);

    // check class name
    if(ui->lineEditClassName->text().isEmpty() || ui->lineEditClassName->text()[0] == ' ')
    {
        result = false;

        warnText = "Class name is not correct";
    }

    // check required classes
    for(int i = 0 ; i < ui->tableWidget_required->rowCount() ; i++)
    {
        if (ui->tableWidget_required->item(i, 0) == nullptr
                || ui->tableWidget_required->item(i, 0)->text().isEmpty()
                || ui->tableWidget_required->item(i, 0)->text()[0] == ' ')
        {
            result = false;
            warnText = "Required class name in class " + clsItem->getName() + " is not correct";
            break;
        }
    }

    // check class properties
    // TODO

    if (!result)
    {
        clsItem->setChangesSaved(false);

        QMessageBox* msg = new QMessageBox();
        msg->setWindowTitle("Warning !");
        msg->setText(warnText);
        msg->show();
    }

    return result;
}

void TabClassLayout::slotFillModelFromFormElements()
{
    if(!checkCorrectFormData())
        return;

    // fill name
    clsItem->setName(ui->lineEditClassName->text());

    // fill namespaces
    clsItem->namespaces_clear();

    QStringList words_path = ui->lineEditNamespaces->text().split(',');
    for(auto& str : words_path)
    {
        str = str.trimmed();
        if (str != "")
            clsItem->namespaces_add(str);
    }

    // fill required classes
    clsItem->requiredClasses_clear();
    for(int i = 0 ; i < ui->tableWidget_required->rowCount() ; i++)
    {
        RequiredClass *rClass = new RequiredClass();
        rClass->setName(ui->tableWidget_required->item(i, 0)->text());

        if (ui->tableWidget_required->item(i, 1) != nullptr && !ui->tableWidget_required->item(i, 1)->text().isEmpty())
            rClass->setAbsoluteFilePath(ui->tableWidget_required->item(i, 1)->text());

        clsItem->requiredClasses_add(rClass);
    }

    // fill class properties
    clsItem->classProperties_clear();
    for(int i = 0 ; i < ui->tableWidget_fields->rowCount() ; i++)
    {
        ClassProperty *clsProp = new ClassProperty();
        clsProp->setName(ui->tableWidget_fields->item(i, 0)->text());

        QComboBox *qcb = qobject_cast<QComboBox*>(ui->tableWidget_fields->cellWidget(i, 1));
        clsProp->setType(qcb->currentText());

        qcb = qobject_cast<QComboBox*>(ui->tableWidget_fields->cellWidget(i, 2));
        clsProp->setIsCollection(static_cast<QVariant>(qcb->currentText().trimmed()).toBool());

        clsItem->classProperties_add(clsProp);
    }

    ui->pbSaveChanges->setEnabled(false);
    ui->pbDiscardChanges->setEnabled(false);
}

// slot
void TabClassLayout::slotFillFormElementsFromModel()
{
    bool oldIsGenerated = clsItem->getIsGenerated();

    // this is a class name
    ui->lineEditClassName->setText(clsItem->getName());
    emit signalSetTabClassName(myIndex, clsItem->getName());

    // fill namespaces
    QString nsStr = "";
    for (int i = 0 ; i < clsItem->namespaces_count() ; i++)
    {
        if (i < clsItem->namespaces_count() - 1)
            nsStr += clsItem->namespaces_get(i) + ",";
        else
            nsStr += clsItem->namespaces_get(i);
    }
    ui->lineEditNamespaces->setText(nsStr);

    // fill tableWidget_required
    ui->tableWidget_required->setRowCount(clsItem->requiredClasses_count());
    for( int row = 0; row < clsItem->requiredClasses_count(); row++)
    {
        RequiredClass *reqCls = clsItem->requiredClasses_get(row);
        QTableWidgetItem *newItem = new QTableWidgetItem( reqCls->getName() );
        ui->tableWidget_required->setItem(row, 0, newItem);

        QTableWidgetItem *newItem2 = new QTableWidgetItem( reqCls->getAbsoluteFilePath() );
        ui->tableWidget_required->setItem(row, 1, newItem2);

        QWidget* pWidget = new QWidget();
        QPushButton* btn_edit = new QPushButton("...", ui->tableWidget_required);
//        btn_edit->setText("...");
        btn_edit->setMaximumSize(QSize(21, 21));

        _btnRequiredGroup->setMapping( btn_edit, row );
        connect( btn_edit, SIGNAL(clicked()), _btnRequiredGroup, SLOT(map()));
//        bntRequiredItems.push_back(btn_edit);

//        connect(btn_edit, SIGNAL(clicked()), this, SLOT(slotChoiseRequiredClass()));

        QHBoxLayout* pLayout = new QHBoxLayout(pWidget);
        pLayout->addWidget(btn_edit);
        pLayout->setAlignment(Qt::AlignRight);
        pLayout->setContentsMargins(0, 0, 0, 0);
        pWidget->setLayout(pLayout);

        ui->tableWidget_required->setCellWidget(row, 1, pWidget);
    }
//    ui->tableWidget_required->resizeColumnsToContents();

//    QTableWidget* myTable = new QTableWidet;
    ui->tableWidget_required->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//    header->setSectionResizeMode(QHeaderView::Stretch);
//    ui->tableWidget_required->horizontalHeader()->setStretchLastSection(1);
//     ui->tableWidget_required->resizeColumnToContents(1);
//    ui->tableWidget_required->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // fill tableWidget_fields
    ui->tableWidget_fields->setRowCount(clsItem->classProperties_count());
    for( int row = 0; row < clsItem->classProperties_count(); row++)
    {
        ClassProperty *clsProperty = clsItem->classProperties_get(row);

        QTableWidgetItem *newItem = new QTableWidgetItem( clsProperty->getName() );
        ui->tableWidget_fields->setItem(row, 0, newItem);

        newItem = new QTableWidgetItem( clsProperty->getType() );
        ui->tableWidget_fields->setItem(row, 1, newItem);

        newItem = new QTableWidgetItem();
        ui->tableWidget_fields->setItem(row, 2, newItem);

        // hardcode-------- refactor this urgently
        QComboBox *cmb = new QComboBox(ui->tableWidget_fields);
        cmb->addItems(QtJsonClassGenerator::supported_types.keys().toVector().toList());
        connect(cmb, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(slotCurrentIndexChanged(const QString&)));

        // add required class types
        for(int i = 0; i < clsItem->requiredClasses_count(); i++)
        {
            cmb->addItem(clsItem->requiredClasses_get(i)->getName());
        }

        int index = cmb->findText( clsProperty->getType() );
        if ( index != -1 ) { // -1 for not found
            cmb->setCurrentIndex(index);
        }

        cmb->setFocusPolicy(Qt::StrongFocus);
        cmb->installEventFilter(new MouseWheelWidgetAdjustmentGuard(cmb));
        ui->tableWidget_fields->setCellWidget(row, 1, cmb);

        cmb = new QComboBox(ui->tableWidget_fields);
        cmb->addItem("true");
        cmb->addItem("false");
        connect(cmb, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(slotCurrentIndexChanged(const QString&)));

        QString str = "false";
        if (clsProperty->getIsCollection())
            str = "true";

        index = cmb->findText(str);
        if ( index != -1 ) { // -1 for not found
            cmb->setCurrentIndex(index);
        }

        cmb->setFocusPolicy(Qt::StrongFocus);
        cmb->installEventFilter(new MouseWheelWidgetAdjustmentGuard(cmb));
        ui->tableWidget_fields->setCellWidget(row, 2, cmb);
        // ----------hardcode
    }
//    ui->tableWidget_fields->resizeColumnsToContents();
    ui->tableWidget_fields->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
//    ui->tableWidget_fields->resizeColumnToContents(1);
//    ui->tableWidget_fields->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    ui->tableWidget_fields->horizontalHeader()->setStretchLastSection(true);
//    ui->pbSaveChanges->setEnabled(false);
//    ui->pbDiscardChanges->setEnabled(false);
    slotSetGenerated(oldIsGenerated);

}

void TabClassLayout::slotBtnOutClick(int btn)
{
//    ui->tableWidget_required->setSelectionModel(ui->tableWidget_required->selectionModel());
    ui->tableWidget_required->selectRow(btn);
    QModelIndexList selection = ui->tableWidget_required->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    //row selected
    int row = index.row();

//    QString clsName = ui->tableWidget_required->item(row, 0)->text();
//    clsItem->requiredClasses_removeByName(clsName);

//    ui->tableWidget_required->removeRow(row);
    QString file_path = QFileDialog::getOpenFileName(this, "Select sript file", QDir::homePath(), "*.jcd");

    if (file_path.isEmpty())
        return;


    RequiredClass *rClass = clsItem->requiredClasses_get(row);

    rClass->setFileName(file_path);

//    QFile rFile(reqString);
    // check on absolute path
//    if(rFile.exists())
    rClass->setAbsoluteFilePath(file_path);
//    else
//    {
//        // check on relative path
//        QFileInfo fi(clsItem->getScriptFilePath());
////                QDir dir(fi.dir().absolutePath());
//        QString path = fi.dir().path() + "/" + reqString;
//        QFile relativeFile(path);
//        if(relativeFile.exists())
//        {
//            QFileInfo fiRel(path);
//            rClass->setAbsoluteFilePath(fiRel.absoluteFilePath());
//        }
//    }
    auto newItem = new QTableWidgetItem( rClass->getName() );
    ui->tableWidget_required->setItem(row, 0, newItem);

    newItem = new QTableWidgetItem( rClass->getAbsoluteFilePath() );
    ui->tableWidget_required->setItem(row, 1, newItem);

    slotFillFormElementsFromModel();
//    TabClassLayout::slotSetGenerated(false);
}

void TabClassLayout::slotUpdateDataClasses()
{
//    for ( int r = 0 ; r < clsItem->requiredClasses_count() ; r++)
//    {
//        for(int i = 0 ; i < classItems->count() ; i++)
//        {
//            if(classItems->at(i)->getName() == clsItem->requiredClasses_get(r)->getName())
//            {
//                QFileInfo fi(clsItem->getScriptFilePath());

//                QDir dir(fi.dir().absolutePath());
//                QString LFName= dir.relativeFilePath(classItems->at(i)->getScriptFilePath());

//                clsItem->requiredClasses_get(r)->setFileName(LFName);
//            }
//        }
//    }

//    slotFillFormElementsFromModel();
}

void TabClassLayout::slotSaveScriptFile()
{
    if (clsItem->getIsGenerated() != true)
        return;

    QString path = "";

    if  (!Settings::saveDirectory.isEmpty())
        path = Settings::saveDirectory + "/";

    QFile file (clsItem->getScriptFilePath());
    QFileInfo fi(clsItem->getScriptFilePath());

    if (Settings::saveDirectory == fi.dir().absolutePath() || path == "")
    {
        path = fi.dir().absolutePath() + "/";
        file.remove();
    }

    saveScriptFile(path + clsItem->getClassName() + ".jcd"); // save .jcd file

}

void TabClassLayout::saveScriptFile(const QString &name)
{
    QFile file(name);

    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QTextStream data( &file );
        QStringList strList;

        // write required classes
        for( int r = 0; r < clsItem->requiredClasses_count() ; ++r )
        {
            strList.clear();
            data << "require ";

            RequiredClass *rClass = clsItem->requiredClasses_get(r);

            strList << rClass->getFileName();
            data << strList.join( "" ) + "\n";
        }

        // write class name
        strList.clear();
        strList << clsItem->getName();
        data << strList.join("") << "\n";

        // write class fields
        for( int r = 0; r < clsItem->classProperties_count() ; ++r )
        {
            strList.clear();

            ClassProperty *cProp = clsItem->classProperties_get(r);

            strList << cProp->getName() + ", " + cProp->getType() + ", " + (cProp->getIsCollection() ? "true" : "false");

            if (r < clsItem->classProperties_count() - 1)
                data << strList.join( "" ) + "\n";
            else
                data << strList.join( "" );
        }

        clsItem->setScriptFilePath(file.fileName());
        file.close();

    }
}

void TabClassLayout::slotSaveHppAndCppFiles()
{
    if (clsItem->getIsGenerated() != true)
        return;

    QString rootPath;
    if (clsItem->getIncludeProjectDirPath() == "")
    {
        QFileInfo fi(clsItem->getScriptFilePath());
        rootPath = fi.dir().absolutePath() + "/";

        QFile oldFileH (oldHFilePath);
        oldFileH.remove();

        oldHFilePath = rootPath + clsItem->getClassName() + ".h";
        std::ofstream fileHpp(oldHFilePath.toStdString());
        fileHpp << clsItem->getHStream();

        QFile oldFileCpp (oldCppFilePath);
        oldFileCpp.remove();

        oldCppFilePath = rootPath + clsItem->getClassName() + ".cpp";
        std::ofstream fileCpp(oldCppFilePath.toStdString());
        fileCpp << clsItem->getCppStream();
    }
}

void TabClassLayout::slotOpenGeneratedClassFile()
{
    GeneratedClassContentDialog *gcCont = new GeneratedClassContentDialog(clsItem, this);
    gcCont->show();
}

void TabClassLayout::slotSetGenerated(bool isGen)
{
    if (isGen)
    {
        clsItem->setIsGenerated(true);
        ui->pbSaveChanges->setEnabled(false);
        ui->pbDiscardChanges->setEnabled(false);
        ui->labelGenerated->setText("<font color='green'>Generated</font>");
    }
    else
    {
        clsItem->setIsGenerated(false);
        ui->pbSaveChanges->setEnabled(true);
        ui->pbDiscardChanges->setEnabled(true);
        ui->labelGenerated->setText("<font color='red'>Not generated</font>");
    }
}

void TabClassLayout::slotCurrentIndexChanged(const QString& text)
{
    TabClassLayout::slotSetGenerated(false);
}

void TabClassLayout::setTabIndex(int tabIndex)
{
    myIndex = tabIndex;
}

QString TabClassLayout::transformNameForFile(const QString& str)
{
    QString path;
    QStringList words_path = str.split(' ');

    for(auto& str : words_path)
    {
        str = str.trimmed();
        str[0] = str[0].toUpper();
        path += str;
    }

    return path;
}
#define FOLDINGEND }

void TabClassLayout::on_lineEditNamespaces_textChanged(const QString &arg1)
{
    TabClassLayout::slotSetGenerated(false);
}

QVector<ClassItem *> *TabClassLayout::getClassItems() const
{
    return classItems;
}

void TabClassLayout::setClassItems(QVector<ClassItem *> *value)
{
    classItems = value;
}

//QVector<ClassItem*>* TabClassLayout::getClassItems()
//{
//    return classItems;
//}

//void TabClassLayout::setClassItems(QVector<ClassItem*>* &value)
//{
//    classItems = value;
//}


void TabClassLayout::on_tableWidget_required_itemActivated(QTableWidgetItem *item)
{
    int k = 1;
    int l = k + 3;
}

QString TabClassLayout::getOldCppFilePath() const
{
    return oldCppFilePath;
}

QString TabClassLayout::getOldHFilePath() const
{
    return oldHFilePath;
}
