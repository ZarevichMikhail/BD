#include "workersdelegate.h"


#include "referenceeditor.h"  // Наш виджет с кнопкой
#include "workerselectdialog.h" // Наш диалог

#include <QPointer>



WorkersDelegate::WorkersDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{}






QWidget *WorkersDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    ReferenceEditor *editor = new ReferenceEditor(parent);
    // Используем адрес функции openDialog
    connect(editor, &ReferenceEditor::selectClicked, this, &WorkersDelegate::openDialog);
    return editor;
}

void WorkersDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    // // Берем текущий текст из ячейки и пишем в редактор
    // // QString value = index.model()->data(index, Qt::EditRole).toString();
    // // ReferenceEditor *refEditor = static_cast<ReferenceEditor*>(editor);
    // // refEditor->setText(value);

    // ReferenceEditor *refEditor = static_cast<ReferenceEditor*>(editor);

    // // ВАЖНО: Получаем ID из модели!
    // // Если это QSqlRelationalTableModel, то EditRole вернет ID (число).
    // int currentId = index.model()->data(index, Qt::EditRole).toInt();

    // // Получаем Текст для отображения
    // QString currentText = index.model()->data(index, Qt::DisplayRole).toString();

    // // Загружаем ОБА значения
    // refEditor->setCurrentId(currentId);
    // refEditor->setText(currentText);


    ReferenceEditor *refEditor = static_cast<ReferenceEditor*>(editor);

    // Так как setRelation нет, в модели лежит просто ЧИСЛО (ID)
    int currentId = index.model()->data(index, Qt::EditRole).toInt();

    // 1. Записываем ID в скрытое поле
    refEditor->setCurrentId(currentId);

    // 2. Записываем ID в текстовое поле (показываем число)
    // Если хотите, чтобы при открытии редактора там всё-таки появлялась Фамилия,
    // вам придется сделать SQL-запрос вручную (SELECT Фамилия WHERE ID=...),
    // но проще пока просто показать текущий ID.
    refEditor->setText(QString::number(currentId));

}

void WorkersDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    // Берем текст из редактора и пишем в модель
    //ReferenceEditor *refEditor = static_cast<ReferenceEditor*>(editor);
    //model->setData(index, refEditor->text(), Qt::EditRole);

    //ReferenceEditor *refEditor = static_cast<ReferenceEditor*>(editor);
    //model->setData(index, refEditor->currentId(), Qt::EditRole);

    ReferenceEditor *refEditor = static_cast<ReferenceEditor*>(editor);

    // Мы сохраняем ID (число), а не текст!
    model->setData(index, refEditor->currentId(), Qt::EditRole);
}


void WorkersDelegate::openDialog()
{

    // ИСПОЛЬЗУЕМ QPointer ДЛЯ ЗАЩИТЫ ОТ ВЫЛЕТА
    // QPointer автоматически обнулится, если объект editor будет удален системой
    QPointer<ReferenceEditor> editor = qobject_cast<ReferenceEditor*>(sender());
    // Сюда переносите код открытия диалога
    // ВАЖНО: Чтобы это сработало, вам нужно знать, КАКОЙ editor вызвал этот слот.
    // В лямбде это просто (переменная editor доступна).
    // В отдельном слоте сложнее - нужно использовать qobject_cast<ReferenceEditor*>(sender());

    //ReferenceEditor *editor = qobject_cast<ReferenceEditor*>(sender());
    if (!editor) return;


    WorkerSelectDialog dialog;
    if (dialog.exec() == QDialog::Accepted) {

        // ПРОВЕРКА: Жив ли еще наш редактор после закрытия диалога?
        if (editor) {
            //editor->setText(dialog.getSelectedName()); // Показываем имя
            editor->setCurrentId(dialog.getSelectedId()); // Запоминаем ID

            // Хитрость: Сообщаем модели, что редактирование завершено
            emit commitData(editor);
            emit closeEditor(editor);
        }
    }


    // WorkerSelectDialog dialog; // Или как называется ваш диалог выбора сотрудника
    // if (dialog.exec() == QDialog::Accepted) {
    //     editor->setText(dialog.getSelectedName());
    //     // Обновление модели произойдет автоматически через setModelData
    // }
}






