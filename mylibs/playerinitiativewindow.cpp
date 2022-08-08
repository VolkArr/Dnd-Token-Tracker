#include "playerinitiativewindow.h"

PlayerInitiativeWindow::PlayerInitiativeWindow(std::vector<QString> names_t, QWidget* parent) : QDialog(parent)
{
    names = names_t;
    alocate_mem();
    make_window();
    conn();
}

void PlayerInitiativeWindow::alocate_mem(){
    startEvent = std::unique_ptr<QPushButton>(new QPushButton(this));
    close = std::unique_ptr<QPushButton>(new QPushButton(this));



}

void PlayerInitiativeWindow::make_window(){

    setWindowFlags(Qt::CustomizeWindowHint  | Qt::FramelessWindowHint);
    setModal(true);



    for(size_t i = 0; i < names.size(); i++){

        QLabel* tmp_name = new QLabel(this);
        tmp_name->setText(names[i]);
        QLabel* tmp_initiative = new QLabel(this);
        tmp_initiative->setText("Инициатива");
        init.push_back(std::make_unique<QLineEdit>(this));
        tmp_name->setGeometry(10,10 + (30*i) + 5,30,30);
        tmp_initiative->setGeometry(tmp_name->x() + tmp_name->width() + 5, tmp_name->y() ,60,30);
        init[init.size()-1]->setGeometry(tmp_initiative->x() + tmp_initiative->width() + 5, tmp_initiative->y() ,60,30);
        QIntValidator* validatorCD = new QIntValidator(0,100,this);
        init[init.size()-1]->setValidator(validatorCD);

    }
    startEvent->setText("Старт");
    close->setText("Отмена");
    startEvent->setGeometry(init[init.size()-1]->x(),init[init.size()-1]->y() + init[init.size()-1]->height() + 10, 60,30);
    close->setGeometry(startEvent->x()  + startEvent->width() + 5 ,startEvent->y(), 60,30);

    setGeometry(0,0, close->x()  + close->width() + 5 ,startEvent->y()+ startEvent->height()+10);

}

void PlayerInitiativeWindow::closeBtn(){
    accept();
}

void PlayerInitiativeWindow::conn(){
    connect(startEvent.get(), &QPushButton::clicked, this, &PlayerInitiativeWindow::Send);
    connect(close.get(), &QPushButton::clicked, this, &PlayerInitiativeWindow::closeBtn);
}


void PlayerInitiativeWindow::Send(){

    std::vector<STATS> stats;


    for(size_t i = 0; i < names.size(); i++){

        STATS stat;

        stat.name = names[i];

        stat.STR = 0;
        stat.DEX = 0;
        stat.CON = 0;
        stat.INT = 0;
        stat.WIS = 0;
        stat.CHA = 0;


        stat.CD = 0;
        stat.initiative = init[i]->text().toInt();;
        stat.type = "player";

        stats.push_back(stat);
    }

    emit sendSTATS(stats);
}
