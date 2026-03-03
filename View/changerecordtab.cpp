#include "changerecordtab.h"
#include "ui_changerecordtab.h"

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>

#include <QDebug>

ChangeRecordTab::ChangeRecordTab(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChangeRecordTab)
{
    ui->setupUi(this);
}

ChangeRecordTab::~ChangeRecordTab()
{
    delete ui;
}

void ChangeRecordTab::on_CreateQueryButton_clicked()
{


    QString SqlQuery = "";


    if(ui->AddWorkerRadioButton->isChecked()){


        SqlQuery = "INSERT INTO public.\"Сотрудники\" "
                        "(\"ФИО\", \"Должность\", \"Серия паспорта\", \"Номер паспорта\", \"Факультет\", \"Количество отработанных часов\") "
                   "VALUES (:name, :post, :series, :number, :faculty, :hours)";
    }

    else if(ui->ChangeWorkerDataRadioButton->isChecked()){

        SqlQuery ="UPDATE public.\"Сотрудники\" "

                    "SET "
                        "\"ФИО\" = :name, "
                        "\"Серия паспорта\" = :series, "
                        "\"Номер паспорта\" = :number, "
                        "\"Факультет\" = :faculty, "
                        "\"Должность\" = :post, "
                        "\"Количество отработанных часов\" = :hours "

                    "WHERE \"ИД сотрудника\" = :id";

        qDebug() << SqlQuery;

        }
    else if(ui->DeleteWorkerRadioButton->isChecked()){

        SqlQuery = "DELETE FROM public.\"Сотрудники\" "
                       "WHERE \"ИД сотрудника\" = :id";
        qDebug() << SqlQuery;
    }


    QSqlQuery query;
    query.prepare(SqlQuery);

    query.bindValue(":name", ui->NameTextBox->text());
    query.bindValue(":post", ui->PostTextBox->text());
    query.bindValue(":series", ui->SeriesTextBox->text());
    query.bindValue(":number", ui->NumberTextBox->text());
    query.bindValue(":faculty", ui->FacultyTextBox->text());
    query.bindValue(":hours", ui->HoursTextBox->text());
    query.bindValue(":id", ui->IdTextBox->text());


    if (!query.exec()) {
        QMessageBox::critical(this, "Неправильный запрос", query.lastError().text());
        return;
    }


    // QSqlQueryModel *model = new QSqlQueryModel(this);
    // model->setQuery(std::move(query));


    // ui->tableView->setModel(model);
    // ui->tableView->resizeColumnsToContents();


    // if (model->rowCount() == 0) {
    //     QMessageBox::information(this, "Информация", "Нет значений!");
    // }




}

