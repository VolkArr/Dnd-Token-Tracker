#ifndef PLAYERINITIATIVEWINDOW_H
#define PLAYERINITIATIVEWINDOW_H

#include <QObject>

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

Q_DECLARE_METATYPE(std::vector<STATS>);

class PlayerInitiativeWindow  : public QDialog
{
    Q_OBJECT

public:
    PlayerInitiativeWindow(std::vector<QString> names_t,  QWidget* parent = nullptr);


private:
    void alocate_mem();
    void make_window();
    void conn();

private:
    std::vector<QString> names;

    std::vector<std::unique_ptr<QLineEdit>> init;

    std::unique_ptr<QPushButton> startEvent;
    std::unique_ptr<QPushButton> close;

private slots:
    void Send();
    void closeBtn();

signals:
    void sendSTATS(std::vector<STATS> stats);
};

#endif // PLAYERINITIATIVEWINDOW_H
