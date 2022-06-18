#include "menu.h"

Menu::Menu(QWidget *parent) : QWidget(parent)
{

    alocate_mem();
    make_window();
    conn();
}


void Menu::alocate_mem(){
    addCharacter = std::unique_ptr<QPushButton>(new QPushButton(this));
}

void Menu::make_window(){
    addCharacter->setText("Быстрое добавление");
    addCharacter->setGeometry(10,10,130,30);
}

void Menu::conn(){

}
