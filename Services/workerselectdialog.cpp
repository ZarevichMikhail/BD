#include "workerselectdialog.h"
#include "ui_workerselectdialog.h"


WorkerSelectDialog::WorkerSelectDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WorkerSelectDialog)
{
    ui->setupUi(this);

    // Подключаем модель (как обычно)
    QSqlDatabase db = QSqlDatabase::database();
    model = new QSqlTableModel(this, db);
    model->setTable("public.\"Сотрудники\"");
    model->select();

    ui->tableView->setModel(model);
    // Скрываем ID, если хотим, оставляем только название и оклад
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);



}

WorkerSelectDialog::~WorkerSelectDialog()
{
    delete ui;
}



int WorkerSelectDialog::getSelectedId() const { return selectedId; }
QString WorkerSelectDialog::getSelectedName() const { return selectedName; }


void WorkerSelectDialog::on_SelectButton_clicked()
{
    // Получаем текущую строку
        int row = ui->tableView->currentIndex().row();
    if (row < 0) return;


    selectedId = model->record(row).value("ИД сотрудника").toInt();
    selectedName = model->record(row).value("ФИО").toString();

    accept(); // Закрываем диалог с результатом QDialog::Accepted
}


void WorkerSelectDialog::on_CanceButton_clicked()
{
    reject(); // Закрываем диалог с результатом QDialog::Rejected
}

