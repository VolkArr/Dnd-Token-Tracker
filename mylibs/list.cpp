#include "list.h"

list::list(short w_t, short h_t, QWidget *parent) : QFrame(parent), w{w_t}, h{h_t}
{
    setObjectName("isBorder");
    alocate_mem();
    make_window();
    conn();
}

void list::add(STATS stats){
    Character* tmp = new Character(stats);
    ls->addWidget(tmp);
    sortByInitiative();

}


void list::alocate_mem(){
    ls = std::unique_ptr<QVBoxLayout>(new QVBoxLayout(this));
}

void list::make_window(){
     ls->setAlignment(Qt::AlignTop);
     ls->setGeometry(QRect(10,10,w-210,h-10));

}

void list::sortByInitiative(){
    std::vector<Character*> tmp_array;
    int size = ls->count();
    for(size_t i = 0; i < size ; i++){
        tmp_array.push_back((Character*)ls->itemAt(0)->widget());
        tmp_array[i]->setParent(nullptr);
        tmp_array[i]->hide();
    }
    std::sort(tmp_array.begin(), tmp_array.end(), [](Character* a, Character* b) {
            return a->getInitiative() > b->getInitiative();
        });
    for(size_t i = 0; i < tmp_array.size() ; i++){
        ls->addWidget(tmp_array[i]);
        tmp_array[i]->show();
    }
}

void list::conn(){

}
