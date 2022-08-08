#ifndef PERSON_H
#define PERSON_H


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

class Person : public QFrame
{
    Q_OBJECT
public:
    explicit Person(QWidget *parent = nullptr);
    Person(STATS stats, QWidget *parent = nullptr);
    virtual ~Person();
    virtual int getInitiative() = 0;
    virtual QString getName() = 0;
    virtual STATS getSTATS() = 0;

protected:

    STATS character_Stats;

    std::unique_ptr<QPushButton> deletePreson;
    //std::unique_ptr<QPushButton> OutOfFight;
    std::unique_ptr<QLabel> name_label;
    std::unique_ptr<EditableLabel> init_label;

    std::unique_ptr<QLabel> INIT;


protected:
    virtual void visualSettings() = 0;
    virtual void alocate_mem() = 0;
    virtual void make_window() = 0;
    virtual void conn() = 0;


signals:
    virtual void initiativeChanged() = 0;

protected slots:
     virtual void deletePersonBtn() = 0 ;
     //void OutOfFightBtn();

     virtual void initChanged() = 0;

};
#endif // PERSON_H
