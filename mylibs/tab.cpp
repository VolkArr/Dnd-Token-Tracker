#include "tab.h"

TabBar::TabBar(int w, int h, QWidget* parent) : QWidget(parent)
{
   scroll =  std::unique_ptr<QScrollArea>(new QScrollArea);
   ls =  std::unique_ptr<list>(new list(w,h));

   scroll->setGeometry(10,10,w,h);
   scroll->setWidget(ls.get());
   scroll->setWidgetResizable(true);
}
