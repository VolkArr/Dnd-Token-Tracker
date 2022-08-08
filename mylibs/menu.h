#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QPushButton>


class Menu : public QWidget
{
    Q_OBJECT
public:
    explicit Menu(QWidget *parent = nullptr);

public:
    std::unique_ptr<QPushButton> addCharacter;
    std::unique_ptr<QPushButton> addPlayer;
    std::unique_ptr<QPushButton> startFight;
    std::unique_ptr<QPushButton> deleteEvent;

private:
    void alocate_mem();
    void make_window();
    void conn();

signals:

};

#endif // MENU_H
