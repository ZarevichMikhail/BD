/********************************************************************************
** Form generated from reading UI file 'paymentstableform.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAYMENTSTABLEFORM_H
#define UI_PAYMENTSTABLEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaymentsTableForm
{
public:
    QPushButton *PrevButton;
    QPushButton *NextButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *ContractNumberTextBox;
    QLineEdit *WorkerIdTextBox;
    QLineEdit *ParentTextBox;
    QLineEdit *DepartmentTextBox;
    QLineEdit *ProfessionTextBox;
    QPushButton *AddRowButton;
    QPushButton *RemoveRowButton;
    QPushButton *SaveRowButton;

    void setupUi(QWidget *PaymentsTableForm)
    {
        if (PaymentsTableForm->objectName().isEmpty())
            PaymentsTableForm->setObjectName("PaymentsTableForm");
        PaymentsTableForm->resize(555, 406);
        PrevButton = new QPushButton(PaymentsTableForm);
        PrevButton->setObjectName("PrevButton");
        PrevButton->setGeometry(QRect(40, 40, 31, 26));
        NextButton = new QPushButton(PaymentsTableForm);
        NextButton->setObjectName("NextButton");
        NextButton->setGeometry(QRect(90, 40, 31, 26));
        label = new QLabel(PaymentsTableForm);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 90, 121, 18));
        label_2 = new QLabel(PaymentsTableForm);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 120, 111, 20));
        label_3 = new QLabel(PaymentsTableForm);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 150, 261, 18));
        label_4 = new QLabel(PaymentsTableForm);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(100, 180, 66, 18));
        label_5 = new QLabel(PaymentsTableForm);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 210, 191, 18));
        ContractNumberTextBox = new QLineEdit(PaymentsTableForm);
        ContractNumberTextBox->setObjectName("ContractNumberTextBox");
        ContractNumberTextBox->setGeometry(QRect(270, 90, 113, 26));
        WorkerIdTextBox = new QLineEdit(PaymentsTableForm);
        WorkerIdTextBox->setObjectName("WorkerIdTextBox");
        WorkerIdTextBox->setGeometry(QRect(270, 120, 113, 26));
        ParentTextBox = new QLineEdit(PaymentsTableForm);
        ParentTextBox->setObjectName("ParentTextBox");
        ParentTextBox->setGeometry(QRect(270, 150, 113, 26));
        DepartmentTextBox = new QLineEdit(PaymentsTableForm);
        DepartmentTextBox->setObjectName("DepartmentTextBox");
        DepartmentTextBox->setGeometry(QRect(270, 180, 113, 26));
        ProfessionTextBox = new QLineEdit(PaymentsTableForm);
        ProfessionTextBox->setObjectName("ProfessionTextBox");
        ProfessionTextBox->setGeometry(QRect(270, 210, 113, 26));
        AddRowButton = new QPushButton(PaymentsTableForm);
        AddRowButton->setObjectName("AddRowButton");
        AddRowButton->setGeometry(QRect(130, 40, 131, 26));
        RemoveRowButton = new QPushButton(PaymentsTableForm);
        RemoveRowButton->setObjectName("RemoveRowButton");
        RemoveRowButton->setGeometry(QRect(280, 40, 121, 26));
        SaveRowButton = new QPushButton(PaymentsTableForm);
        SaveRowButton->setObjectName("SaveRowButton");
        SaveRowButton->setGeometry(QRect(60, 280, 141, 26));

        retranslateUi(PaymentsTableForm);

        QMetaObject::connectSlotsByName(PaymentsTableForm);
    } // setupUi

    void retranslateUi(QWidget *PaymentsTableForm)
    {
        PaymentsTableForm->setWindowTitle(QCoreApplication::translate("PaymentsTableForm", "Form", nullptr));
        PrevButton->setText(QCoreApplication::translate("PaymentsTableForm", "<-", nullptr));
        NextButton->setText(QCoreApplication::translate("PaymentsTableForm", "->", nullptr));
        label->setText(QCoreApplication::translate("PaymentsTableForm", "\320\235\320\276\320\274\320\265\321\200 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260", nullptr));
        label_2->setText(QCoreApplication::translate("PaymentsTableForm", "\320\230\320\224 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("PaymentsTableForm", "\320\247\320\265\320\273\320\276\320\262\320\265\320\272, \320\272\320\276\321\202\320\276\321\200\321\213\320\271 \320\261\321\203\320\264\320\265\321\202 \320\276\320\277\320\273\320\260\321\207\320\270\320\262\320\260\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("PaymentsTableForm", "\320\232\320\260\321\204\320\265\320\264\321\200\320\260", nullptr));
        label_5->setText(QCoreApplication::translate("PaymentsTableForm", "\320\235\320\260\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\264\320\263\320\276\321\202\320\276\320\262\320\272\320\270", nullptr));
        AddRowButton->setText(QCoreApplication::translate("PaymentsTableForm", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        RemoveRowButton->setText(QCoreApplication::translate("PaymentsTableForm", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\321\200\320\276\320\272\321\203", nullptr));
        SaveRowButton->setText(QCoreApplication::translate("PaymentsTableForm", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaymentsTableForm: public Ui_PaymentsTableForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAYMENTSTABLEFORM_H
