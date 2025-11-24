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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QTableView *workersTable;
    QLabel *label;
    QLineEdit *SearchTextBox;
    QPushButton *SearchButton;
    QCheckBox *FilterCheckBox;
    QPushButton *ResetSearchButton;
    QPushButton *SelectPostButton;

    void setupUi(QWidget *PostTable)
    {
        if (PostTable->objectName().isEmpty())
            PostTable->setObjectName("PostTable");
        PostTable->resize(751, 539);
        tableView = new QTableView(PostTable);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 120, 541, 191));
        AddRowButton = new QPushButton(PostTable);
        AddRowButton->setObjectName("AddRowButton");
        AddRowButton->setGeometry(QRect(20, 30, 121, 26));
        DeleteButton = new QPushButton(PostTable);
        DeleteButton->setObjectName("DeleteButton");
        DeleteButton->setGeometry(QRect(150, 30, 121, 26));
        workersTable = new QTableView(PostTable);
        workersTable->setObjectName("workersTable");
        workersTable->setGeometry(QRect(10, 330, 561, 211));
        label = new QLabel(PostTable);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 80, 51, 16));
        SearchTextBox = new QLineEdit(PostTable);
        SearchTextBox->setObjectName("SearchTextBox");
        SearchTextBox->setGeometry(QRect(90, 70, 171, 26));
        SearchButton = new QPushButton(PostTable);
        SearchButton->setObjectName("SearchButton");
        SearchButton->setGeometry(QRect(270, 70, 88, 26));
        FilterCheckBox = new QCheckBox(PostTable);
        FilterCheckBox->setObjectName("FilterCheckBox");
        FilterCheckBox->setGeometry(QRect(300, 30, 92, 24));
        ResetSearchButton = new QPushButton(PostTable);
        ResetSearchButton->setObjectName("ResetSearchButton");
        ResetSearchButton->setGeometry(QRect(360, 70, 88, 26));
        SelectPostButton = new QPushButton(PostTable);
        SelectPostButton->setObjectName("SelectPostButton");
        SelectPostButton->setGeometry(QRect(400, 30, 151, 26));

        retranslateUi(PostTable);

        QMetaObject::connectSlotsByName(PostTable);
    } // setupUi

    void retranslateUi(QWidget *PostTable)
    {
        PostTable->setWindowTitle(QCoreApplication::translate("PostTable", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\320\270", nullptr));
        AddRowButton->setText(QCoreApplication::translate("PostTable", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        DeleteButton->setText(QCoreApplication::translate("PostTable", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        label->setText(QCoreApplication::translate("PostTable", "\320\237\320\276\320\270\321\201\320\272: ", nullptr));
        SearchButton->setText(QCoreApplication::translate("PostTable", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        FilterCheckBox->setText(QCoreApplication::translate("PostTable", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        ResetSearchButton->setText(QCoreApplication::translate("PostTable", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        SelectPostButton->setText(QCoreApplication::translate("PostTable", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PostTable: public Ui_PostTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTTABLEFORM_H
