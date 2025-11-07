/********************************************************************************
** Form generated from reading UI file 'workerstableform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKERSTABLEFORM_H
#define UI_WORKERSTABLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkersTableForm
{
public:
    QTableView *WorkersTableView;
    QPushButton *AddRowButton;
    QPushButton *DeleteRowButton;

    void setupUi(QWidget *WorkersTableForm)
    {
        if (WorkersTableForm->objectName().isEmpty())
            WorkersTableForm->setObjectName("WorkersTableForm");
        WorkersTableForm->resize(755, 428);
        WorkersTableView = new QTableView(WorkersTableForm);
        WorkersTableView->setObjectName("WorkersTableView");
        WorkersTableView->setGeometry(QRect(20, 60, 721, 301));
        AddRowButton = new QPushButton(WorkersTableForm);
        AddRowButton->setObjectName("AddRowButton");
        AddRowButton->setGeometry(QRect(30, 20, 121, 26));
        DeleteRowButton = new QPushButton(WorkersTableForm);
        DeleteRowButton->setObjectName("DeleteRowButton");
        DeleteRowButton->setGeometry(QRect(170, 20, 111, 26));

        retranslateUi(WorkersTableForm);

        QMetaObject::connectSlotsByName(WorkersTableForm);
    } // setupUi

    void retranslateUi(QWidget *WorkersTableForm)
    {
        WorkersTableForm->setWindowTitle(QCoreApplication::translate("WorkersTableForm", "Form", nullptr));
        AddRowButton->setText(QCoreApplication::translate("WorkersTableForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        DeleteRowButton->setText(QCoreApplication::translate("WorkersTableForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkersTableForm: public Ui_WorkersTableForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERSTABLEFORM_H
