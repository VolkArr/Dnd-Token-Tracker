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
    ls = std::unique_ptr<list>(new list(width(), height(), this));
    charMenu = std::unique_ptr<CharacterStatMenu>(new CharacterStatMenu(this));
    scroll = std::unique_ptr<QScrollArea>(new QScrollArea(this));
}

void MainWindow::make_window(){




    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();

    setGeometry(screenGeometry.width()/2 - 300, screenGeometry.height()/2 - 250,1000,500);

    setStyleSheet("QFrame#isBorder { border: 1px solid; border-radius: 2px}");
    setStyleSheet("QScrollArea { border: 1px solid; border-radius: 2px}");

    scroll->setGeometry(10,10 ,width() - 210,height() - 10);
    scroll->setWidget(ls.get());
    scroll->setWidgetResizable(true);

    menu->setGeometry(scroll->geometry().x() + scroll->geometry().width() + 10, scroll->geometry().y(), 150, 500);


    setFixedSize(width(), height());



}

void MainWindow::conn(){
    connect(menu->addCharacter.get(), &QPushButton::clicked, this, &MainWindow::CollapseExpand);
    connect(charMenu.get(), &CharacterStatMenu::sendSTATS, this, &MainWindow::addCharacter);
}


void MainWindow::CollapseExpand(){
    if(menu->addCharacter->text() == "Быстрое добавление"){ // Развернуть
        menu->addCharacter->setText("Свернуть");
        makeAppear(charMenu.get() );
    }
    else{ // Свернуть
        menu->addCharacter->setText("Быстрое добавление");
        charMenu->hide();
    }

}
void MainWindow::addCharacter(STATS stats){

    ls->add(stats);

}

void MainWindow::moveEvent(QMoveEvent * event){
    charMenu->move(x()+width(), y() + 31);
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


