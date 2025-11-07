#include "facultydelegate.h"

FacultyDelegate::FacultyDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{}







// Функция создания виджета QComboBox
QWidget *FacultyDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // Создаем выпадающий список
    QComboBox *editor = new QComboBox(parent);

    // Заполнение
    editor->addItem("ИРЭТ");
    editor->addItem("ФВС");
    editor->addItem("ФСУ");
    editor->addItem("ФИТ");
    editor->addItem("ГФ");
    editor->addItem("ФБ");
    editor->addItem("ЮФ");

    return editor;
}


// 2. Эта функция читает данные из таблицы и устанавливает их в QComboBox
void FacultyDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    // Получаем текущее значение из ячейки
    QString value = index.model()->data(index, Qt::EditRole).toString();

    // Приводим наш виджет к типу QComboBox
    QComboBox *comboBox = static_cast<QComboBox*>(editor);

    // Устанавливаем это значение как текущее в списке
    comboBox->setCurrentText(value);
}

// 3. Эта функция берет выбранное значение из QComboBox и сохраняет его в модель (в таблицу)
void FacultyDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString value = comboBox->currentText(); // Получаем текст, который выбрал пользователь

    // Передаем новое значение в модель
    model->setData(index, value, Qt::EditRole);
}




