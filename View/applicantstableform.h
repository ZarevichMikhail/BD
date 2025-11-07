#ifndef APPLICANTSTABLEFORM_H
#define APPLICANTSTABLEFORM_H

#include <QWidget>
#include <QSqlTableModel> //
#include <QSqlError>

#include <QDebug> // Инструмент для отладки
#include <QMessageBox> // Для показа сообщений об ошибках
#include <QCloseEvent> // Для создания окна с подтверждением выхода

namespace Ui {
class ApplicantsTableForm;
}

class ApplicantsTableForm : public QWidget
{
    Q_OBJECT

public:
    explicit ApplicantsTableForm(QWidget *parent = nullptr);
    ~ApplicantsTableForm();

    static ApplicantsTableForm *CreateWindow();
    void ShowForm();


protected:
    void closeEvent(QCloseEvent *event);


private slots:
    void on_AddRowButton_clicked();

    void on_DeleteRowButton_clicked();

private:
    Ui::ApplicantsTableForm *ui;

    QSqlTableModel *model;
    static ApplicantsTableForm *ApplicantsForm;



};

#endif // APPLICANTSTABLEFORM_H
