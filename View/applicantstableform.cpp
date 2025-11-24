#include "applicantstableform.h"
#include "ui_applicantstableform.h"
#include "facultydelegate.h"


ApplicantsTableForm *ApplicantsTableForm::ApplicantsForm= nullptr;


ApplicantsTableForm::ApplicantsTableForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ApplicantsTableForm)
{
    ui->setupUi(this);


    // Получаем подключение к БД, которое мы уже открыли в mainwindow
    QSqlDatabase db = QSqlDatabase::database();

    // Создаем модель https://doc.qt.io/qt-6/qsqltablemodel.html
    model = new QSqlTableModel(this, db);

    // Указываем таблицу.
    // "public" - это схема в PostgreSQL, "Должности" - имя таблицы.
    // Кавычки нужны, т.к. имя на русском
    model->setTable("public.\"Абитуриенты\"");
    //model->setTable("public.\"V_Абитуриенты_Конкусный_балл\""); // СТАЛО
    // Populates the model with data from the table that was set via setTable()
    model->select();

    // Настройка изменения данных в таблице
    // All changes will be cached in the model until either submitAll() or revertAll() is called
    model->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);

    ui->ApplicantsTableView->setModel(model);

}

ApplicantsTableForm::~ApplicantsTableForm()
{
    ApplicantsForm = nullptr;
    delete ui;
}


// Открывает окно при нажатии на кнопку
    ApplicantsTableForm *ApplicantsTableForm::CreateWindow()
{

    // Создаёт новое окно, если оно не открыто
    if (ApplicantsForm == nullptr){

        ApplicantsForm = new ApplicantsTableForm();
    }
    return ApplicantsForm;

}

// "Активатор окна"
void ApplicantsTableForm::ShowForm()
{
    // Показывает окно
    // если оно уже было открыто, ничего не делает
    this->show();
    // Поднимает его на передний план
    this->activateWindow();

}

// Событие закрытия формы
// При закрытии отправляет все изменения в таблицу
void ApplicantsTableForm::closeEvent(QCloseEvent *event)
{
    // https://doc.qt.io/qt-6/qsqltablemodel.html#submitAll
    // Submits all pending changes and returns true on success. Returns false on error, detailed error information can be obtained with lastError().
    if (model->submitAll()) {
        event->accept();
    }
    // Если введены неправильные данные
    else {
        QMessageBox::critical(this, "Ошибка",
                              "Не удалось сохранить изменения в БД:\n" + model->lastError().text());
        event->ignore();
        // Отменяет изменения
        model->revertAll();
    }
}


void ApplicantsTableForm::on_AddRowButton_clicked()
{
    model->insertRow(model->rowCount());
}


void ApplicantsTableForm::on_DeleteRowButton_clicked()
{
    // Получаем индекс текущей выделенной ячейки
    int currentRow = ui->ApplicantsTableView->currentIndex().row();

    // Проверяем, что какая-то строка выбрана
    if (currentRow >= 0) {
        // Говорим модели удалить эту строку
        model->removeRow(currentRow);
    }
}

