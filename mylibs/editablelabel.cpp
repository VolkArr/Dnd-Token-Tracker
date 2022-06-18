#include "editablelabel.h"

EditableLabel::EditableLabel(QWidget *parent) : QWidget(parent)
{
    alocate_mem();
    make_window();
    conn();
}

void EditableLabel::mouseDoubleClickEvent( QMouseEvent * e )
{
    if ( e->button() == Qt::LeftButton )
    {
           label->hide();
           editable->show();
           editable->setText(label->text());
           editable->setFocus();
    }

    QWidget::mouseDoubleClickEvent( e );
}

void EditableLabel::setText(QString text){
        label->setText(text);
}

QString EditableLabel::text(){
        return label->text();
}


void EditableLabel::alocate_mem(){
    label = std::unique_ptr<QLabel>(new QLabel(this));
    editable = std::unique_ptr<QLineEdit>(new QLineEdit(this));
}

void EditableLabel::make_window(){
    label->setGeometry(0,0,30,25);
    editable->setGeometry(0,0,30,25);
    editable->hide();
}

void EditableLabel::focusOut(){
    editable->hide();
    label->show();
    label->setText(editable->text());
    emit statChanged();
}

void EditableLabel::conn(){
    connect(editable.get(), &QLineEdit::editingFinished, this, &EditableLabel::focusOut );
}
