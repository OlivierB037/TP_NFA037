//
// Created by aperi on 13/12/2022.
//

#ifndef TP_NFA037_FRUIT_H
#define TP_NFA037_FRUIT_H


#include "Bloc.h"

class Fruit : Bloc {
    Fruit();

    bool isCrossable() const;

    bool isEaten() const;

    void setEaten(bool _eaten);

private:
    bool eaten;

};


#endif //TP_NFA037_FRUIT_H
