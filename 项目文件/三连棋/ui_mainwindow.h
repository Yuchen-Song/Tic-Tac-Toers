/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <mypushbutton1.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    mypushbutton1 *Combtn;
    QSpacerItem *verticalSpacer;
    mypushbutton1 *Startbtn;
    mypushbutton1 *chessB;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    mypushbutton1 *Exitbtn;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(320, 180, 271, 271));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Combtn = new mypushbutton1(widget);
        Combtn->setObjectName(QString::fromUtf8("Combtn"));

        gridLayout->addWidget(Combtn, 2, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        Startbtn = new mypushbutton1(widget);
        Startbtn->setObjectName(QString::fromUtf8("Startbtn"));

        gridLayout->addWidget(Startbtn, 0, 1, 1, 1);

        chessB = new mypushbutton1(widget);
        chessB->setObjectName(QString::fromUtf8("chessB"));

        gridLayout->addWidget(chessB, 4, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 1, 1, 1);

        Exitbtn = new mypushbutton1(widget);
        Exitbtn->setObjectName(QString::fromUtf8("Exitbtn"));

        gridLayout->addWidget(Exitbtn, 6, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 5, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Combtn->setText(QCoreApplication::translate("MainWindow", "man vs com", nullptr));
        Startbtn->setText(QCoreApplication::translate("MainWindow", "start the game", nullptr));
        chessB->setText(QCoreApplication::translate("MainWindow", "ChessBoard B", nullptr));
        Exitbtn->setText(QCoreApplication::translate("MainWindow", "exit the game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
