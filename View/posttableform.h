#ifndef POSTTABLEFORM_H
#define POSTTABLEFORM_H

#include <QWidget>
#include <QSqlTableModel> //
#include <QSqlError>

#include <QDebug> // Инструмент для отладки
#include <QMessageBox> // Для показа сообщений об ошибках
#include <QCloseEvent> // Для создания окна с подтверждением выхода


namespace Ui {
class PostTable;
}

class PostTable : public QWidget
{
    Q_OBJECT

public:
    explicit PostTable(QWidget *parent = nullptr);
    ~PostTable();


    // Функция, создающая окно
    static PostTable *CreateWindow();
    // Функция, показывающая окно
    void ShowForm();


protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_AddRowButton_clicked();

    void on_DeleteButton_clicked();

private:
    Ui::PostTable *ui;

    QSqlTableModel *model;

    static PostTable *PostForm;
};

#endif // POSTTABLEFORM_H
