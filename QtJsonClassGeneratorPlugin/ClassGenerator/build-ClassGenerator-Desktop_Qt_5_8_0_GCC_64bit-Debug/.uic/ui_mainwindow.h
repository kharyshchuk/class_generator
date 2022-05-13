/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QPushButton *pbSettings;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pbDwnlScriptFiles;
    QPushButton *pbGenerateAllClasses;
    QPushButton *pbSaveAllClassFiles;
    QTabWidget *tabWidgetClasses;
    QPushButton *pbAddClass;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(655, 557);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        pbSettings = new QPushButton(centralWidget);
        pbSettings->setObjectName(QStringLiteral("pbSettings"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pbSettings->sizePolicy().hasHeightForWidth());
        pbSettings->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/settingicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pbSettings->setIcon(icon);

        verticalLayout_2->addWidget(pbSettings);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pbDwnlScriptFiles = new QPushButton(centralWidget);
        pbDwnlScriptFiles->setObjectName(QStringLiteral("pbDwnlScriptFiles"));

        horizontalLayout->addWidget(pbDwnlScriptFiles);

        pbGenerateAllClasses = new QPushButton(centralWidget);
        pbGenerateAllClasses->setObjectName(QStringLiteral("pbGenerateAllClasses"));
        pbGenerateAllClasses->setEnabled(false);

        horizontalLayout->addWidget(pbGenerateAllClasses);

        pbSaveAllClassFiles = new QPushButton(centralWidget);
        pbSaveAllClassFiles->setObjectName(QStringLiteral("pbSaveAllClassFiles"));
        pbSaveAllClassFiles->setEnabled(false);

        horizontalLayout->addWidget(pbSaveAllClassFiles);


        verticalLayout->addLayout(horizontalLayout);

        tabWidgetClasses = new QTabWidget(centralWidget);
        tabWidgetClasses->setObjectName(QStringLiteral("tabWidgetClasses"));
        tabWidgetClasses->setFocusPolicy(Qt::WheelFocus);
        tabWidgetClasses->setTabsClosable(true);
        tabWidgetClasses->setMovable(true);

        verticalLayout->addWidget(tabWidgetClasses);

        pbAddClass = new QPushButton(centralWidget);
        pbAddClass->setObjectName(QStringLiteral("pbAddClass"));

        verticalLayout->addWidget(pbAddClass);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 655, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QFont font1;
        font1.setItalic(false);
        mainToolBar->setFont(font1);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidgetClasses->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Json Class Generator", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Notification!", Q_NULLPTR));
        pbSettings->setText(QString());
        pbDwnlScriptFiles->setText(QApplication::translate("MainWindow", "Dowload script files", Q_NULLPTR));
        pbGenerateAllClasses->setText(QApplication::translate("MainWindow", "Generate classes", Q_NULLPTR));
        pbSaveAllClassFiles->setText(QApplication::translate("MainWindow", "Save generated class files", Q_NULLPTR));
        pbAddClass->setText(QApplication::translate("MainWindow", "Add new class", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
