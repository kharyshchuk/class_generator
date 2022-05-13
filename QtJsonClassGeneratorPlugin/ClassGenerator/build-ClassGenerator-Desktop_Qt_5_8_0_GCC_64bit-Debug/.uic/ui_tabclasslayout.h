/********************************************************************************
** Form generated from reading UI file 'tabclasslayout.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABCLASSLAYOUT_H
#define UI_TABCLASSLAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TabClassLayout
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *labelClassCreated;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEditClassName;
    QPushButton *pbDwnlFromFIle;
    QLabel *labelGenerated;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *lineEditNamespaces;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *pbOpenGenFiles;
    QTableWidget *tableWidget_required;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QTableWidget *tableWidget_fields;
    QFormLayout *formLayout;
    QPushButton *pbSaveChanges;
    QPushButton *pbDiscardChanges;

    void setupUi(QWidget *TabClassLayout)
    {
        if (TabClassLayout->objectName().isEmpty())
            TabClassLayout->setObjectName(QStringLiteral("TabClassLayout"));
        TabClassLayout->resize(575, 684);
        verticalLayout_4 = new QVBoxLayout(TabClassLayout);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        labelClassCreated = new QLabel(TabClassLayout);
        labelClassCreated->setObjectName(QStringLiteral("labelClassCreated"));
        QFont font;
        font.setPointSize(14);
        labelClassCreated->setFont(font);
        labelClassCreated->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(labelClassCreated);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(TabClassLayout);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        lineEditClassName = new QLineEdit(TabClassLayout);
        lineEditClassName->setObjectName(QStringLiteral("lineEditClassName"));

        verticalLayout->addWidget(lineEditClassName);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        pbDwnlFromFIle = new QPushButton(TabClassLayout);
        pbDwnlFromFIle->setObjectName(QStringLiteral("pbDwnlFromFIle"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pbDwnlFromFIle->sizePolicy().hasHeightForWidth());
        pbDwnlFromFIle->setSizePolicy(sizePolicy);
        pbDwnlFromFIle->setLayoutDirection(Qt::LeftToRight);

        gridLayout->addWidget(pbDwnlFromFIle, 0, 1, 1, 1);

        labelGenerated = new QLabel(TabClassLayout);
        labelGenerated->setObjectName(QStringLiteral("labelGenerated"));
        labelGenerated->setFont(font);
        labelGenerated->setLayoutDirection(Qt::LeftToRight);
        labelGenerated->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelGenerated, 1, 1, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        splitter = new QSplitter(TabClassLayout);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        lineEditNamespaces = new QLineEdit(layoutWidget);
        lineEditNamespaces->setObjectName(QStringLiteral("lineEditNamespaces"));

        horizontalLayout_4->addWidget(lineEditNamespaces);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        pbOpenGenFiles = new QPushButton(layoutWidget);
        pbOpenGenFiles->setObjectName(QStringLiteral("pbOpenGenFiles"));
        sizePolicy.setHeightForWidth(pbOpenGenFiles->sizePolicy().hasHeightForWidth());
        pbOpenGenFiles->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pbOpenGenFiles);


        verticalLayout_2->addLayout(horizontalLayout);

        tableWidget_required = new QTableWidget(layoutWidget);
        if (tableWidget_required->columnCount() < 2)
            tableWidget_required->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_required->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_required->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_required->setObjectName(QStringLiteral("tableWidget_required"));
        tableWidget_required->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(tableWidget_required);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        tableWidget_fields = new QTableWidget(layoutWidget1);
        if (tableWidget_fields->columnCount() < 3)
            tableWidget_fields->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_fields->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_fields->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_fields->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        tableWidget_fields->setObjectName(QStringLiteral("tableWidget_fields"));
        tableWidget_fields->setAutoFillBackground(false);
        tableWidget_fields->setGridStyle(Qt::SolidLine);
        tableWidget_fields->setColumnCount(3);
        tableWidget_fields->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget_fields->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        tableWidget_fields->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_3->addWidget(tableWidget_fields);

        splitter->addWidget(layoutWidget1);

        verticalLayout_4->addWidget(splitter);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        pbSaveChanges = new QPushButton(TabClassLayout);
        pbSaveChanges->setObjectName(QStringLiteral("pbSaveChanges"));
        pbSaveChanges->setEnabled(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, pbSaveChanges);

        pbDiscardChanges = new QPushButton(TabClassLayout);
        pbDiscardChanges->setObjectName(QStringLiteral("pbDiscardChanges"));
        pbDiscardChanges->setEnabled(false);
        sizePolicy.setHeightForWidth(pbDiscardChanges->sizePolicy().hasHeightForWidth());
        pbDiscardChanges->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, pbDiscardChanges);


        verticalLayout_4->addLayout(formLayout);


        retranslateUi(TabClassLayout);

        QMetaObject::connectSlotsByName(TabClassLayout);
    } // setupUi

    void retranslateUi(QWidget *TabClassLayout)
    {
        TabClassLayout->setWindowTitle(QApplication::translate("TabClassLayout", "Form", Q_NULLPTR));
        labelClassCreated->setText(QApplication::translate("TabClassLayout", "Notification!", Q_NULLPTR));
        label->setText(QApplication::translate("TabClassLayout", "Name:", Q_NULLPTR));
        pbDwnlFromFIle->setText(QApplication::translate("TabClassLayout", "Download from file", Q_NULLPTR));
        labelGenerated->setText(QApplication::translate("TabClassLayout", "Not generated", Q_NULLPTR));
        label_4->setText(QApplication::translate("TabClassLayout", "Namespaces (by comma):", Q_NULLPTR));
        label_2->setText(QApplication::translate("TabClassLayout", "Required classes:", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        pbOpenGenFiles->setToolTip(QApplication::translate("TabClassLayout", "Ctrl + Q", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pbOpenGenFiles->setText(QApplication::translate("TabClassLayout", "Open generated files", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_required->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("TabClassLayout", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_required->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("TabClassLayout", "Path to .jcd file", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tableWidget_required->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("TabClassLayout", "Properties:", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_fields->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("TabClassLayout", "Name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_fields->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("TabClassLayout", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_fields->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("TabClassLayout", "Is Collection", Q_NULLPTR));
        pbSaveChanges->setText(QApplication::translate("TabClassLayout", "Save changes", Q_NULLPTR));
        pbDiscardChanges->setText(QApplication::translate("TabClassLayout", "Discard Changes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TabClassLayout: public Ui_TabClassLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABCLASSLAYOUT_H
