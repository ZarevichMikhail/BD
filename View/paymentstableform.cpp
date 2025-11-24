#include "paymentstableform.h"
#include "ui_paymentstableform.h"


PaymentsTableForm *PaymentsTableForm::PaymentsForm= nullptr;

PaymentsTableForm::PaymentsTableForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PaymentsTableForm)
{
    ui->setupUi(this);



    // Получаем подключение к БД, которое мы уже открыли в mainwindow
    QSqlDatabase db = QSqlDatabase::database();

    // Создаем модель https://doc.qt.io/qt-6/qsqltablemodel.html
    model = new QSqlTableModel(this, db);

    // Указываем таблицу.
    // "public" - это схема в PostgreSQL, "Договоры" - имя таблицы.
    // Кавычки нужны, т.к. имя на русском
    model->setTable("public.\"Договоры\"");

    // Populates the model with data from the table that was set via setTable()
    model->select();

    // Настройка изменения данных в таблице
    // All changes will be cached in the model until either submitAll() or revertAll() is called
    model->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);



    currentRow = 0;
    ShowRecord(currentRow);

}



PaymentsTableForm::~PaymentsTableForm()
{
    PaymentsForm = nullptr;
    currentRow = 0;
    delete ui;
}


void PaymentsTableForm::ShowRecord(int row)
{
    QSqlRecord record = model->record(row);

    ui->ContractNumberTextBox->setText(record.value("Номер договора").toString());
    ui->WorkerIdTextBox->setText(record.value("ИД сотрудника").toString());
    ui->ParentTextBox->setText(record.value("Человек, который будет оплачивать").toString());
    ui->DepartmentTextBox->setText(record.value("Кафедра").toString());
    ui->ProfessionTextBox->setText(record.value("Направление подготовки").toString());


}

// Открывает окно при нажатии на кнопку
PaymentsTableForm *PaymentsTableForm::CreateWindow()
{

    // Создаёт новое окно, если оно не открыто
    if (PaymentsForm == nullptr){

        PaymentsForm = new PaymentsTableForm();
    }
    return PaymentsForm;

}

// "Активатор окна"
void PaymentsTableForm::ShowForm()
{
    // Показывает окно
    // если оно уже было открыто, ничего не делает
    this->show();
    // Поднимает его на передний план
    this->activateWindow();

}


void PaymentsTableForm::on_PrevButton_clicked()
{
    if (currentRow -1 >= 0) {
        currentRow--;
        ShowRecord(currentRow);
    }
}


void PaymentsTableForm::on_NextButton_clicked()
{
    if (currentRow + 1 <= model->rowCount()) {
        currentRow++;
        ShowRecord(currentRow);
    }
}


void PaymentsTableForm::on_AddRowButton_clicked()
{
    model->insertRow(model->rowCount());
    currentRow = model->rowCount();
    ShowRecord(model->rowCount());
}


void PaymentsTableForm::on_RemoveRowButton_clicked()
{
    // Получаем индекс текущей выделенной ячейки
    //int currentRow = currentRow;

    // Проверяем, что какая-то строка выбрана
    if (currentRow >= 0) {
        // Говорим модели удалить эту строку
        model->removeRow(currentRow);
        currentRow--;
    }

    // if (currentRow - 1 < model->rowCount()) {
    //     ShowRecord(currentRow - 1);
    // }
    if (currentRow > 0) {
        currentRow--;
    }

    ShowRecord(currentRow);

}

// Событие закрытия формы
// При закрытии отправляет все изменения в таблицу
void PaymentsTableForm::closeEvent(QCloseEvent *event)
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

void PaymentsTableForm::on_SaveRowButton_clicked()
{

    QSqlRecord record = model->record(currentRow);

    // Обновляет данные новой строки
    // record.value("ИД сотрудника").toString() = ui->WorkerIdTextBox->text();
    // record.value("Человек, который будет оплачивать").toString() = ui->WorkerIdTextBox->text();
    // record.value("Кафедра").toString() = ui->DepartmentTextBox->text();
    // record.value("Направление подготовки").toString() = ui->ProfessionTextBox->text();

    // 2. Устанавливаем новые значения В ОБЪЕКТ record
    //    Используем setValue()
    //    ВНИМАНИЕ: Нужно преобразовывать типы! "ИД сотрудника" - это число.
    record.setValue("ИД сотрудника", ui->WorkerIdTextBox->text().toInt());

    // У вас здесь была ошибка: вы снова брали текст из WorkerIdTextBox
    record.setValue("Человек, который будет оплачивать", ui->ParentTextBox->text());

    record.setValue("Кафедра", ui->DepartmentTextBox->text());
    record.setValue("Направление подготовки", ui->ProfessionTextBox->text());

    // 3. УСТАНАВЛИВАЕМ ИЗМЕНЕННУЮ ЗАПИСЬ ОБРАТНО В МОДЕЛЬ
    //    Это самый важный шаг, который вы пропустили.
    model->setRecord(currentRow, record);

    if (model->submitAll()) {

        QMessageBox::information(this, "Информация","Данные сохранены.");

    }
    // Если введены неправильные данные
    else {
        QMessageBox::critical(this, "Ошибка",
                              "Не удалось сохранить изменения в БД:\n" + model->lastError().text());

        // Отменяет изменения
        model->revertAll();
    }

    // ui->WorkerIdTextBox->setText(record.value("ИД сотрудника").toString());
    // ui->ParentTextBox->setText(record.value("Человек, который будет оплачивать").toString());
    // ui->DepartmentTextBox->setText(record.value("Кафедра").toString());
    // ui->ProfessionTextBox->setText(record.value("Направление подготовки").toString());
}

