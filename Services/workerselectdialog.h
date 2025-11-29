#ifndef WORKERSELECTDIALOG_H
#define WORKERSELECTDIALOG_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>

namespace Ui {
class WorkerSelectDialog;
}

class WorkerSelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WorkerSelectDialog(QWidget *parent = nullptr);
    ~WorkerSelectDialog();

    // Метод, чтобы забрать результат (Название и ID)
    QString getSelectedName() const;
    int getSelectedId() const;

private slots:

    void on_SelectButton_clicked();

    void on_CanceButton_clicked();

private:
    Ui::WorkerSelectDialog *ui;

    QSqlTableModel *model;
    int selectedId = -1;
    QString selectedName;
};

#endif // WORKERSELECTDIALOG_H
