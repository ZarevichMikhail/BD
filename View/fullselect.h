#ifndef FULLSELECT_H
#define FULLSELECT_H

#include <QWidget>

namespace Ui {
class FullSelect;
}

class FullSelect : public QWidget
{
    Q_OBJECT

public:
    explicit FullSelect(QWidget *parent = nullptr);
    ~FullSelect();

    static FullSelect *CreateWindow();
    void ShowForm();

private slots:
    void on_CreateQueryButton_clicked();

private:
    Ui::FullSelect *ui;

    static FullSelect *Form;
};

#endif // FULLSELECT_H
