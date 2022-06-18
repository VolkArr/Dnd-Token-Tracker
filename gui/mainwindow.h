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


#include "../mylibs/character.h"
#include "../mylibs/menu.h"
#include "../mylibs/characterstatmenu.h"
#include "../mylibs/list.h"

#include <thread>
#include <chrono>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    std::unique_ptr<list> ls;
    std::unique_ptr<QScrollArea> scroll;
    std::unique_ptr<Menu> menu;
    std::unique_ptr<CharacterStatMenu> charMenu;



private:
    void alocate_mem();
    void make_window();
    void conn();
    void makeAppear(CharacterStatMenu * dialog);



private slots:
    void CollapseExpand();
    void addCharacter(STATS stats);


protected:
    void moveEvent(QMoveEvent * event);
};
#endif // MAINWINDOW_H
