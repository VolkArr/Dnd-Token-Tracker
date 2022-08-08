#include "menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent)
{

    alocate_mem();
    make_window();
    conn();
}


void Menu::alocate_mem(){
    addCharacter = std::unique_ptr<QPushButton>(new QPushButton(this));
    addPlayer =  std::unique_ptr<QPushButton>(new QPushButton(this));
    startFight =  std::unique_ptr<QPushButton>(new QPushButton(this));
    deleteEvent =  std::unique_ptr<QPushButton>(new QPushButton(this));
}

void Menu::make_window(){
    addCharacter->setText("Добавить токен");
    addCharacter->setGeometry(10,10,130,30);
    addPlayer->setText("Добавить персонажа");
    addPlayer->setGeometry(addCharacter->x(), addCharacter->y() + addCharacter->height() + 10 ,addCharacter->width(),addCharacter->height());
    startFight->setText("Начать бой");
    startFight->setGeometry(addPlayer->x(), addPlayer->y() + addPlayer->height() + 10 ,addPlayer->width(),addPlayer->height());
    deleteEvent->setText("Удалить событие");
    deleteEvent->setGeometry(startFight->x(), startFight->y() + startFight->height() + 10 ,startFight->width(),startFight->height());
}

void Menu::conn(){

}
