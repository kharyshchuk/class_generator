/********************************************************************************
** Form generated from reading UI file 'generatedclasscontentdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEDCLASSCONTENTDIALOG_H
#define UI_GENERATEDCLASSCONTENTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_GeneratedClassContentDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *GeneratedClassContentDialog)
    {
        if (GeneratedClassContentDialog->objectName().isEmpty())
            GeneratedClassContentDialog->setObjectName(QStringLiteral("GeneratedClassContentDialog"));
        GeneratedClassContentDialog->resize(617, 725);
        horizontalLayout = new QHBoxLayout(GeneratedClassContentDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        textBrowser = new QTextBrowser(GeneratedClassContentDialog);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        horizontalLayout->addWidget(textBrowser);


        retranslateUi(GeneratedClassContentDialog);

        QMetaObject::connectSlotsByName(GeneratedClassContentDialog);
    } // setupUi

    void retranslateUi(QDialog *GeneratedClassContentDialog)
    {
        GeneratedClassContentDialog->setWindowTitle(QApplication::translate("GeneratedClassContentDialog", "Dialog", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        textBrowser->setToolTip(QApplication::translate("GeneratedClassContentDialog", "push Ctrl + W show next class file", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class GeneratedClassContentDialog: public Ui_GeneratedClassContentDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEDCLASSCONTENTDIALOG_H
