#ifndef WORKERSTABLEFORM_H
#define WORKERSTABLEFORM_H

#include <QWidget>

#include <QSqlError>
#include <QSqlTableModel> // Это наш аналог TableAdapter + DataSet

#include <QCloseEvent> // Для создания окна с подтверждением выхода
#include <QDebug>      // Инструмент для отладки
#include <QMessageBox> // Для показа сообщений об ошибках




// Для создания выпадающего списка
// Замена QSqlTableModel
#include <QSqlRelationalTableModel>
#include <QSqlRelation>
#include <QSqlRelationalDelegate> // Это тоже важно!



namespace Ui {
class WorkersTableForm;
}

class WorkersTableForm : public QWidget
{
    Q_OBJECT

public:
    explicit WorkersTableForm(QWidget *parent = nullptr);
    ~WorkersTableForm();

    static WorkersTableForm *CreateWindow();
    void ShowForm();



protected:
    void closeEvent(QCloseEvent *event);



private slots:
    void on_AddRowButton_clicked();

    void on_DeleteRowButton_clicked();




private:
    Ui::WorkersTableForm *ui;

    //QSqlTableModel *model;
    QSqlRelationalTableModel *model;

    static WorkersTableForm *WorkersForm;
};

#endif // WORKERSTABLEFORM_H
