#include "character.h"

Character::Character(QWidget *parent) : QFrame(parent), character_Stats{STATS()}
{

    alocate_mem();
    make_window();
    conn();
}


Character::Character( STATS stats, QWidget *parent): QFrame(parent), character_Stats{stats}{

    alocate_mem();
    make_window();
    conn();
}


void Character::Roll_initiative(){

}

void Character::Roll_HP(){

}

void Character::visualSettings(){
    setObjectName("isBorder");
    setMinimumSize(QSize(CheckStats->x() + CheckStats->width() + 10,atack->y() + atack->height() + 20));
    setMaximumHeight(atack->y() + atack->height() + 20);
}

void Character::alocate_mem(){
   deletePreson = std::unique_ptr<QPushButton>(new QPushButton(this));
   CheckStats = std::unique_ptr<QPushButton>(new QPushButton(this));
   atackBTN = std::unique_ptr<QPushButton>(new QPushButton(this));
   name_label = std::unique_ptr<QLabel>(new QLabel(this));
   init_label = std::unique_ptr<QLabel>(new QLabel(this));
   CD_label = std::unique_ptr<QLabel>(new QLabel(this));
   maxHP_label = std::unique_ptr<QLabel>(new QLabel(this));
   currentHP_label = std::unique_ptr<QLabel>(new QLabel(this));
   HP = std::unique_ptr<QLabel>(new QLabel(this));
   CD = std::unique_ptr<QLabel>(new QLabel(this));
   INIT = std::unique_ptr<QLabel>(new QLabel(this));
   atack = std::unique_ptr<QLineEdit>(new QLineEdit(this));;
}

void Character::make_window(){

    setObjectName("isBorder");
    setStyleSheet("QFrame#isBorder { border: 1px solid; border-radius: 2px}");

    INIT->setText("Инициатива: ");
    HP->setText("ХП: Максимум/Текущее");
    CD->setText("Класс Доспехов");



    if( character_Stats.name.count() == 0){
        character_Stats.name = randomName();
    }

    name_label->setText(character_Stats.name);
    name_label->setGeometry(10,10,80,25);


    INIT->setGeometry(name_label->x() + name_label->width() + 10,name_label->y(),100,25);
    init_label->setText(QString::fromStdString(std::to_string(character_Stats.initiative)));
    init_label->setGeometry(INIT->x() + INIT->width() + 1,INIT->y(),30,25);


    CD->setGeometry(init_label->x() + init_label->width() + 10,init_label->y(),100,25);
    CD_label->setText(QString::fromStdString(std::to_string(character_Stats.CD)));
    CD_label->setGeometry(CD->x() + CD->width() + 1,CD->y(),20,25);

    HP->setGeometry(CD_label->x() + CD_label->width() + 10,CD_label->y(),150,25);
    maxHP_label->setText(QString::fromStdString(std::to_string(character_Stats.HP)));
    maxHP_label->setGeometry(HP->x() + HP->width() + 1,HP->y(),30,25);

    currentHP_label->setText(QString::fromStdString(std::to_string(character_Stats.HP)));
    currentHP_label->setGeometry(maxHP_label->x() + maxHP_label->width() + 1,maxHP_label->y(),30,25);

    deletePreson->setText("Удалить");
    deletePreson->setGeometry(currentHP_label->x() + currentHP_label->width() + 10,currentHP_label->y(), 60,25);

    atack->setGeometry(deletePreson->x(), deletePreson->y() + deletePreson->height() + 10, 60, 25);

    atackBTN->setText("Нанести урон");
    atackBTN->setGeometry(atack->x() + atack->width() + 10, atack->y(), 110,25);

    CheckStats->setText("Посмотреть статы");
    CheckStats->setGeometry(deletePreson->x() + deletePreson->width() + 10, deletePreson->y(), 110, 25);


    visualSettings();

    //setGeometry(0,0, rollInitiative->x() + rollInitiative->width() + 10, atack->y() + atack->height() + 20);
}



void Character::conn(){

}