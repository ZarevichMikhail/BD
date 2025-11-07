/********************************************************************************
** Form generated from reading UI file 'applicantstableform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPLICANTSTABLEFORM_H
#define UI_APPLICANTSTABLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ApplicantsTableForm
{
public:
    QPushButton *AddRowButton;
    QPushButton *DeleteRowButton;
    QTableView *ApplicantsTableView;

    void setupUi(QWidget *ApplicantsTableForm)
    {
        if (ApplicantsTableForm->objectName().isEmpty())
            ApplicantsTableForm->setObjectName("ApplicantsTableForm");
        ApplicantsTableForm->resize(957, 501);
        AddRowButton = new QPushButton(ApplicantsTableForm);
        AddRowButton->setObjectName("AddRowButton");
        AddRowButton->setGeometry(QRect(30, 30, 121, 26));
        DeleteRowButton = new QPushButton(ApplicantsTableForm);
        DeleteRowButton->setObjectName("DeleteRowButton");
        DeleteRowButton->setGeometry(QRect(170, 30, 111, 26));
        ApplicantsTableView = new QTableView(ApplicantsTableForm);
        ApplicantsTableView->setObjectName("ApplicantsTableView");
        ApplicantsTableView->setGeometry(QRect(10, 70, 941, 231));

        retranslateUi(ApplicantsTableForm);

        QMetaObject::connectSlotsByName(ApplicantsTableForm);
    } // setupUi

    void retranslateUi(QWidget *ApplicantsTableForm)
    {
        ApplicantsTableForm->setWindowTitle(QCoreApplication::translate("ApplicantsTableForm", "Form", nullptr));
        AddRowButton->setText(QCoreApplication::translate("ApplicantsTableForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        DeleteRowButton->setText(QCoreApplication::translate("ApplicantsTableForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ApplicantsTableForm: public Ui_ApplicantsTableForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPLICANTSTABLEFORM_H
