#include "character.h"

Character::Character(QWidget *parent) : Person(parent), character_Stats{STATS()}
{

    init();
}


Character::Character( STATS stats, QWidget *parent): Person(parent), character_Stats{stats}{

    init();
}


void Character::init(){
    alocate_mem();
    make_window();
    conn();
}

void Character::deletePersonBtn(){
    setParent(nullptr);
    delete this;
}

void Character::CheckStatsBtn(){

}

void Character::takeDmg(){
    QString tmp = QString::fromStdString(std::to_string(currentHP_label->text().toInt() - atack->text().toInt()));
    currentHP_label->setText(tmp);
    if(currentHP_label->text().toInt() <= 0) deletePersonBtn();
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
   init_label = std::unique_ptr<EditableLabel>(new EditableLabel(this));
   CD_label = std::unique_ptr<EditableLabel>(new EditableLabel(this));
   maxHP_label = std::unique_ptr<EditableLabel>(new EditableLabel(this));
   currentHP_label = std::unique_ptr<EditableLabel>(new EditableLabel(this));
   HP = std::unique_ptr<QLabel>(new QLabel(this));
   CD = std::unique_ptr<QLabel>(new QLabel(this));
   INIT = std::unique_ptr<QLabel>(new QLabel(this));
   atack = std::unique_ptr<QLineEdit>(new QLineEdit(this));
   status = std::unique_ptr<QLabel>(new QLabel(this));
}

void Character::make_window(){

    setObjectName("isBorder");
    setStyleSheet("QFrame#isBorder { border: 1px solid; border-radius: 2px}");

    INIT->setText("Инициатива: ");
    HP->setText("ХП: max/curr");
    CD->setText("CD:");

    status->setGeometry(5,5, 30, 75);
    status->setStyleSheet("QLabel { background-color : red;  }");

    if( character_Stats.name.count() == 0){
        character_Stats.name = randomName();
    }

    name_label->setText(character_Stats.name);
    name_label->setGeometry(status->x() + status->width() + 10,status->y(),100,25);


    INIT->setGeometry(name_label->x() + name_label->width() + 10,name_label->y(),70,25);
    init_label->setText(QString::fromStdString(std::to_string(character_Stats.initiative)));
    init_label->setGeometry(INIT->x() + INIT->width() + 5,INIT->y(),32,25);


    CD->setGeometry(init_label->x() + init_label->width() + 10,init_label->y(),30,25);
    CD_label->setText(QString::fromStdString(std::to_string(character_Stats.CD)));
    CD_label->setGeometry(CD->x() + CD->width() + 5,CD->y(),20,25);

    HP->setGeometry(CD_label->x() + CD_label->width() + 10,CD_label->y(),80,25);
    maxHP_label->setText(QString::fromStdString(std::to_string(character_Stats.HP)));
    maxHP_label->setGeometry(HP->x() + HP->width() + 5,HP->y(),30,25);

    currentHP_label->setText(QString::fromStdString(std::to_string(character_Stats.HP)));
    currentHP_label->setGeometry(maxHP_label->x() + maxHP_label->width() + 1,maxHP_label->y(),30,25);

    deletePreson->setText("Убить");
    deletePreson->setGeometry(currentHP_label->x() + currentHP_label->width() + 10,currentHP_label->y(), 60,25);

    atack->setGeometry(deletePreson->x(), deletePreson->y() + deletePreson->height() + 10, 60, 25);

    atackBTN->setText("Нанести урон");
    atackBTN->setGeometry(atack->x() + atack->width() + 10, atack->y(), 110,25);

    CheckStats->setText("Посмотреть статы");
    CheckStats->setGeometry(deletePreson->x() + deletePreson->width() + 10, deletePreson->y(), 110, 25);


    visualSettings();

    //setGeometry(0,0, rollInitiative->x() + rollInitiative->width() + 10, atack->y() + atack->height() + 20);
}

void Character::initChanged(){
    emit initiativeChanged();
}

void Character::conn(){
    connect(deletePreson.get(), &QPushButton::clicked, this, &Character::deletePersonBtn);
    connect(atackBTN.get(), &QPushButton::clicked, this, &Character::takeDmg);
    connect(init_label.get(), &EditableLabel::statChanged, this, &Character::initChanged);

}
