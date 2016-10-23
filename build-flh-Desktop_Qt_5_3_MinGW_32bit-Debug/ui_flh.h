/********************************************************************************
** Form generated from reading UI file 'flh.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLH_H
#define UI_FLH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_flh
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *flh)
    {
        if (flh->objectName().isEmpty())
            flh->setObjectName(QStringLiteral("flh"));
        flh->resize(400, 300);
        menuBar = new QMenuBar(flh);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        flh->setMenuBar(menuBar);
        mainToolBar = new QToolBar(flh);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        flh->addToolBar(mainToolBar);
        centralWidget = new QWidget(flh);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        flh->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(flh);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        flh->setStatusBar(statusBar);

        retranslateUi(flh);

        QMetaObject::connectSlotsByName(flh);
    } // setupUi

    void retranslateUi(QMainWindow *flh)
    {
        flh->setWindowTitle(QApplication::translate("flh", "flh", 0));
    } // retranslateUi

};

namespace Ui {
    class flh: public Ui_flh {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLH_H
