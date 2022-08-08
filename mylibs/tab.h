#ifndef TAB_H
#define TAB_H

#include <QWidget>
#include <QScrollArea>
#include "../mylibs/list.h"

class TabBar : public QWidget{
    Q_OBJECT
public:
    TabBar(int w, int h, QWidget* parent = nullptr);
    std::unique_ptr<QScrollArea> scroll;
    std::unique_ptr<list> ls;

};
#endif // TAB_H
