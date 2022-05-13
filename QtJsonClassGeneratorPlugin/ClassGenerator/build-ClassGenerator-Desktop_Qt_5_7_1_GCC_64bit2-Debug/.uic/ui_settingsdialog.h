/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *General;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditSaveDirectory;
    QPushButton *pbChooseFolder;
    QWidget *Uncrustify;
    QFormLayout *formLayout_2;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBoxUncrustify;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEditUncrustifyCommand;
    QPushButton *pbChooseUncrustifyPath;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEditUncrustifyConfigFile;
    QPushButton *pbChooseUncrustifyConfig;
    QWidget *tab;
    QFormLayout *formLayout_3;
    QCheckBox *checkBoxLightGeneration;
    QPushButton *pbSaveSettings;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName(QStringLiteral("SettingsDialog"));
        SettingsDialog->resize(562, 412);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsDialog->sizePolicy().hasHeightForWidth());
        SettingsDialog->setSizePolicy(sizePolicy);
        SettingsDialog->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_4 = new QHBoxLayout(SettingsDialog);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(SettingsDialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        General = new QWidget();
        General->setObjectName(QStringLiteral("General"));
        formLayout = new QFormLayout(General);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(General);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEditSaveDirectory = new QLineEdit(General);
        lineEditSaveDirectory->setObjectName(QStringLiteral("lineEditSaveDirectory"));

        horizontalLayout->addWidget(lineEditSaveDirectory);

        pbChooseFolder = new QPushButton(General);
        pbChooseFolder->setObjectName(QStringLiteral("pbChooseFolder"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pbChooseFolder->sizePolicy().hasHeightForWidth());
        pbChooseFolder->setSizePolicy(sizePolicy1);
        pbChooseFolder->setMinimumSize(QSize(21, 25));
        pbChooseFolder->setMaximumSize(QSize(21, 25));
        pbChooseFolder->setIconSize(QSize(16, 16));
        pbChooseFolder->setAutoRepeat(false);

        horizontalLayout->addWidget(pbChooseFolder);


        verticalLayout_2->addLayout(horizontalLayout);


        formLayout->setLayout(0, QFormLayout::SpanningRole, verticalLayout_2);

        tabWidget->addTab(General, QString());
        Uncrustify = new QWidget();
        Uncrustify->setObjectName(QStringLiteral("Uncrustify"));
        formLayout_2 = new QFormLayout(Uncrustify);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        checkBoxUncrustify = new QCheckBox(Uncrustify);
        checkBoxUncrustify->setObjectName(QStringLiteral("checkBoxUncrustify"));

        verticalLayout_3->addWidget(checkBoxUncrustify);

        label_3 = new QLabel(Uncrustify);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEditUncrustifyCommand = new QLineEdit(Uncrustify);
        lineEditUncrustifyCommand->setObjectName(QStringLiteral("lineEditUncrustifyCommand"));

        horizontalLayout_3->addWidget(lineEditUncrustifyCommand);

        pbChooseUncrustifyPath = new QPushButton(Uncrustify);
        pbChooseUncrustifyPath->setObjectName(QStringLiteral("pbChooseUncrustifyPath"));
        sizePolicy1.setHeightForWidth(pbChooseUncrustifyPath->sizePolicy().hasHeightForWidth());
        pbChooseUncrustifyPath->setSizePolicy(sizePolicy1);
        pbChooseUncrustifyPath->setMinimumSize(QSize(21, 25));
        pbChooseUncrustifyPath->setMaximumSize(QSize(21, 25));
        pbChooseUncrustifyPath->setIconSize(QSize(16, 16));
        pbChooseUncrustifyPath->setAutoRepeat(false);

        horizontalLayout_3->addWidget(pbChooseUncrustifyPath);


        verticalLayout_3->addLayout(horizontalLayout_3);

        label_2 = new QLabel(Uncrustify);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEditUncrustifyConfigFile = new QLineEdit(Uncrustify);
        lineEditUncrustifyConfigFile->setObjectName(QStringLiteral("lineEditUncrustifyConfigFile"));

        horizontalLayout_2->addWidget(lineEditUncrustifyConfigFile);

        pbChooseUncrustifyConfig = new QPushButton(Uncrustify);
        pbChooseUncrustifyConfig->setObjectName(QStringLiteral("pbChooseUncrustifyConfig"));
        sizePolicy1.setHeightForWidth(pbChooseUncrustifyConfig->sizePolicy().hasHeightForWidth());
        pbChooseUncrustifyConfig->setSizePolicy(sizePolicy1);
        pbChooseUncrustifyConfig->setMinimumSize(QSize(21, 25));
        pbChooseUncrustifyConfig->setMaximumSize(QSize(21, 25));
        pbChooseUncrustifyConfig->setIconSize(QSize(16, 16));
        pbChooseUncrustifyConfig->setAutoRepeat(false);

        horizontalLayout_2->addWidget(pbChooseUncrustifyConfig);


        verticalLayout_3->addLayout(horizontalLayout_2);


        formLayout_2->setLayout(0, QFormLayout::SpanningRole, verticalLayout_3);

        tabWidget->addTab(Uncrustify, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        formLayout_3 = new QFormLayout(tab);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        checkBoxLightGeneration = new QCheckBox(tab);
        checkBoxLightGeneration->setObjectName(QStringLiteral("checkBoxLightGeneration"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, checkBoxLightGeneration);

        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        pbSaveSettings = new QPushButton(SettingsDialog);
        pbSaveSettings->setObjectName(QStringLiteral("pbSaveSettings"));
        sizePolicy1.setHeightForWidth(pbSaveSettings->sizePolicy().hasHeightForWidth());
        pbSaveSettings->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(pbSaveSettings);


        horizontalLayout_4->addLayout(verticalLayout);

        QWidget::setTabOrder(lineEditSaveDirectory, pbChooseFolder);
        QWidget::setTabOrder(pbChooseFolder, pbSaveSettings);

        retranslateUi(SettingsDialog);

        tabWidget->setCurrentIndex(0);
        pbChooseFolder->setDefault(false);
        pbChooseUncrustifyPath->setDefault(false);
        pbChooseUncrustifyConfig->setDefault(false);


        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QApplication::translate("SettingsDialog", "Settings", Q_NULLPTR));
        label->setText(QApplication::translate("SettingsDialog", "Directory for saving class files:", Q_NULLPTR));
        pbChooseFolder->setText(QApplication::translate("SettingsDialog", "...", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(General), QApplication::translate("SettingsDialog", "General", Q_NULLPTR));
        checkBoxUncrustify->setText(QApplication::translate("SettingsDialog", "Use Uncrustify", Q_NULLPTR));
        label_3->setText(QApplication::translate("SettingsDialog", "Command path:", Q_NULLPTR));
        lineEditUncrustifyCommand->setText(QApplication::translate("SettingsDialog", "/usr/bin/uncrustify", Q_NULLPTR));
        pbChooseUncrustifyPath->setText(QApplication::translate("SettingsDialog", "...", Q_NULLPTR));
        label_2->setText(QApplication::translate("SettingsDialog", "Config file:", Q_NULLPTR));
        pbChooseUncrustifyConfig->setText(QApplication::translate("SettingsDialog", "...", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Uncrustify), QApplication::translate("SettingsDialog", "Uncrustify", Q_NULLPTR));
        checkBoxLightGeneration->setText(QApplication::translate("SettingsDialog", "Use light generation", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SettingsDialog", "Generation", Q_NULLPTR));
        pbSaveSettings->setText(QApplication::translate("SettingsDialog", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
