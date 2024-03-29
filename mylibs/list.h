#ifndef LIST_H
#define LIST_H

#include <QWidget>
#include <QVBoxLayout>



#include "character.h"
#include "player.h"

class list : public QFrame
{
    Q_OBJECT
public:
    explicit list(short w, short h, QWidget *parent = nullptr);

   void add(STATS stats);
   int getSize();
   std::vector<QString> getNames();
   std::vector<STATS> getSTATS();

private:
   std::unique_ptr<QVBoxLayout> ls;

   short w,h;

private:
    void alocate_mem();
    void make_window();
    void conn();

private slots:
    void sortByInitiative();

signals:

};

#endif // LIST_H
