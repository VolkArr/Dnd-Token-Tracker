#ifndef EDITABLELABEL_H
#define EDITABLELABEL_H

#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QMouseEvent>

#include <memory>

class EditableLabel : public QWidget
{
    Q_OBJECT
public:
    explicit EditableLabel(QWidget *parent = nullptr);

    void setText(QString text);
    QString text();


private:
    std::unique_ptr<QLabel> label;
    std::unique_ptr<QLineEdit> editable;


protected:
    void mouseDoubleClickEvent( QMouseEvent * e );

private:
    void alocate_mem();
    void make_window();
    void conn();

private slots:
    void focusOut();

signals:
    void statChanged();
};

#endif // EDITABLELABEL_H
