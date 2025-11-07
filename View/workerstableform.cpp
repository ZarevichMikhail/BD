#include "workerstableform.h"
#include "ui_workerstableform.h"
#include "facultydelegate.h"

WorkersTableForm *WorkersTableForm::WorkersForm = nullptr;


WorkersTableForm::WorkersTableForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WorkersTableForm)
{
    ui->setupUi(this);

    // Получаем подключение к БД, которое мы уже открыли в mainwindow
    QSqlDatabase db = QSqlDatabase::database();

    // Создаем модель https://doc.qt.io/qt-6/qsqltablemodel.html
    //model = new QSqlTableModel(this, db);
    model = new QSqlRelationalTableModel(this, db);


    // Указываем таблицу.
    // "public" - это схема в PostgreSQL, "Должности" - имя таблицы.
    // Кавычки нужны, т.к. имя на русском
    model->setTable("public.\"Сотрудники\"");


    // 4. ОПИШИТЕ СВЯЗЬ (САМЫЙ ВАЖНЫЙ ШАГ!)
    // Нам нужно найти индекс столбца "ИД_должности"
    int positionColumnIndex = model->fieldIndex("Должность");


    // Теперь "объясняем" модели, что это за связь
    model->setRelation(positionColumnIndex,
                       QSqlRelation("public.\"Должности\"",     // Родительская таблица
                                    "\"ИД должности\"",         // Ее первичный ключ
                                    "\"Название должности\"")); // Столбец, который мы хотим ПОКАЗЫВАТЬ


    // Populates the model with data from the table that was set via setTable()
    model->select();

    // Настройка изменения данных в таблице
    // All changes will be cached in the model until either submitAll() or revertAll() is called
    //model->setEditStrategy(QSqlTableModel::EditStrategy::OnManualSubmit);
    model->setEditStrategy(QSqlRelationalTableModel::EditStrategy::OnManualSubmit);


    // Устанавливаем модель для нашего QTableView
    // 'tableView' - это objectName, который Qt Designer дал виджету.
    // Проверь в .ui, что он называется именно так.
    //ui->WorkersTableView->setModel(model);

    // 7. СКАЖИТЕ VIEW ИСПОЛЬЗОВАТЬ СПЕЦИАЛЬНЫЙ ДЕЛЕГАТ
    // Эта строка автоматически создаст ComboBox'ы там, где нужно
    ui->WorkersTableView->setItemDelegate(new QSqlRelationalDelegate(ui->WorkersTableView));




    // Устанавливаем модель для нашего QTableView
    // 'tableView' - это objectName, который Qt Designer дал виджету.
    // Проверь в .ui, что он называется именно так.
    ui->WorkersTableView->setModel(model);

    FacultyDelegate *delegate = new FacultyDelegate(this);


    // 3. Найдите номер нужного столбца (например, "Факультет")
    int facultyColumn = -1;
    for (int i = 0; i < model->columnCount(); ++i) {
        if (model->headerData(i, Qt::Horizontal).toString() == "Факультет") {
            facultyColumn = i;
            break;
        }
    }

    // 4. Установите делегат для этого столбца
    if (facultyColumn != -1) {
        ui->WorkersTableView->setItemDelegateForColumn(facultyColumn, delegate);
    }






}

WorkersTableForm::~WorkersTableForm()
{
    WorkersForm = nullptr;
    delete ui;
}



// Открывает окно при нажатии на кнопку
WorkersTableForm *WorkersTableForm::CreateWindow()
{

    // Создаёт новое окно, если оно не открыто
    if (WorkersForm == nullptr){

        WorkersForm = new WorkersTableForm();
    }
    return WorkersForm;

}

// "Активатор окна"
void WorkersTableForm::ShowForm()
{
    // Показывает окно
    // если оно уже было открыто, ничего не делает
    this->show();
    // Поднимает его на передний план
    this->activateWindow();

}





// Событие закрытия формы
// При закрытии отправляет все изменения в таблицу
void WorkersTableForm::closeEvent(QCloseEvent *event)
{
    // https://doc.qt.io/qt-6/qsqltablemodel.html#submitAll
    // Submits all pending changes and returns true on success. Returns false on error, detailed error information can be obtained with lastError().
    if (model->submitAll()) {
        event->accept();
    }
    // Если введены неправильные данные
    else {
        QMessageBox::critical(this,
                              "Ошибка",
                              "Не удалось сохранить изменения в БД:\n" + model->lastError().text());
        event->ignore();
        // Отменяет изменения
        model->revertAll();
    }
}

void WorkersTableForm::on_AddRowButton_clicked()
{
    model->insertRow(model->rowCount());
}


void WorkersTableForm::on_DeleteRowButton_clicked()
{
    // Получаем индекс текущей выделенной ячейки
    int currentRow = ui->WorkersTableView->currentIndex().row();

    // Проверяем, что какая-то строка выбрана
    if (currentRow >= 0) {
        // Говорим модели удалить эту строку
        model->removeRow(currentRow);
    }
}

