#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent> // Для создания окна с подтверждением выхода

// Подключение библиотек для работы с базой данных
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    void closeEvent(QCloseEvent *event) override;

private slots:

    void on_action_Exit_triggered();

    void on_action_Info_triggered();

    void on_action_Posts_triggered();

    void on_action_Workers_triggered();

    void on_action_4_triggered();

    void on_action_StudentsList_triggered();



    void on_action_Payments_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
