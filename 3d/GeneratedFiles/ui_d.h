/********************************************************************************
** Form generated from reading UI file 'd.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_D_H
#define UI_D_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dClass)
    {
        if (dClass->objectName().isEmpty())
            dClass->setObjectName(QStringLiteral("dClass"));
        dClass->resize(600, 400);
        menuBar = new QMenuBar(dClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        dClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        dClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(dClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        dClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(dClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        dClass->setStatusBar(statusBar);

        retranslateUi(dClass);

        QMetaObject::connectSlotsByName(dClass);
    } // setupUi

    void retranslateUi(QMainWindow *dClass)
    {
        dClass->setWindowTitle(QApplication::translate("dClass", "d", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dClass: public Ui_dClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_D_H
