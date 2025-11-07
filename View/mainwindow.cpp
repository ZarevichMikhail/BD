#include "View/mainwindow.h"
#include "./ui_mainwindow.h"
#include "View/posttableform.h"
#include "View/workerstableform.h"
#include "View/applicantstableform.h"
#include "View/paymentstableform.h"
#include "View/studentslistform.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Ручное подключение действия triggered к нажатию кнопки.
    // автоматически созданный слот почему-то у меня не работает.
    //connect(ui->action_Posts, &QAction::triggered, this, &MainWindow::on_action_Posts_triggered);


    // Подключение к базе данных
    // Имя "QPSQL" - это драйвер для PostgreSQL https://doc.qt.io/qt-6/sql-driver.html
    // Документация на QSqlDatabase https://doc.qt.io/qt-6/qsqldatabase.html
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");

    // Данные для подключюения
    db.setHostName("localhost");
    db.setDatabaseName("labdatabase");
    db.setUserName("mikhail");
    db.setPassword("mikhail");
    db.setPort(5432); // Стандартный порт PostgreSQL

    // Пытаемся открыть подключение
    if (!db.open()) {
        qDebug() << "Ошибка! Не удалось подключиться к базе данных.";
        qDebug() << db.lastError().text();

        // Выводим пользователю сообщение об ошибке
        QMessageBox::critical(this, "Ошибка",
                              "Не удалось подключиться к базе данных:\n" + db.lastError().text());
    } else {
        //qDebug() << "Подключение к БД успешно!";
    }


}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_action_Exit_triggered()
{
    qDebug() << "Точка останова в on_action_Exit_triggered";
    this->close(); // Команда, запускающая событие закрытия
    //PostTable::fw()->ShowForm();
}


// Обработчик события закрытия
// Вызывает диалоговое окно с подтверждением
void MainWindow::closeEvent(QCloseEvent *event)
{
    // Вызов диалогового окна.
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Внимание",
                                                               tr("Вы хотите закрыть программу?\n"),
                                                               QMessageBox::No | QMessageBox::Yes,
                                                               QMessageBox::Yes); // 'Yes' будет кнопкой по умолчанию

    if (resBtn != QMessageBox::Yes) {
        // Если No или закрытие диалоговоко окна
        event->ignore(); // Отмена события
    } else {
        event->accept(); //
    }
}


void MainWindow::on_action_Info_triggered()
{
    QMessageBox::information(this, "О программе", "(С) ТУСУР, КСУП, Заревич Михаил Антонович, 513-2, 2025");
}


void MainWindow::on_action_Posts_triggered()
{
    qDebug() << "Точка останова в on_action_Posts_triggered";

    PostTable::CreateWindow()->ShowForm();
}



void MainWindow::on_action_Workers_triggered()
{
    qDebug() << "Точка останова в on_action_Workers_triggered";
    WorkersTableForm::CreateWindow()->ShowForm();
}


void MainWindow::on_action_4_triggered()
{
    qDebug() << "Точка останова в on_action_4_triggered";
    ApplicantsTableForm::CreateWindow() ->ShowForm();
}




void MainWindow::on_action_Payments_triggered()
{
    PaymentsTableForm::CreateWindow()->ShowForm();
}



void MainWindow::on_action_StudentsList_triggered()
{
    StudentsListForm::CreateWindow()->ShowForm();
}




