#ifndef SQLFORM_H
#define SQLFORM_H

#include <QWidget>

namespace Ui {
class SQLForm;
}

class SQLForm : public QWidget
{
    Q_OBJECT

public:
    explicit SQLForm(QWidget *parent = nullptr);
    ~SQLForm();


    static SQLForm *CreateWindow();
    void ShowForm();

private:
    Ui::SQLForm *ui;

    static SQLForm *Form;
};

#endif // SQLFORM_H
