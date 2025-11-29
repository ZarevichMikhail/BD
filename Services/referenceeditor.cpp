#include "referenceeditor.h"

ReferenceEditor::ReferenceEditor(QWidget *parent)
    : QWidget{parent}
{



    // Создаем горизонтальную разметку без отступов, чтобы влезло в ячейку таблицы
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    lineEdit = new QLineEdit(this);
    lineEdit->setReadOnly(true); // Запрещаем ручной ввод, только выбор!

    button = new QToolButton(this);
    button->setText("..."); // Кнопка выбора

    // !!! ДОБАВЬТЕ ЭТУ СТРОКУ !!!
    // Заставляем кнопку всегда быть видимой и иметь фиксированный размер
    button->setFixedSize(25, 20); // Ширина 25, Высота 20 (под высоту строки)
    // Или, чтобы она растягивалась по высоте, но не по ширине:
    // button->setFixedWidth(25);

    layout->addWidget(lineEdit);
    layout->addWidget(button);



    // Когда жмут кнопку, мы пересылаем сигнал наружу
    connect(button, &QToolButton::clicked, this, &ReferenceEditor::selectClicked);


}


QString ReferenceEditor::text() const {
    return lineEdit->text();
}

void ReferenceEditor::setText(const QString &t) {
    lineEdit->setText(t);
}




int ReferenceEditor::currentId() const {
    return m_currentId;
}

void ReferenceEditor::setCurrentId(int id) {
    m_currentId = id;
}






