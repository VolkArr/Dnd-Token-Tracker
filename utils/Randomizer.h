

#ifndef RANDOMIZER_H
#define RANDOMIZER_H


#include <QRandomGenerator>
#include <QDateTime>
#include <QFile>
#include <QString>
#include <QDir>
#include <QDebug>

long roll_Custom(long max);

long roll_D4();

long roll_D6();

long roll_D8();

long roll_D10();

long roll_D12();

long roll_D20();

long roll_D100();

QString randomName();

#endif // RANDOMIZER_H
