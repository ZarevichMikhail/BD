#include "workerstableform.h"
#include "ui_workerstableform.h"
#include "facultydelegate.h"

#include <QSqlRecord>
#include <QSqlField> // Для работы с полями таблицы
    // Нужно, чтобы преобразовать int в qstring


#include "View/posttableform.h"

WorkersTableForm *WorkersTableForm::WorkersForm = nullptr;
int WorkersTableForm::selectedPostId = 0;


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
    ApplicantsDetailModel = new QSqlRelationalTableModel(this, db);


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


    // --- 3. СВЯЗЫВАЕМ МАСТЕР И ДЕТАЛЬ (ИСПРАВЛЕННАЯ ВЕРСИЯ) ---
    // Соединяем сигнал о смене ТЕКУЩЕЙ СТРОКИ в masterView...
    connect(ui->WorkersTableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
            this, &WorkersTableForm::updateDetailView);


    //detailModel = new QSqlTableModel(this,db);
    ApplicantsDetailModel = new QSqlTableModel(this, db);
    ApplicantsDetailModel->setTable("public.\"Абитуриенты\"");
    ApplicantsDetailModel->select();
    ui->StudentsTableView->setModel(ApplicantsDetailModel);




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



// --- 5. РЕАЛИЗУЕМ СЛОТ, КОТОРЫЙ ФИЛЬТРУЕТ ДЕТАЛИ ---
// (Имя функции и параметры теперь совпадают с тем, что в .h)
void WorkersTableForm::updateDetailView(const QModelIndex &current, const QModelIndex &previous)
{
    // (Параметр 'previous' нам не нужен, но мы должны его принять)
    Q_UNUSED(previous); // Говорим компилятору, что мы знаем, что не используем 'previous'

    if (!current.isValid()) {
        ApplicantsDetailModel->setFilter("1 = 0"); // Если не выбрана ни одна строка мастера, прячем все детали
        ApplicantsDetailModel->select();
        ui->WorkersTableView->setModel(ApplicantsDetailModel);
        return;
    }

    // 1. Получаем ИД должности из мастер-таблицы
    int idColumnIndex = model->fieldIndex("ИД сотрудника");
    int currentPostId = model->data(model->index(current.row(), idColumnIndex)).toInt();

    // 2. Фильтруем деталь-таблицу
    QString filter = QString("\"ИД сотрудника\" = %1").arg(currentPostId);
    ApplicantsDetailModel->setFilter(filter);

    // 3. Перезагружаем Деталь-модель
    ApplicantsDetailModel->select();

}






void WorkersTableForm::on_SearchButton_clicked()
{
    // Проверка на то, выбрана ли колонка
    // Текущая выбранная колонка
    int currentColumn = ui->WorkersTableView->currentIndex().column();

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
            ui->WorkersTableView->setCurrentIndex(foundIndex);
            // Прокручиваем таблицу к ней
            ui->WorkersTableView->scrollTo(foundIndex);
            // Передаем фокус таблице, чтобы выделение стало синим/активным
            ui->WorkersTableView->setFocus();
        } else {
            QMessageBox::information(this, "Поиск", "Совпадений не найдено.");
        }
    }
}


void WorkersTableForm::on_ResetButton_clicked()
{

    ui->SearchTextBox->clear(); // Очищаем поле ввода
    ui->FilterCheckBox->setChecked(false); // Снимаем галочку

    model->setFilter(""); // Убираем SQL-фильтр
    model->select();      // Обновляем данные
}



void WorkersTableForm::on_ChangePostButton_clicked()
{

    //PostTable::CreateWindow()->ShowForm();

    //PostTable::PostForm->ui->SearchButton->setText("text");


    // 1. Создаем/получаем окно должностей
    PostTable *postWindow = PostTable::CreateWindow();

    // 2. ВАЖНО: Отключаем старые соединения, чтобы сигнал не сработал 2 раза,
    // если мы открываем окно повторно
    disconnect(postWindow, &PostTable::postSelected, this, &WorkersTableForm::onPostSelected);

    // 3. Подключаем сигнал из окна должностей к слоту в окне сотрудников
    connect(postWindow, &PostTable::postSelected, this, &WorkersTableForm::onPostSelected);

    // 4. Показываем окно
    postWindow->ShowForm();

}



void WorkersTableForm::onPostSelected(int postId)
{

    // 1. Узнаем, какой сотрудник сейчас выбран
    int currentWorkerRow = ui->WorkersTableView->currentIndex().row();
    if (currentWorkerRow < 0) {
        QMessageBox::warning(this, "Ошибка", "Не выбран сотрудник!");
        return;
    }

    // 2. Находим индекс колонки с внешним ключом
    // ВАЖНО: Имя здесь должно ТОЧНО совпадать с именем поля в БД (в create table).
    // Если вы создавали поле как "Должность", пишите "Должность".
    // Если как "ИД_должности", пишите "ИД_должности".
    int postColumnIndex = model->fieldIndex("Название должности");

    // ПРОВЕРКА: Нашли ли мы колонку?
    if (postColumnIndex == -1) {
        QMessageBox::critical(this, "Ошибка кода",
                              "Не найдена колонка 'Должность'. Проверьте имя поля в fieldIndex!");
        return;
    }

    // 3. Устанавливаем данные и проверяем, приняла ли их модель
    QModelIndex index = model->index(currentWorkerRow, postColumnIndex);
    if (!model->setData(index, postId)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось установить значение в ячейку (setData вернул false).");
        return;
    }

    // 4. Сохраняем в базу данных
    if (model->submitAll()) {
        // !!! КРИТИЧЕСКИ ВАЖНЫЙ МОМЕНТ ДЛЯ РЕЛЯЦИОННОЙ МОДЕЛИ !!!
        // Мы изменили ID (число), но таблица показывает Название (текст).
        // Нам нужно перезагрузить модель, чтобы она сходила в базу
        // и подтянула новое Название должности для нового ID.
        model->select();

        // Восстанавливаем выделение на той же строке (для удобства)
        ui->WorkersTableView->selectRow(currentWorkerRow);

        QMessageBox::information(this, "Успех", "Должность успешно изменена!");
    } else {
        QMessageBox::critical(this, "Ошибка БД",
                              "Не удалось сохранить: " + model->lastError().text());
        model->revertAll();
    }



    // // 1. Узнаем, какой сотрудник сейчас выбран в таблице сотрудников
    // int currentWorkerRow = ui->WorkersTableView->currentIndex().row();

    // if (currentWorkerRow < 0) {
    //     QMessageBox::warning(this, "Ошибка", "Не выбран сотрудник для изменения!");
    //     return;
    // }

    // // 2. Находим колонку "Должность" (или "ИД_должности") в модели сотрудников
    // // (Убедитесь, что имя поля совпадает с тем, что в БД)
    // int postColumnIndex = model->fieldIndex("Должность");

    // // 3. Устанавливаем новое значение ID должности в модель
    // model->setData(model->index(currentWorkerRow, postColumnIndex), postId);

    // // 4. Сохраняем изменения в базу (если стратегия OnManualSubmit)
    // if (model->submitAll()) {
    //     QMessageBox::information(this, "Успех", "Должность успешно изменена!");
    // } else {
    //     QMessageBox::critical(this, "Ошибка", "Не удалось сохранить: " + model->lastError().text());
    //     model->revertAll();
    // }
}
