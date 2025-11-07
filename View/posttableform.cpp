#include "posttableform.h"
#include "ui_posttableform.h"


PostTable *PostTable::PostForm = nullptr;


PostTable::PostTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PostTable)
{
    ui->setupUi(this);

    // Получаем подключение к БД, которое мы уже открыли в mainwindow
    QSqlDatabase db = QSqlDatabase::database();

    // Создаем модель https://doc.qt.io/qt-6/qsqltablemodel.html
    model = new QSqlTableModel(this, db);

    // Указываем таблицу.
    // "public" - это схема в PostgreSQL, "Должности" - имя таблицы.
    // Кавычки нужны, т.к. имя на русском
    model->setTable("public.\"Должности\"");

    // Populates the model with data from the table that was set via setTable()
    model->select();

    // Настройка изменения данных в таблице
    // All changes will be cached in the model until either submitAll() or revertAll() is called
    model->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);


    // Устанавливаем модель для нашего QTableView
    // 'tableView' - это objectName, который Qt Designer дал виджету.
    // Проверь в .ui, что он называется именно так.
    ui->tableView->setModel(model);
}

PostTable::~PostTable()
{
    // Сбрасывание f в null при закрытии формы.
    PostForm = nullptr;
    delete ui;
}


// Открывает окно при нажатии на кнопку
PostTable *PostTable::CreateWindow()
{

    // Создаёт новое окно, если оно не открыто
    if (PostForm == nullptr){

        PostForm = new PostTable();
    }
    return PostForm;

}

// "Активатор окна"
void PostTable::ShowForm()
{
    // Показывает окно
    // если оно уже было открыто, ничего не делает
    this->show();
    // Поднимает его на передний план
    this->activateWindow();

}

// Событие закрытия формы
// При закрытии отправляет все изменения в таблицу
void PostTable::closeEvent(QCloseEvent *event)
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



void PostTable::on_AddRowButton_clicked()
{

    model->insertRow(model->rowCount());
}


void PostTable::on_DeleteButton_clicked()
{
    // Получаем индекс текущей выделенной ячейки
    int currentRow = ui->tableView->currentIndex().row();

    // Проверяем, что какая-то строка выбрана
    if (currentRow >= 0) {
        // Говорим модели удалить эту строку
        model->removeRow(currentRow);
    }

}

