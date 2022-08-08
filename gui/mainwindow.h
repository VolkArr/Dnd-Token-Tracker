    #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QScreen>
#include <QGuiApplication>
#include <QDebug>
#include <QScrollArea>
#include <QDialog>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QDragMoveEvent>
#include <QTabWidget>
#include <QMessageBox>


#include "../mylibs/character.h"
#include "../mylibs/menu.h"
#include "../mylibs/characterstatmenu.h"
#include "../mylibs/playerstatmenu.h"
#include "../mylibs/list.h"
#include "../mylibs/tab.h"
#include "../mylibs/playerinitiativewindow.h"

#include <thread>
#include <chrono>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    std::unique_ptr<Menu> menu;
    std::unique_ptr<CharacterStatMenu> charMenu;
    std::unique_ptr<PlayerStatMenu> playerMenu;
    std::unique_ptr<QTabWidget> eventList;
    std::vector<std::unique_ptr<list>> events;



private:
    void alocate_mem();
    void make_window();
    void conn();


    void makeAppear(CharacterStatMenu * dialog);
    void makeAppear(PlayerStatMenu * dialog);



private slots:
    void CollapseExpand();
    void CollapseExpandPlayer();
    void startFight(std::vector<STATS> names);
    void deleteEvent();
    void startFightBtn();
    void addCharacter(STATS stats);
    void addPlayer(STATS stats);


protected:
    void moveEvent(QMoveEvent * event);
    void tabBarClicked(int index);
    void currentChanged(int index);
};
#endif // MAINWINDOW_H
