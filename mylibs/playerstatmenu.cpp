#include "playerstatmenu.h"


PlayerStatMenu::PlayerStatMenu(QWidget* parent) : QDialog(parent)
{
    alocate_mem();
    make_window();
    conn();
}


void PlayerStatMenu::alocate_mem(){
    addPersonBtn = std::unique_ptr<QPushButton>(new QPushButton(this));
    name = std::unique_ptr<QLabel>(new QLabel(this));
    name_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));
}

void PlayerStatMenu::make_window(){

    setWindowFlags(Qt::CustomizeWindowHint  | Qt::FramelessWindowHint);

    name->setText("Имя:");
    addPersonBtn->setText("Добавить в пати");


    name->setGeometry(10,10,30,30);
    name_line->setGeometry(name->x(),name->y() + name->height()+2,160,30);


    addPersonBtn->setGeometry(name_line->x(),name_line->y()+name_line->height()+5,110,30);

    menuSize = QSize(name_line->x()+name_line->width()+10, addPersonBtn->y() + name_line->height()+10);

}

void PlayerStatMenu::conn(){
    connect(addPersonBtn.get(), &QPushButton::clicked, this, &PlayerStatMenu::Send);
}


void PlayerStatMenu::Send(){

    STATS stats;

    stats.name = name_line->text();



    stats.STR = 0;
    stats.DEX = 0;
    stats.CON = 0;
    stats.INT = 0;
    stats.WIS = 0;
    stats.CHA = 0;


    stats.CD = 0;

    stats.initiative = 0;

    stats.HP = 0;



    stats.type = "player";

    sendSTATS(stats);
}
