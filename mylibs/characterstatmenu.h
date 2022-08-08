#ifndef CHARACTERSTATMENU_H
#define CHARACTERSTATMENU_H

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
#include <QCheckBox>


#include "../utils/structs.h"
#include "../utils/Randomizer.h"

Q_DECLARE_METATYPE(STATS);


class CharacterStatMenu : public QDialog
{
     Q_OBJECT
public:
    CharacterStatMenu(QWidget* parent = nullptr);

    QSize getSize(){return menuSize;}

private:


    std::unique_ptr<QLabel> name;
    std::unique_ptr<QLineEdit> name_line;

    std::unique_ptr<QLabel> STR;
    std::unique_ptr<QLineEdit> STR_line;

    std::unique_ptr<QLabel> DEX;
    std::unique_ptr<QLineEdit> DEX_line;


    std::unique_ptr<QLabel> CON;
    std::unique_ptr<QLineEdit> CON_line;

    std::unique_ptr<QLabel> INT;
    std::unique_ptr<QLineEdit> INT_line;

    std::unique_ptr<QLabel> WIS;
    std::unique_ptr<QLineEdit> WIS_line;

    std::unique_ptr<QLabel> CHA;
    std::unique_ptr<QLineEdit> CHA_line;

    std::unique_ptr<QLabel> CD;
    std::unique_ptr<QLineEdit> CD_line;
    std::unique_ptr<QCheckBox> addDex;




    std::unique_ptr<QLabel> HP;
    std::unique_ptr<QLineEdit> HP_line;
    std::unique_ptr<QComboBox> dice;
    std::unique_ptr<QLabel> plus;
    std::unique_ptr<QLineEdit> plus_line;

    std::unique_ptr<QLabel> initiative;
    std::unique_ptr<QLineEdit> initiative_line;
    std::unique_ptr<QCheckBox> addDexINIT;



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

#endif // CHARACTERSTATMENU_H
