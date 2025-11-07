/********************************************************************************
** Form generated from reading UI file 'studentslistform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTSLISTFORM_H
#define UI_STUDENTSLISTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentsListForm
{
public:
    QTableView *tableView;
    QPushButton *AddRowButton;
    QPushButton *DeleteRowButton;

    void setupUi(QWidget *StudentsListForm)
    {
        if (StudentsListForm->objectName().isEmpty())
            StudentsListForm->setObjectName("StudentsListForm");
        StudentsListForm->resize(703, 450);
        tableView = new QTableView(StudentsListForm);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 70, 551, 261));
        AddRowButton = new QPushButton(StudentsListForm);
        AddRowButton->setObjectName("AddRowButton");
        AddRowButton->setGeometry(QRect(20, 20, 131, 26));
        DeleteRowButton = new QPushButton(StudentsListForm);
        DeleteRowButton->setObjectName("DeleteRowButton");
        DeleteRowButton->setGeometry(QRect(160, 20, 121, 26));

        retranslateUi(StudentsListForm);

        QMetaObject::connectSlotsByName(StudentsListForm);
    } // setupUi

    void retranslateUi(QWidget *StudentsListForm)
    {
        StudentsListForm->setWindowTitle(QCoreApplication::translate("StudentsListForm", "Form", nullptr));
        AddRowButton->setText(QCoreApplication::translate("StudentsListForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        DeleteRowButton->setText(QCoreApplication::translate("StudentsListForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentsListForm: public Ui_StudentsListForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTSLISTFORM_H
