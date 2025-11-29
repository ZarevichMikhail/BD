#ifndef WORKERSDELEGATE_H
#define WORKERSDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>

class WorkersDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit WorkersDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;


private slots:
    // Слот, который откроет диалог
    void openDialog();

signals:
};

#endif // WORKERSDELEGATE_H
