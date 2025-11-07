/********************************************************************************
** Form generated from reading UI file 'posttableform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTTABLEFORM_H
#define UI_POSTTABLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PostTable
{
public:
    QTableView *tableView;
    QPushButton *AddRowButton;
    QPushButton *DeleteButton;

    void setupUi(QWidget *PostTable)
    {
        if (PostTable->objectName().isEmpty())
            PostTable->setObjectName("PostTable");
        PostTable->resize(595, 364);
        tableView = new QTableView(PostTable);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 80, 461, 221));
        AddRowButton = new QPushButton(PostTable);
        AddRowButton->setObjectName("AddRowButton");
        AddRowButton->setGeometry(QRect(20, 30, 121, 26));
        DeleteButton = new QPushButton(PostTable);
        DeleteButton->setObjectName("DeleteButton");
        DeleteButton->setGeometry(QRect(150, 30, 121, 26));

        retranslateUi(PostTable);

        QMetaObject::connectSlotsByName(PostTable);
    } // setupUi

    void retranslateUi(QWidget *PostTable)
    {
        PostTable->setWindowTitle(QCoreApplication::translate("PostTable", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        AddRowButton->setText(QCoreApplication::translate("PostTable", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        DeleteButton->setText(QCoreApplication::translate("PostTable", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PostTable: public Ui_PostTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTTABLEFORM_H
