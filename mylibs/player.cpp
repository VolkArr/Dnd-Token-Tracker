#include "player.h"

Player::Player(QWidget *parent) : Person(parent), character_Stats{STATS()}
{

    init();
}


Player::Player( STATS stats, QWidget *parent): Person(parent), character_Stats{stats}{

    init();
}

void Player::init(){
    alocate_mem();
    make_window();
    conn();
}


void Player::deletePersonBtn(){
    setParent(nullptr);
    delete this;
}




void Player::visualSettings(){
    setObjectName("isBorder");
    setMinimumSize(QSize(deletePreson->x() + deletePreson->width() + 10,OutOfFight->y() + OutOfFight->height() + 20));
    setMaximumHeight(OutOfFight->y() + OutOfFight->height() + 20);

}

void Player::alocate_mem(){
   deletePreson = std::unique_ptr<QPushButton>(new QPushButton(this));
   OutOfFight = std::unique_ptr<QPushButton>(new QPushButton(this));
   name_label = std::unique_ptr<QLabel>(new QLabel(this));
   init_label = std::unique_ptr<EditableLabel>(new EditableLabel(this));
   status = std::unique_ptr<QLabel>(new QLabel(this));
   INIT = std::unique_ptr<QLabel>(new QLabel(this));
}

void Player::make_window(){


    setObjectName("isBorder");
    setStyleSheet("QFrame#isBorder { border: 1px solid; border-radius: 2px}");

    INIT->setText("Инициатива: ");

    status->setGeometry(5,5, 30, 75);
    status->setStyleSheet("QLabel { background-color : green;  }");

    if( character_Stats.name.count() == 0){
        character_Stats.name = randomName();
    }

    name_label->setText(character_Stats.name);
    name_label->setGeometry(status->x() + status->width() + 10,status->y(),100,25);


    INIT->setGeometry(name_label->x() + name_label->width() + 10,name_label->y(),70,25);
    init_label->setText(QString::fromStdString(std::to_string(character_Stats.initiative)));
    init_label->setGeometry(INIT->x() + INIT->width() + 5,INIT->y(),32,25);




    deletePreson->setText("Убить");
    deletePreson->setGeometry(init_label->x() + init_label->width() + 10,init_label->y(), 110,25);
    OutOfFight->setText("Упал");
    OutOfFight->setGeometry(deletePreson->x(), deletePreson->y() + deletePreson->height() + 10, 110, 25);




    visualSettings();


}

void Player::OutOfFightBtn(){
     if(OutOfFight->text() == "Упал"){
         OutOfFight->setText("Стабилизировать");
         status->setStyleSheet("QLabel { background-color : grey;  }");
     }
     else{
         OutOfFight->setText("Упал");
         status->setStyleSheet("QLabel { background-color : green;  }");
     }
}

void Player::initChanged(){
    emit initiativeChanged();
}

void Player::conn(){
    connect(deletePreson.get(), &QPushButton::clicked, this, &Player::deletePersonBtn);
    connect(OutOfFight.get(), &QPushButton::clicked, this, &Player::OutOfFightBtn);
    connect(init_label.get(), &EditableLabel::statChanged, this, &Player::initChanged);

}
