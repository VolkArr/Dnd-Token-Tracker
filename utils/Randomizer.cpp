#include "Randomizer.h"

long roll_Custom(long max){

    return (QRandomGenerator::system()->generate() % max ) + 1;
}

long roll_D4(){

    return ( QRandomGenerator::system()->generate() % 4) + 1;
}

long roll_D6(){

    return ( QRandomGenerator::system()->generate() % 6) + 1;
}

long roll_D8(){

    return ( QRandomGenerator::system()->generate() % 8) + 1;
}

long roll_D10(){

    return ( QRandomGenerator::system()->generate() % 10) + 1;
}

long roll_D12(){

    return ( QRandomGenerator::system()->generate() % 12) + 1;
}

long roll_D20(){

    return ( QRandomGenerator::system()->generate() % 20) + 1;
}

long roll_D100(){

    return ( QRandomGenerator::system()->generate() % 100) + 1;
}

QString randomName(){

    QFile file(QDir::currentPath() + "./data/names.txt");

    if (!file.open(QIODevice::ReadOnly))
        return QString("");
;
    long rnd = ( QRandomGenerator::system()->generate() % 11000) + 1;
    for(size_t i = 1; i < rnd; i++){
        file.readLine();
    }
    file.close();
    return QString::fromStdString(file.readLine().toStdString());
}
