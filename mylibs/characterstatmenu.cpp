#include "characterstatmenu.h"

CharacterStatMenu::CharacterStatMenu(QWidget* parent) : QDialog(parent)
{
    alocate_mem();
    make_window();
    conn();
}


void CharacterStatMenu::alocate_mem(){
    addPersonBtn = std::unique_ptr<QPushButton>(new QPushButton(this));
    STR = std::unique_ptr<QLabel>(new QLabel(this));
    DEX = std::unique_ptr<QLabel>(new QLabel(this));
    CON = std::unique_ptr<QLabel>(new QLabel(this));
    INT = std::unique_ptr<QLabel>(new QLabel(this));
    WIS = std::unique_ptr<QLabel>(new QLabel(this));
    CHA = std::unique_ptr<QLabel>(new QLabel(this));
    name = std::unique_ptr<QLabel>(new QLabel(this));
    name_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));
    STR_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));
    DEX_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));
    CON_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));
    INT_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));
    WIS_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));
    CHA_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));

    HP = std::unique_ptr<QLabel>(new QLabel(this));
    HP_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));
    dice = std::unique_ptr<QComboBox>(new QComboBox(this));
    plus  = std::unique_ptr<QLabel>(new QLabel(this));
    plus_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));

    CD = std::unique_ptr<QLabel>(new QLabel(this));
    CD_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));

    initiative = std::unique_ptr<QLabel>(new QLabel(this));
    initiative_line = std::unique_ptr<QLineEdit>(new QLineEdit(this));
    addDex = std::unique_ptr<QRadioButton>(new QRadioButton(this));
    addDexINIT = std::unique_ptr<QRadioButton>(new QRadioButton(this));

    Tips = std::unique_ptr<QLabel>(new QLabel(this));
}

void CharacterStatMenu::make_window(){

    setWindowFlags(Qt::CustomizeWindowHint  | Qt::FramelessWindowHint);

    name->setText("Имя:");
    HP->setText("Кость хитов: ");
    CD->setText("Класс доспеха");
    initiative->setText("Инициатива");
    plus->setText("+");
    STR->setText("STR");
    DEX->setText("DEX");
    CON->setText("CON");
    INT->setText("INT");
    WIS->setText("WIS");
    CHA->setText("CHA");
    addPersonBtn->setText("Добавить");


    name->setGeometry(10,10,30,30);
    name_line->setGeometry(name->x(),name->y() + name->height()+2,160,30);


    HP->setGeometry(name_line->x(),name_line->y()+name_line->height()+5,70,20);
    HP_line->setGeometry(HP->x(),HP->y() + HP->height()+2,60,20);
    QIntValidator* validator = new QIntValidator(1,1000,this);
    HP_line->setValidator(validator);
    HP_line->setText("1");
    dice->setGeometry(HP_line->x() + HP_line->width(), HP_line->y(),50,20);
    dice->addItem("d6");
    dice->addItem("d8");
    dice->addItem("d10");
    dice->addItem("d12");
    dice->addItem("d20");
    dice->addItem("d100");
    plus->setGeometry(dice->x() + dice->width(), dice->y(),10,20);
    plus_line->setGeometry(plus->x() + plus->width(), plus->y(),30,20);
     QIntValidator* validatorPLUS = new QIntValidator(-1000,1000,this);
    plus_line->setValidator(validatorPLUS);
    plus_line->setText("0");



    CD->setGeometry(HP_line->x(),HP_line->y()+HP_line->height()+5,80,20);
    CD_line->setGeometry(CD->x()+ CD->width()+2,CD->y() ,60,20);
    QIntValidator* validatorCD = new QIntValidator(0,100,this);
    CD_line->setValidator(validatorCD);
    CD_line->setText("10");

    addDex->setText("Добавить Лов. к КД");
    addDex->setGeometry(CD->x(),CD->y()+CD->height()+5,150,20);

    initiative->setGeometry(addDex->x(),addDex->y()+addDex->height()+5,80,20);
    initiative_line->setGeometry(initiative->x() + initiative->width()+2,initiative->y() ,60,20);
    initiative_line->setValidator(validatorCD);
    initiative_line->setText("0");


    addDexINIT->setText("Добавить Лов. к Иниц");
    addDexINIT->setGeometry(initiative->x(),initiative->y()+initiative->height()+5,150,20);

    QIntValidator* validatorSTAT = new QIntValidator(1,100,this);

    STR->setGeometry(addDexINIT->x(),addDexINIT->y()+addDexINIT->height()+5,30,30);
    STR_line->setGeometry(STR->x()+STR->width()+2,STR->y(), 30, 30);
    STR_line->setValidator(validatorSTAT);
    STR_line->setText("10");

    Tips->setText("Подсказка! Исправить ХП и остальные статы можно двойным нажатием на стат в списке персонажей           Если инициатива = 0, то она ролиться 1д20+ЛОВ");
    Tips->setWordWrap(true);
    Tips->setGeometry(STR_line->x()+STR_line->width() + 20, STR_line->y(), 60,250);

    DEX->setGeometry(STR->x(),STR->y()+STR->height()+5,30,30);
    DEX_line->setGeometry(DEX->x()+DEX->width()+2,DEX->y(), 30, 30);
    DEX_line->setValidator(validatorSTAT);
    DEX_line->setText("10");

    CON->setGeometry(DEX->x(),DEX->y()+DEX->height()+5,30,30);
    CON_line->setGeometry(CON->x()+CON->width()+2,CON->y(), 30, 30);
    CON_line->setValidator(validatorSTAT);
    CON_line->setText("10");

    INT->setGeometry(CON->x(),CON->y()+CON->height()+5,30,30);
    INT_line->setGeometry(INT->x()+INT->width()+2,INT->y(), 30, 30);
    INT_line->setValidator(validatorSTAT);
    INT_line->setText("10");

    WIS->setGeometry(INT->x(),INT->y()+INT->height()+5,30,30);
    WIS_line->setGeometry(WIS->x()+WIS->width()+2,WIS->y(), 30, 30);
    WIS_line->setValidator(validatorSTAT);
    WIS_line->setText("10");

    CHA->setGeometry(WIS->x(),WIS->y()+WIS->height()+5,30,30);
    CHA_line->setGeometry(CHA->x()+CHA->width()+2,CHA->y(), 30, 30);
    CHA_line->setValidator(validatorSTAT);
    CHA_line->setText("10");

    addPersonBtn->setGeometry(CHA->x(),CHA->y()+CHA->height()+5,60,30);

    menuSize = QSize(CHA_line->x()+CHA_line->width()+100, addPersonBtn->y() + addPersonBtn->height()+10);

}

void CharacterStatMenu::conn(){
    connect(addPersonBtn.get(), &QPushButton::clicked, this, &CharacterStatMenu::Send);
}


void CharacterStatMenu::Send(){

    STATS stats;

    stats.name = name_line->text();



    stats.STR = STR_line->text().toInt();
    stats.DEX = DEX_line->text().toInt();
    stats.CON = CON_line->text().toInt();
    stats.INT = INT_line->text().toInt();
    stats.WIS = WIS_line->text().toInt();
    stats.CHA = CHA_line->text().toInt();


    if(!(addDex->isChecked())){
        stats.CD = CD_line->text().toInt();
    }
    else{
        stats.CD = CD_line->text().toInt() + stats.getMod().DEX_m;
    }

    if(initiative_line->text() == "0"){
        stats.initiative = roll_D20() + stats.getMod().DEX_m;
    }
    else{
        if(addDexINIT->isChecked()){
            stats.initiative = initiative_line->text().toInt() + stats.getMod().DEX_m;
        }
        else{
            stats.initiative = initiative_line->text().toInt();
        }
    }

    if(dice->currentText() == "d4"){
        long current = 0;
        for(size_t i = 0; i < HP_line->text().toInt(); i++){
            current+=roll_D4();
        }
        stats.HP = current + plus_line->text().toInt();
    }
    else if(dice->currentText() == "d6"){
        long current = 0;
        std::vector<long> tmp;
        for(size_t i = 0; i < HP_line->text().toInt(); i++){
            tmp.push_back(roll_D6());
            current+=tmp[i];
        }
//        for(std::vector<long>::iterator it = tmp.begin(); it != tmp.end(); ++it)
//             current += *it;
        stats.HP = current + plus_line->text().toInt();
    }
    else if(dice->currentText() == "d8"){
        long current = 0;
        for(size_t i = 0; i < HP_line->text().toInt(); i++){
            current+=roll_D8();
        }
        stats.HP = current + plus_line->text().toInt();
    }
    else if(dice->currentText() == "d10"){
        long current = 0;
        for(size_t i = 0; i < HP_line->text().toInt(); i++){
            current+=roll_D10();
        }
        stats.HP = current + plus_line->text().toInt();
    }
    else if(dice->currentText() == "d12"){
        long current = 0;
        for(size_t i = 0; i < HP_line->text().toInt(); i++){
            current+=roll_D12();
        }
        stats.HP = current + plus_line->text().toInt();
    }
    else if(dice->currentText() == "d20"){
        long current = 0;
        for(size_t i = 0; i < HP_line->text().toInt(); i++){
            current+=roll_D20();

        }
        stats.HP = current + plus_line->text().toInt();
    }
    else if(dice->currentText() == "d100"){
        long current = 0;
        for(size_t i = 0; i < HP_line->text().toInt(); i++){
            current+=roll_D100();
        }
        stats.HP = current + plus_line->text().toInt();
    }


    sendSTATS(stats);
}
