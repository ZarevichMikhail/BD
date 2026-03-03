#ifndef CHANGERECORDTAB_H
#define CHANGERECORDTAB_H

#include <QWidget>

namespace Ui {
class ChangeRecordTab;
}

class ChangeRecordTab : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeRecordTab(QWidget *parent = nullptr);
    ~ChangeRecordTab();

private slots:
    void on_CreateQueryButton_clicked();

private:
    Ui::ChangeRecordTab *ui;
};

#endif // CHANGERECORDTAB_H
