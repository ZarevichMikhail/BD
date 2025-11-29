/********************************************************************************
** Form generated from reading UI file 'workerselectfdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERSELECTFDIALOG_H
#define UI_WORKERSELECTFDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_WorkerSelectFDialog
{
public:
    QTableView *tableView;
    QPushButton *CancelButton;

    void setupUi(QDialog *WorkerSelectFDialog)
    {
        if (WorkerSelectFDialog->objectName().isEmpty())
            WorkerSelectFDialog->setObjectName("WorkerSelectFDialog");
        WorkerSelectFDialog->resize(566, 414);
        tableView = new QTableView(WorkerSelectFDialog);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 70, 511, 291));
        CancelButton = new QPushButton(WorkerSelectFDialog);
        CancelButton->setObjectName("CancelButton");
        CancelButton->setGeometry(QRect(40, 20, 121, 26));

        retranslateUi(WorkerSelectFDialog);

        QMetaObject::connectSlotsByName(WorkerSelectFDialog);
    } // setupUi

    void retranslateUi(QDialog *WorkerSelectFDialog)
    {
        WorkerSelectFDialog->setWindowTitle(QCoreApplication::translate("WorkerSelectFDialog", "Dialog", nullptr));
        CancelButton->setText(QCoreApplication::translate("WorkerSelectFDialog", "\320\236\321\202\320\274\320\265\320\275\320\260 \320\262\321\213\320\261\320\276\321\200\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkerSelectFDialog: public Ui_WorkerSelectFDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERSELECTFDIALOG_H
