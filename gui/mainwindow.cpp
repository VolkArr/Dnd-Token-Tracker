#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    alocate_mem();
    make_window();
    conn();
}

MainWindow::~MainWindow()
{

}



void MainWindow::alocate_mem(){
    menu = std::unique_ptr<Menu>(new Menu(this));
    charMenu = std::unique_ptr<CharacterStatMenu>(new CharacterStatMenu(this));
    playerMenu = std::unique_ptr<PlayerStatMenu>(new PlayerStatMenu(this));
    eventList = std::unique_ptr<QTabWidget>(new QTabWidget(this));
}


void MainWindow::tabBarClicked(int index){
    if(index == eventList->count()-1){
            if(!(eventList->tabText(eventList->count()-2) == "Бой")){
            events.push_back(std::make_unique<list>(width(), height()));
            QScrollArea* newTabScroll = new QScrollArea();

            newTabScroll->setGeometry(10,10,width()-210,height()-20);
            newTabScroll->setWidget(events[events.size()-1].get());
            newTabScroll->setWidgetResizable(true);
            QString newTabName = "Событие" + QString::fromStdString(std::to_string(eventList->count()-1));
            eventList->insertTab(eventList->count()-1, newTabScroll,newTabName);
            eventList->setCurrentIndex(eventList->count()-2);
        }
        else{
            eventList->setCurrentIndex(eventList->count()-2);
            QMessageBox::warning(this, "Идет бой", "Сначала завершите предыдущий бой");
        }
    }
}

void MainWindow::currentChanged(int index){
    if(index == 0){
        menu->deleteEvent->setDisabled(true);
        menu->startFight->setDisabled(true);
    }
    else{
        if(eventList->tabText(index) == "Бой"){
            menu->deleteEvent->setDisabled(false);
            menu->startFight->setDisabled(true);
        }
        else{
            menu->deleteEvent->setDisabled(false);
            menu->startFight->setDisabled(false);
        }
        if(eventList->tabText(index) ==  "Новое событие"){
            eventList->setCurrentIndex(eventList->count()-2);
        }
    }
}

void MainWindow::make_window(){
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    setGeometry(screenGeometry.width()/2 - 300, screenGeometry.height()/2 - 250,1015,500);



    eventList->setGeometry(10,10 ,width()-210,height() - 20);
    eventList->setTabPosition(QTabWidget::West);
    eventList->setTabShape(QTabWidget::Triangular);





    setStyleSheet("QFrame#isBorder { border: 1px solid; border-radius: 2px}");
    setStyleSheet("QScrollArea { border: 1px solid; border-radius: 2px}");

    events.push_back(std::make_unique<list>(width(), height()));
    QScrollArea* party_scroll = new QScrollArea();
    party_scroll->setGeometry(10,10,width()-210,height()-20);
    party_scroll->setWidget(events[events.size()-1].get());
    party_scroll->setWidgetResizable(true);
    eventList->addTab(party_scroll,"Пати");

    list* newTabList = new list(width()-210, height());
    QScrollArea* newTabScroll = new QScrollArea();

    newTabScroll->setGeometry(10,10,width()-210,height()-20);
    newTabScroll->setWidget(newTabList);
    newTabScroll->setWidgetResizable(true);
    eventList->insertTab(eventList->count()-2, newTabScroll,"Новое событие");

    menu->setGeometry(eventList->geometry().x() + eventList->geometry().width() + 25, eventList->geometry().y(), 150, 500);
    menu->deleteEvent->setDisabled(true);
    menu->startFight->setDisabled(true);

    setFixedSize(width(), height());



}

void MainWindow::conn(){
    connect(menu->addCharacter.get(), &QPushButton::clicked, this, &MainWindow::CollapseExpand);
    connect(menu->addPlayer.get(), &QPushButton::clicked, this, &MainWindow::CollapseExpandPlayer);
    connect(menu->startFight.get(), &QPushButton::clicked, this, &MainWindow::startFightBtn);
    connect(menu->deleteEvent.get(), &QPushButton::clicked, this, &MainWindow::deleteEvent);
    connect(charMenu.get(), &CharacterStatMenu::sendSTATS, this, &MainWindow::addCharacter);
    connect(playerMenu.get(), &PlayerStatMenu::sendSTATS, this, &MainWindow::addPlayer);


    connect(eventList.get(), &QTabWidget::currentChanged, this, &MainWindow::currentChanged);
    connect(eventList.get(), &QTabWidget::tabBarClicked, this, &MainWindow::tabBarClicked);

}

void MainWindow::startFightBtn(){
     if(!(eventList->tabText(eventList->count()-2) == "Бой")){
         std::vector<QString> names = events[0]->getNames();
         PlayerInitiativeWindow* tmpWindow = new PlayerInitiativeWindow(names);
         connect(tmpWindow, &PlayerInitiativeWindow::sendSTATS, this, &MainWindow::startFight);
         tmpWindow->setGeometry(x() + width()/2 - tmpWindow->width()/2,y()+height()/2 - tmpWindow->height()/2, tmpWindow->width(), tmpWindow->height());
         tmpWindow->show();
     }
     else{
          QMessageBox::warning(this, "Идет бой", "Сначала завершите предыдущий бой");
     }
}

void MainWindow::startFight(std::vector<STATS> names){
    events.push_back(std::make_unique<list>(width(), height()));
    std::vector<STATS> enemys = events[eventList->currentIndex()]->getSTATS();


    QScrollArea* newTabScroll = new QScrollArea();
    newTabScroll->setGeometry(10,10,width()-210,height()-20);
    newTabScroll->setWidget(events[events.size()-1].get());
    newTabScroll->setWidgetResizable(true);
    eventList->insertTab(eventList->count()-1, newTabScroll, "Бой");

    for(size_t i = 0; i < names.size(); i++){
        events[events.size() -1]->add(names[i]);
    }
    for(size_t i = 0; i < enemys.size(); i++){
        events[events.size() -1]->add(enemys[i]);
    }


    eventList->setCurrentIndex(eventList->count()-2);

}

void MainWindow::deleteEvent(){
    eventList->removeTab(eventList->currentIndex());
    if(eventList->currentIndex() == eventList->count()-1){
        eventList->setCurrentIndex(eventList->count()-2);
    }
}

void MainWindow::CollapseExpandPlayer(){
    if(menu->addCharacter->text() == "Свернуть"){
        menu->addCharacter->setText("Добавить токен");
        charMenu->hide();
    }
    if(menu->addPlayer->text() == "Добавить персонажа"){ // Развернуть
        menu->addPlayer->setText("Свернуть");
        makeAppear(playerMenu.get() );
    }
    else{ // Свернуть
        menu->addPlayer->setText("Добавить персонажа");
        playerMenu->hide();
    }
}

void MainWindow::CollapseExpand(){
    if(menu->addPlayer->text() == "Свернуть"){ // Развернуть
        menu->addPlayer->setText("Добавить персонажа");
        playerMenu->hide();
    }
    if(menu->addCharacter->text() == "Добавить токен"){ // Развернуть
        menu->addCharacter->setText("Свернуть");
        makeAppear(charMenu.get() );
    }
    else{ // Свернуть
        menu->addCharacter->setText("Добавить токен");
        charMenu->hide();
    }
}

void MainWindow::addPlayer(STATS stats){
    eventList->setCurrentIndex(0);
    events[0]->add(stats);
}

void MainWindow::addCharacter(STATS stats){
    if(!(eventList->currentIndex() == 0)){
        events[eventList->currentIndex()]->add(stats);
    }
}

void MainWindow::moveEvent(QMoveEvent * event){
    charMenu->move(x()+width(), y() + 31);
    playerMenu->move(x()+width(), y() + 31);
}

void MainWindow::makeAppear(PlayerStatMenu * dialog){
    static QParallelAnimationGroup *animationGroup = 0;
       if (animationGroup)
       {
           for(int i = 0, ie = animationGroup->animationCount(); i != ie; ++i)
               delete animationGroup->animationAt(i);
           delete animationGroup;
       }

       QRect geometryEnd = QRect(0,0,dialog->getSize().width(),dialog->getSize().height());


       geometryEnd.translate(x()+width(), y() + 31);

       QRect geometryBegin = geometryEnd;
       geometryBegin.setWidth(0);

       // Set up start and end geometry for the only child widget of 'dialog'.
       QWidget * dialogChildWidget = dynamic_cast< QWidget * >(dialog->children().first());
       if ( !dialogChildWidget )
           return;
       QRect childGeometryEnd = dialogChildWidget->geometry();
       QRect childGeometryBegin = childGeometryEnd;
       childGeometryBegin.translate(geometryEnd.width(), 0);

       // Set up animation for 'dialog'.
       QPropertyAnimation *dialogAnimation = new QPropertyAnimation(dialog, "geometry");
       dialogAnimation->setDuration(400);
       dialogAnimation->setStartValue(geometryBegin);
       dialogAnimation->setEndValue(geometryEnd);

       // Set up animation for the only child widget of 'dialog'.
       QPropertyAnimation *childAnimation = new QPropertyAnimation(dialogChildWidget, "geometry");
       childAnimation->setDuration(400);
       childAnimation->setStartValue(childGeometryBegin);
       childAnimation->setEndValue(childGeometryEnd);

       // Set up (and start) a parallel animation group
       animationGroup = new QParallelAnimationGroup;
       animationGroup->addAnimation(dialogAnimation);
       animationGroup->addAnimation(childAnimation);
       animationGroup->start();

       // Make 'dialog' visible, borderless, modal.

       dialog->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
       dialog->show();
}

void MainWindow::makeAppear(CharacterStatMenu * dialog)
{
    static QParallelAnimationGroup *animationGroup = 0;
       if (animationGroup)
       {
           for(int i = 0, ie = animationGroup->animationCount(); i != ie; ++i)
               delete animationGroup->animationAt(i);
           delete animationGroup;
       }

       QRect geometryEnd = QRect(0,0,dialog->getSize().width(),dialog->getSize().height());


       geometryEnd.translate(x()+width(), y() + 31);

       QRect geometryBegin = geometryEnd;
       geometryBegin.setWidth(0);

       // Set up start and end geometry for the only child widget of 'dialog'.
       QWidget * dialogChildWidget = dynamic_cast< QWidget * >(dialog->children().first());
       if ( !dialogChildWidget )
           return;
       QRect childGeometryEnd = dialogChildWidget->geometry();
       QRect childGeometryBegin = childGeometryEnd;
       childGeometryBegin.translate(geometryEnd.width(), 0);

       // Set up animation for 'dialog'.
       QPropertyAnimation *dialogAnimation = new QPropertyAnimation(dialog, "geometry");
       dialogAnimation->setDuration(400);
       dialogAnimation->setStartValue(geometryBegin);
       dialogAnimation->setEndValue(geometryEnd);

       // Set up animation for the only child widget of 'dialog'.
       QPropertyAnimation *childAnimation = new QPropertyAnimation(dialogChildWidget, "geometry");
       childAnimation->setDuration(400);
       childAnimation->setStartValue(childGeometryBegin);
       childAnimation->setEndValue(childGeometryEnd);

       // Set up (and start) a parallel animation group
       animationGroup = new QParallelAnimationGroup;
       animationGroup->addAnimation(dialogAnimation);
       animationGroup->addAnimation(childAnimation);
       animationGroup->start();

       // Make 'dialog' visible, borderless, modal.

       dialog->setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
       dialog->show();

}


