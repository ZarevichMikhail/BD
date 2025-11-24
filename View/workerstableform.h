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




#include "View/posttableform.h"


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

    Ui::PostTable *PostTableUi;

    static int selectedPostId;





protected:
    void closeEvent(QCloseEvent *event);



private slots:
    void on_AddRowButton_clicked();

    void on_DeleteRowButton_clicked();

    void updateDetailView(const QModelIndex &current, const QModelIndex &previous);

    void on_SearchButton_clicked();

    void on_ResetButton_clicked();

    void on_ChangePostButton_clicked();


    // Новый слот, который сработает, когда должность выбрана
    void onPostSelected(int postId);









private:
    Ui::WorkersTableForm *ui;

    //QSqlTableModel *model;
    QSqlRelationalTableModel *model;

    QSqlTableModel *ApplicantsDetailModel;
    QSqlTableModel *PaymentsDetailModel;
    QSqlTableModel *StudentsDetailModel;

    static WorkersTableForm *WorkersForm;
};

#endif // WORKERSTABLEFORM_H
