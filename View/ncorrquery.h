#ifndef NCORRQUERY_H
#define NCORRQUERY_H

#include <QWidget>

namespace Ui {
class NCorrQuery;
}

class NCorrQuery : public QWidget
{
    Q_OBJECT

public:
    explicit NCorrQuery(QWidget *parent = nullptr);
    ~NCorrQuery();

private slots:
    void on_CreateSubqueryButton_clicked();

private:
    Ui::NCorrQuery *ui;
};

#endif // NCORRQUERY_H
