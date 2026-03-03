#include "sqlform.h"
#include "ui_sqlform.h"
#include "View/exemplequery.h"
#include "fullselect.h"
#include "ncorrquery.h"
#include "changerecordtab.h"

SQLForm *SQLForm::Form = nullptr;

SQLForm::SQLForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SQLForm)
{
    ui->setupUi(this);

    // Убирает вкладки по умолчанию
    while (ui->tabWidget->count() > 0) {
        ui->tabWidget->removeTab(0);
    }

    // Вкладки
    ExempleQuery *firstTab = new ExempleQuery(this);
    FullSelect *secondTab = new FullSelect(this);
    NCorrQuery *thirdTab = new NCorrQuery(this);
    ChangeRecordTab *fourthTab = new ChangeRecordTab(this);


    ui->tabWidget->addTab(firstTab, "Примеры запросов");
    ui->tabWidget->addTab(secondTab, "Полная запись SELECT");
    ui->tabWidget->addTab(thirdTab, "Примеры Подзапросов");
    ui->tabWidget->addTab(fourthTab, "Запросы изменения данных");
    // ItemsTab *itemsTab = new ItemsTab(this);
    // CustomersTab *customersTab = new CustomersTab(this);

}

SQLForm::~SQLForm()
{
    delete ui;
    Form = nullptr;
}



// Открывает окно при нажатии на кнопку
SQLForm *SQLForm::CreateWindow()
{

    // Создаёт новое окно, если оно не открыто
    if (Form == nullptr){

        Form = new SQLForm();
    }
    return Form;

}

// "Активатор окна"
void SQLForm::ShowForm()
{
    // Показывает окно
    // если оно уже было открыто, ничего не делает
    this->show();
    // Поднимает его на передний план
    this->activateWindow();

}










