#ifndef PLAYER_H
#define PLAYER_H

#include <person.h>

class Player : public Person
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = nullptr);
    Player(STATS stats, QWidget *parent = nullptr);

    int getInitiative() override {return init_label->text().toInt();}
    QString getName()override{return character_Stats.name;}
    STATS getSTATS() override{return character_Stats;}

private:

    STATS character_Stats;

    std::unique_ptr<QPushButton> deletePreson;
    std::unique_ptr<QPushButton> OutOfFight;
    std::unique_ptr<QLabel> name_label;
    std::unique_ptr<EditableLabel> init_label;
    std::unique_ptr<QLabel> status;
    std::unique_ptr<QLabel> INIT;


private:
    void visualSettings() override;
    void alocate_mem() override;
    void make_window() override;
    void conn();

    void init();

signals:
    void initiativeChanged() override;

private slots:
     void deletePersonBtn() override;
     void OutOfFightBtn();

     void initChanged();

};

#endif // PLAYER_H
