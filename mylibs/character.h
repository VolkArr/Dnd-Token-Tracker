#ifndef CHARACTER_H
#define CHARACTER_H

#include <person.h>

class Character : public Person
{
    Q_OBJECT
public:
    explicit Character(QWidget *parent = nullptr);
    Character(STATS stats, QWidget *parent = nullptr);

    int getInitiative() override{return init_label->text().toInt();}
    QString getName() override{return character_Stats.name;}
    STATS getSTATS() override{return character_Stats;}
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
    std::unique_ptr<QLabel> status;

    std::unique_ptr<QLabel> INIT;
    std::unique_ptr<QLabel> CD;
    std::unique_ptr<QLabel> HP;


private:
    void visualSettings() override;
    void alocate_mem() override;
    void make_window() override;
    void conn() override;

    void init();


signals:
    void initiativeChanged() override;

private slots:
     void deletePersonBtn() override;
     void CheckStatsBtn();
     void takeDmg() ;

     void initChanged() override;

};

#endif // CHARACTER_H
