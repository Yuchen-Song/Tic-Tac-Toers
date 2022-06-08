/********************************************************************************
** Form generated from reading UI file 'gamescence3.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESCENCE3_H
#define UI_GAMESCENCE3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gameScence3
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gameScence3)
    {
        if (gameScence3->objectName().isEmpty())
            gameScence3->setObjectName(QString::fromUtf8("gameScence3"));
        gameScence3->resize(800, 600);
        menubar = new QMenuBar(gameScence3);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        gameScence3->setMenuBar(menubar);
        centralwidget = new QWidget(gameScence3);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gameScence3->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(gameScence3);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        gameScence3->setStatusBar(statusbar);

        retranslateUi(gameScence3);

        QMetaObject::connectSlotsByName(gameScence3);
    } // setupUi

    void retranslateUi(QMainWindow *gameScence3)
    {
        gameScence3->setWindowTitle(QCoreApplication::translate("gameScence3", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class gameScence3: public Ui_gameScence3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESCENCE3_H
