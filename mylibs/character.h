#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFile>
#include <QDebug>


#include "../utils/structs.h"
#include "../utils/Randomizer.h"
#include "editablelabel.h"

#include <memory>

class Character : public QFrame
{
    Q_OBJECT
public:
    explicit Character(QWidget *parent = nullptr);
    Character(STATS stats, QWidget *parent = nullptr);

    int getInitiative(){return init_label->text().toInt();}

private:

    STATS character_Stats;

    std::unique_ptr<QPushButton> deletePreson;
    std::unique_ptr<QPushButton> CheckStats;
    std::unique_ptr<QPushButton> atackBTN;
    std::unique_ptr<QLabel> name_label;
    std::unique_ptr<EditableLabel> init_label;
    std::unique_ptr<EditableLabel> CD_label;
    std::unique_ptr<EditableLabel> maxHP_label;
    std::unique_ptr<EditableLabel> currentHP_label;
    std::unique_ptr<QLineEdit> atack;

    std::unique_ptr<QLabel> INIT;
    std::unique_ptr<QLabel> CD;
    std::unique_ptr<QLabel> HP;


private:
    void visualSettings();
    void alocate_mem();
    void make_window();
    void conn();


signals:
    void initiativeChanged();

private slots:
     void deletePersonBtn();
     void CheckStatsBtn();
     void takeDmg();

     void initChanged();

};

#endif // CHARACTER_H
