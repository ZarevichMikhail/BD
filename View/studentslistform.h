#ifndef STUDENTSLISTFORM_H
#define STUDENTSLISTFORM_H

#include <QWidget>
#include <QSqlError>


#include <QCloseEvent> // Для создания окна с подтверждением выхода
#include <QDebug>      // Инструмент для отладки
#include <QMessageBox> // Для показа сообщений об ошибках



// Для создания выпадающего списка
// Замена QSqlTableModel
#include <QSqlRelationalTableModel>
#include <QSqlRelation>
#include <QSqlRelationalDelegate> // Это тоже важно!




namespace Ui {
class StudentsListForm;
}

class StudentsListForm : public QWidget
{
    Q_OBJECT

public:
    explicit StudentsListForm(QWidget *parent = nullptr);
    ~StudentsListForm();

    static StudentsListForm *CreateWindow();
    void ShowForm();




private slots:
    void on_AddRowButton_clicked();

    void on_DeleteRowButton_clicked();







protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::StudentsListForm *ui;

    //QSqlTableModel *model;

    QSqlRelationalTableModel *model;
    QSqlTableModel *detailModel;


    static StudentsListForm *StudentsForm;


};

#endif // STUDENTSLISTFORM_H
