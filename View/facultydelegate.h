#ifndef FACULTYDELEGATE_H
#define FACULTYDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QComboBox> //

class FacultyDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit FacultyDelegate(QObject *parent = nullptr);

    // Эти три функции мы будем реализовывать
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;




signals:
};

#endif // FACULTYDELEGATE_H
