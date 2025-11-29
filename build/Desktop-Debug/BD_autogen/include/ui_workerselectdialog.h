/********************************************************************************
** Form generated from reading UI file 'workerselectdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERSELECTDIALOG_H
#define UI_WORKERSELECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_WorkerSelectDialog
{
public:
    QTableView *tableView;
    QPushButton *CanceButton;
    QPushButton *SelectButton;

    void setupUi(QDialog *WorkerSelectDialog)
    {
        if (WorkerSelectDialog->objectName().isEmpty())
            WorkerSelectDialog->setObjectName("WorkerSelectDialog");
        WorkerSelectDialog->resize(864, 318);
        tableView = new QTableView(WorkerSelectDialog);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 60, 641, 191));
        CanceButton = new QPushButton(WorkerSelectDialog);
        CanceButton->setObjectName("CanceButton");
        CanceButton->setGeometry(QRect(130, 20, 88, 26));
        SelectButton = new QPushButton(WorkerSelectDialog);
        SelectButton->setObjectName("SelectButton");
        SelectButton->setGeometry(QRect(30, 20, 88, 26));

        retranslateUi(WorkerSelectDialog);

        QMetaObject::connectSlotsByName(WorkerSelectDialog);
    } // setupUi

    void retranslateUi(QDialog *WorkerSelectDialog)
    {
        WorkerSelectDialog->setWindowTitle(QCoreApplication::translate("WorkerSelectDialog", "Dialog", nullptr));
        CanceButton->setText(QCoreApplication::translate("WorkerSelectDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        SelectButton->setText(QCoreApplication::translate("WorkerSelectDialog", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkerSelectDialog: public Ui_WorkerSelectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERSELECTDIALOG_H
