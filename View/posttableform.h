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

    Ui::PostTable *ui;
    Ui::PostTable *PostTableUi;

    static PostTable *PostForm;




protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_AddRowButton_clicked();

    void on_DeleteButton_clicked();

    // Мой слот для 3 лабы
    // Он будет принимать два индекса:
    // 'current' (новая выбранная строка) и 'previous' (старая)
    void updateDetailView(const QModelIndex &current, const QModelIndex &previous);


    void on_SearchButton_clicked();

    void on_ResetSearchButton_clicked();

    void on_SelectPostButton_clicked();

private:


    QSqlTableModel *model;

    QSqlTableModel *detailModel;



signals:
    // Сигнал, который будет отправляться при выборе должности
    // Хранит ID новой должности
    void postSelected(int postId);




};

#endif // POSTTABLEFORM_H
