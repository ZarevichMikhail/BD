/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Exit;
    QAction *action_Posts;
    QAction *action_Workers;
    QAction *action_4;
    QAction *action_Payments;
    QAction *action_StudentsList;
    QAction *action_Info;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        action_Exit = new QAction(MainWindow);
        action_Exit->setObjectName("action_Exit");
        action_Exit->setCheckable(false);
        action_Posts = new QAction(MainWindow);
        action_Posts->setObjectName("action_Posts");
        action_Workers = new QAction(MainWindow);
        action_Workers->setObjectName("action_Workers");
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        action_Payments = new QAction(MainWindow);
        action_Payments->setObjectName("action_Payments");
        action_StudentsList = new QAction(MainWindow);
        action_StudentsList->setObjectName("action_StudentsList");
        action_Info = new QAction(MainWindow);
        action_Info->setObjectName("action_Info");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action_Exit);
        menu->addAction(action_Info);
        menu_2->addAction(action_Posts);
        menu_2->addAction(action_Workers);
        menu_2->addAction(action_4);
        menu_2->addAction(action_Payments);
        menu_2->addAction(action_StudentsList);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "labdatabase", nullptr));
        action_Exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        action_Posts->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        action_Workers->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\270", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\220\320\261\320\270\321\202\321\203\321\200\320\270\320\265\320\275\321\202\321\213", nullptr));
        action_Payments->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\263\320\276\320\262\320\276\321\200\321\213", nullptr));
        action_StudentsList->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\272\320\260\320\267\321\213", nullptr));
        action_Info->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\276\321\207\320\275\320\270\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
