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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QTableView *StudentsTableView;
    QLabel *label;
    QLineEdit *SearchTextBox;
    QPushButton *SearchButton;
    QPushButton *ResetButton;
    QCheckBox *FilterCheckBox;
    QPushButton *ChangePostButton;

    void setupUi(QWidget *WorkersTableForm)
    {
        if (WorkersTableForm->objectName().isEmpty())
            WorkersTableForm->setObjectName("WorkersTableForm");
        WorkersTableForm->resize(1075, 637);
        WorkersTableView = new QTableView(WorkersTableForm);
        WorkersTableView->setObjectName("WorkersTableView");
        WorkersTableView->setGeometry(QRect(20, 120, 731, 211));
        AddRowButton = new QPushButton(WorkersTableForm);
        AddRowButton->setObjectName("AddRowButton");
        AddRowButton->setGeometry(QRect(30, 20, 121, 26));
        DeleteRowButton = new QPushButton(WorkersTableForm);
        DeleteRowButton->setObjectName("DeleteRowButton");
        DeleteRowButton->setGeometry(QRect(170, 20, 111, 26));
        StudentsTableView = new QTableView(WorkersTableForm);
        StudentsTableView->setObjectName("StudentsTableView");
        StudentsTableView->setGeometry(QRect(20, 350, 731, 192));
        label = new QLabel(WorkersTableForm);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 80, 51, 18));
        SearchTextBox = new QLineEdit(WorkersTableForm);
        SearchTextBox->setObjectName("SearchTextBox");
        SearchTextBox->setGeometry(QRect(90, 80, 161, 26));
        SearchButton = new QPushButton(WorkersTableForm);
        SearchButton->setObjectName("SearchButton");
        SearchButton->setGeometry(QRect(260, 80, 88, 26));
        ResetButton = new QPushButton(WorkersTableForm);
        ResetButton->setObjectName("ResetButton");
        ResetButton->setGeometry(QRect(370, 80, 88, 26));
        FilterCheckBox = new QCheckBox(WorkersTableForm);
        FilterCheckBox->setObjectName("FilterCheckBox");
        FilterCheckBox->setGeometry(QRect(310, 30, 92, 24));
        ChangePostButton = new QPushButton(WorkersTableForm);
        ChangePostButton->setObjectName("ChangePostButton");
        ChangePostButton->setGeometry(QRect(390, 30, 161, 26));

        retranslateUi(WorkersTableForm);

        QMetaObject::connectSlotsByName(WorkersTableForm);
    } // setupUi

    void retranslateUi(QWidget *WorkersTableForm)
    {
        WorkersTableForm->setWindowTitle(QCoreApplication::translate("WorkersTableForm", "Form", nullptr));
        AddRowButton->setText(QCoreApplication::translate("WorkersTableForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        DeleteRowButton->setText(QCoreApplication::translate("WorkersTableForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        label->setText(QCoreApplication::translate("WorkersTableForm", "\320\237\320\276\320\270\321\201\320\272:", nullptr));
        SearchButton->setText(QCoreApplication::translate("WorkersTableForm", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        ResetButton->setText(QCoreApplication::translate("WorkersTableForm", "\320\241\320\261\321\200\320\276\321\201", nullptr));
        FilterCheckBox->setText(QCoreApplication::translate("WorkersTableForm", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        ChangePostButton->setText(QCoreApplication::translate("WorkersTableForm", "\320\237\320\276\320\274\320\265\320\275\321\217\321\202\321\214 \320\264\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkersTableForm: public Ui_WorkersTableForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKERSTABLEFORM_H
