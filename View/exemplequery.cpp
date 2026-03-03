#include "exemplequery.h"
#include "ui_exemplequery.h"

#include <QWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>

#include <QDebug>


ExempleQuery::ExempleQuery(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ExempleQuery)
{
    ui->setupUi(this);
}

ExempleQuery::~ExempleQuery()
{
    delete ui;
}

void ExempleQuery::on_CreateQueryButton_clicked()
{


    QString SqlQuery = "";

    if(ui->PostsRadioButton->isChecked()){

        SqlQuery = "SELECT "
                        "\"ИД должности\" AS PostID, "
                        "\"Название должности\" AS PostName, "
                        "\"Оклад\" AS Salary "
                   "FROM public.\"Должности\"";

    }
    else if(ui->WorkersRadioButton->isChecked()){

        SqlQuery = "SELECT "
                        "\"ИД сотрудника\", "
                        "\"Должность\" AS Post, "
                        "\"Факультет\", "
                        "\"Количество отработанных часов\" "
                    "FROM public.\"Сотрудники\" "
                    "WHERE "
                        "\"Количество отработанных часов\" > 1";

    }
    else if(ui->ApplicantsRadioButton->isChecked()){

        SqlQuery = "SELECT "
                        "* "
                   "FROM public.\"Абитуриенты\" ";

    }



    QSqlQuery query;
    query.prepare(SqlQuery);


    qDebug() << SqlQuery;


    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка SQL", query.lastError().text());
        return;
    }

    // Отображение в TableView
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();



}

