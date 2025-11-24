#include "posttableform.h"
#include "ui_posttableform.h"
#include <QDebug>
#include <QSqlRecord>
#include <QSqlField> // Для работы с полями таблицы
                     // Нужно, чтобы преобразовать int в qstring


#include "View/workerstableform.h"


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


    // --- 3. СВЯЗЫВАЕМ МАСТЕР И ДЕТАЛЬ (ИСПРАВЛЕННАЯ ВЕРСИЯ) ---
    // Соединяем сигнал о смене ТЕКУЩЕЙ СТРОКИ в masterView...
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
            this, &PostTable::updateDetailView); // <--- ...с нашим новым слотом


    //detailModel = new QSqlTableModel(this,db);
    detailModel = new QSqlTableModel(this, db);
    detailModel->setTable("public.\"Сотрудники\"");
    detailModel->select();
    ui->workersTable->setModel(detailModel);






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

    //WorkersTableForm::selectedPostId = 1;

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



// --- 5. РЕАЛИЗУЕМ СЛОТ, КОТОРЫЙ ФИЛЬТРУЕТ ДЕТАЛИ ---
// (Имя функции и параметры теперь совпадают с тем, что в .h)
void PostTable::updateDetailView(const QModelIndex &current, const QModelIndex &previous)
{
    // (Параметр 'previous' нам не нужен, но мы должны его принять)
    Q_UNUSED(previous); // Говорим компилятору, что мы знаем, что не используем 'previous'

    if (!current.isValid()) {
        detailModel->setFilter("1 = 0"); // Если не выбрана ни одна строка мастера, прячем все детали
        detailModel->select();
        ui->workersTable->setModel(detailModel);
        return;
    }

    // 1. Получаем ИД должности из мастер-таблицы
    int idColumnIndex = model->fieldIndex("ИД должности");
    int currentPostId = model->data(model->index(current.row(), idColumnIndex)).toInt();

    // 2. Фильтруем деталь-таблицу
    QString filter = QString("\"Должность\" = %1").arg(currentPostId);
    detailModel->setFilter(filter);

    // 3. Перезагружаем Деталь-модель
    detailModel->select();

}



void PostTable::on_SearchButton_clicked()
{

    // Проверка на то, выбрана ли колонка
    // Текущая выбранная колонка
    int currentColumn = ui->tableView->currentIndex().column();

    if (currentColumn < 0) {
        QMessageBox::warning(this, "Внимание", "Сначала выберите колонку (кликните на ячейку в нужном столбце).");
        return;
    }

    // Текст для поиска
    QString searchText = ui->SearchTextBox->text();
    if (searchText.isEmpty()) {
        // Сброс фильтров, если нет текста
        model->setFilter("");
        model->select();
        return;
    }

    // Имя поля в таблице и его тип
    QString fieldName = model->record().fieldName(currentColumn);
    int columnType = model->record().field(currentColumn).metaType().id();

    QString filter;

    // --- ВЕТВЛЕНИЕ: ФИЛЬТР ИЛИ ПОИСК? ---

    if (ui->FilterCheckBox->isChecked()) {
        // ==========================
        // РЕЖИМ 1: ФИЛЬТРАЦИЯ (Скрываем всё, что не подходит)
        // ==========================

        QString filter;

        // Если это число, превращаем его в текст для поиска (CAST)
        if (columnType == QMetaType::Int || columnType == QMetaType::LongLong ||
            columnType == QMetaType::Double || columnType == QMetaType::UInt)
        {
            filter = QString("CAST(\"%1\" AS TEXT) ILIKE '%%2%'").arg(fieldName).arg(searchText);
        }
        else
        {
            // Если это текст
            filter = QString("\"%1\" ILIKE '%%2%'").arg(fieldName).arg(searchText);
        }

        // Применяем SQL-фильтр. В таблице останутся только подходящие строки.
        model->setFilter(filter);
        model->select();
    }
    else {
        // ==========================
        // РЕЖИМ 2: ПОИСК (Ищем и выделяем, не скрывая)
        // ==========================

        // 1. Сначала ОБЯЗАТЕЛЬНО сбрасываем старый фильтр, чтобы искать по всей базе
        model->setFilter("");
        model->select();

        // 2. Ищем в загруженной модели
        // model->index(0, currentColumn) - начинаем поиск с первой строки в выбранном столбце
        QModelIndexList matches = model->match(
            model->index(0, currentColumn),
            Qt::DisplayRole,                // Ищем то, что отображается (текст)
            searchText,                     // Что ищем
            1,                              // Нам нужно только 1-е совпадение
            Qt::MatchContains | Qt::MatchWrap // Искать часть слова | Искать по кругу
            );

        if (!matches.isEmpty()) {
            // Если нашли:
            QModelIndex foundIndex = matches.first();

            // Выделяем эту ячейку
            ui->tableView->setCurrentIndex(foundIndex);
            // Прокручиваем таблицу к ней
            ui->tableView->scrollTo(foundIndex);
            // Передаем фокус таблице, чтобы выделение стало синим/активным
            ui->tableView->setFocus();
        } else {
            QMessageBox::information(this, "Поиск", "Совпадений не найдено.");
        }
    }


}


void PostTable::on_ResetSearchButton_clicked()
{
    ui->SearchTextBox->clear(); // Очищаем поле ввода
    ui->FilterCheckBox->setChecked(false); // Снимаем галочку

    model->setFilter(""); // Убираем SQL-фильтр
    model->select();      // Обновляем данные
}


void PostTable::on_SelectPostButton_clicked()
{

    // Проверка на то, выбрана ли колонка
    // Текущая выбранная колонка
    //WorkersTableForm::CreateWindow();
    //int workerColumn = WorkersTableForm::ui->WorkersTableView->currentIndex().column();
    //WorkersTableForm::selectedPostId = ui->tableView->currentIndex().row();


    // 1. Получаем индекс выбранной строки в таблице должностей
    int currentRow = ui->tableView->currentIndex().row();

    if (currentRow < 0) {
        QMessageBox::warning(this, "Внимание", "Сначала выберите должность в таблице!");
        return;
    }

    // 2. Вытаскиваем реальный ID должности из модели
    // Важно брать именно ID из базы, а не номер строки!
    int idColumnIndex = model->fieldIndex("ИД должности");
    int postId = model->record(currentRow).value("ИД должности").toInt();

    // 3. Отправляем сигнал ("Я выбрал ID такой-то!")
    emit postSelected(postId);

    // 4. Закрываем окно выбора, так как работа сделана
    this->close();






}

