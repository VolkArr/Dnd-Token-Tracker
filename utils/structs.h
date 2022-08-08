#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdint.h>
#include <QString>


struct MOD{
    uint16_t STR_m; // Сила
    uint16_t DEX_m; // Ловкость
    uint16_t CON_m; // Телосложение
    uint16_t INT_m; // Интелект
    uint16_t WIS_m; // Мудрость
    uint16_t CHA_m; // Харизма
};

struct STATS{

    STATS(STATS* tmp){
        STR = tmp->STR;
        DEX = tmp->DEX;
        CON = tmp->CON;
        INT = tmp->INT;
        WIS = tmp->WIS;
        CHA = tmp->CHA;

        CD = tmp->CD;
        HP = tmp->HP;
        initiative = tmp->initiative;

        name = tmp->name;
        type = tmp->type;



    }

    STATS(){
        STR = 10;
        DEX = 10;
        CON = 10;
        INT = 10;
        WIS = 10;
        CHA = 10;

        CD = 10;
        HP = 0;
        initiative = 0;

        name = "";
        type = "token";
    }

    STATS( uint8_t STR_t, uint8_t DEX_t, uint8_t CON_t, uint8_t INT_t, uint8_t WIS_t, uint8_t CHA_t, uint8_t CD_t, uint8_t HP_t, uint8_t initiative_t, QString name_t, QString type_t){
        STR = STR_t;
        DEX = DEX_t;
        CON = CON_t;
        INT = INT_t;
        WIS = WIS_t;
        CHA = CHA_t;

        CD = CD_t;
        HP = HP_t;
        initiative = initiative_t;

        name = name_t;
        type = type_t;
    }

    MOD getMod(){
        modificators.STR_m = STR/2 -5;
        modificators.DEX_m = DEX/2 -5;
        modificators.CON_m = CON/2 -5;
        modificators.INT_m = INT/2 -5;
        modificators.WIS_m = WIS/2 -5;
        modificators.CHA_m = CHA/2 -5;
        return modificators;
    }

    QString name;

    uint16_t STR; // Сила
    uint16_t DEX; // Ловкость
    uint16_t CON; // Телосложение
    uint16_t INT; // Интелект
    uint16_t WIS; // Мудрость
    uint16_t CHA; // Харизма

    MOD modificators;

    uint16_t CD;
    uint16_t HP;

    uint16_t initiative;

    QString type;
};


#endif // STRUCTS_H
