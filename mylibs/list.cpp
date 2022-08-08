#include "list.h"

list::list(short w_t, short h_t, QWidget *parent) : QFrame(parent), w{w_t}, h{h_t}
{
    setObjectName("isBorder");
    alocate_mem();
    make_window();
    conn();
}

int list::getSize(){
    return ls->count();
}

void list::add(STATS stats){
    if(stats.type == "token"){
        Character* tmp = new Character(stats);
        connect(tmp, &Character::initiativeChanged, this, &list::sortByInitiative);
        ls->addWidget(tmp);
        sortByInitiative();
    }
    if(stats.type == "player"){
        Player* tmp = new Player(stats);
        connect(tmp, &Player::initiativeChanged, this, &list::sortByInitiative);
        ls->addWidget(tmp);
        sortByInitiative();
    }

}


void list::alocate_mem(){
    ls = std::unique_ptr<QVBoxLayout>(new QVBoxLayout(this));
}

void list::make_window(){
     ls->setAlignment(Qt::AlignTop);
     ls->setGeometry(QRect(10,10,w-210,h-10));

}

std::vector<STATS> list::getSTATS(){
    std::vector<STATS> stats;
    std::vector<Person*> tmp_array;
    int size = ls->count();
    for(size_t i = 0; i <  size ; i++){
        tmp_array.push_back((Person*)ls->itemAt(0)->widget());
        tmp_array[i]->setParent(nullptr);
        tmp_array[i]->hide();
        stats.push_back(tmp_array[i]->getSTATS());
    }
    std::sort(tmp_array.begin(), tmp_array.end(), [](Person* a, Person* b) {
            return a->getInitiative() > b->getInitiative();
        });
    for(size_t i = 0; i < tmp_array.size() ; i++){
        ls->addWidget(tmp_array[i]);
        tmp_array[i]->show();
    }
    return stats;
}

std::vector<QString> list::getNames(){
    std::vector<QString> names;
    std::vector<Person*> tmp_array;
    int size = ls->count();
    for(size_t i = 0; i <  size ; i++){
        tmp_array.push_back((Person*)ls->itemAt(0)->widget());
        tmp_array[i]->setParent(nullptr);
        tmp_array[i]->hide();
        names.push_back(tmp_array[i]->getName());
    }
    std::sort(tmp_array.begin(), tmp_array.end(), [](Person* a, Person* b) {
            return a->getInitiative() > b->getInitiative();
        });
    for(size_t i = 0; i < tmp_array.size() ; i++){
        ls->addWidget(tmp_array[i]);
        tmp_array[i]->show();
    }
    return names;
}

void list::sortByInitiative(){
    std::vector<Person*> tmp_array;
    int size = ls->count();
    for(size_t i = 0; i < size ; i++){
        tmp_array.push_back((Person*)ls->itemAt(0)->widget());
        tmp_array[i]->setParent(nullptr);
        tmp_array[i]->hide();
    }
    std::sort(tmp_array.begin(), tmp_array.end(), [](Person* a, Person* b) {
            return a->getInitiative() > b->getInitiative();
        });
    for(size_t i = 0; i < tmp_array.size() ; i++){
        ls->addWidget(tmp_array[i]);
        tmp_array[i]->show();
    }
}

void list::conn(){

}
