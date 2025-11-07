#ifndef PAYMENTSTABLEFORM_H
#define PAYMENTSTABLEFORM_H

#include <QWidget>
#include <QSqlTableModel> //
#include <QSqlRecord>
#include <QSqlError>

#include <QDebug> // Инструмент для отладки
#include <QMessageBox> // Для показа сообщений об ошибках
#include <QCloseEvent> // Для создания окна с подтверждением выхода


namespace Ui {
class PaymentsTableForm;
}

class PaymentsTableForm : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentsTableForm(QWidget *parent = nullptr);
    ~PaymentsTableForm();

    static PaymentsTableForm *CreateWindow();
    void ShowForm();

    // Показывает текущую запись
    void ShowRecord(int row);



protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_PrevButton_clicked();

    void on_NextButton_clicked();

    void on_AddRowButton_clicked();

    void on_RemoveRowButton_clicked();

    void on_SaveRowButton_clicked();

private:
    Ui::PaymentsTableForm *ui;

    QSqlTableModel *model;

    static PaymentsTableForm *PaymentsForm;

    int currentRow;

};

#endif // PAYMENTSTABLEFORM_H
