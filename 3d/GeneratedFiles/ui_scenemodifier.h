/********************************************************************************
** Form generated from reading UI file 'scenemodifier.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENEMODIFIER_H
#define UI_SCENEMODIFIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *dClass)
    {
        if (dClass->objectName().isEmpty())
            dClass->setObjectName(QStringLiteral("dClass"));
        dClass->resize(600, 400);
        centralWidget = new QWidget(dClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(470, 200, 131, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        dClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(dClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        dClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(dClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        dClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(dClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        dClass->setStatusBar(statusBar);

        retranslateUi(dClass);

        QMetaObject::connectSlotsByName(dClass);
    } // setupUi

    void retranslateUi(QMainWindow *dClass)
    {
        dClass->setWindowTitle(QApplication::translate("dClass", "d", nullptr));
        pushButton->setText(QApplication::translate("dClass", "down", nullptr));
        pushButton_2->setText(QApplication::translate("dClass", "left", nullptr));
        pushButton_3->setText(QApplication::translate("dClass", "up", nullptr));
        pushButton_4->setText(QApplication::translate("dClass", "right", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dClass: public Ui_dClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEMODIFIER_H
