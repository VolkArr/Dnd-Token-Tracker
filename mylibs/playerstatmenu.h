#ifndef PLAYERSTATMENU_H
#define PLAYERSTATMENU_H
#include <QWidget>
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QRect>
#include <QPointF>
#include <QComboBox>
#include <QIntValidator>
#include <QRadioButton>
#include <QRandomGenerator>
#include <QDebug>


#include "../utils/structs.h"
#include "../utils/Randomizer.h"




class PlayerStatMenu : public QDialog
{
    Q_OBJECT
public:
    PlayerStatMenu(QWidget* parent = nullptr);
public:

    QSize getSize(){return menuSize;}

private:

    std::unique_ptr<QLabel> name;
    std::unique_ptr<QLineEdit> name_line;

    std::unique_ptr<QPushButton> addPersonBtn;

    QSize menuSize;

private:
    void alocate_mem();
    void make_window();
    void conn();

private slots:
    void Send();

signals:
    void sendSTATS(STATS stats);

};
#endif // PLAYERSTATMENU_H
