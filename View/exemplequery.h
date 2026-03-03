#ifndef EXEMPLEQUERY_H
#define EXEMPLEQUERY_H

#include <QWidget>

namespace Ui {
class ExempleQuery;
}

class ExempleQuery : public QWidget
{
    Q_OBJECT

public:
    explicit ExempleQuery(QWidget *parent = nullptr);
    ~ExempleQuery();

private slots:
    void on_CreateQueryButton_clicked();

private:
    Ui::ExempleQuery *ui;
};

#endif // EXEMPLEQUERY_H
