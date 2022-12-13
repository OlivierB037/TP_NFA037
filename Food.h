//
// Created by aperi on 08/12/2022.
//

#ifndef TP_NFA037_FOOD_H
#define TP_NFA037_FOOD_H

#include "Bloc.h"

class Food : public Bloc {
public :

    Food();

    bool isCrossable() const;

    bool isEaten() const;

    void setEaten(bool _eaten);

private:
    bool eaten;
};


#endif //TP_NFA037_FOOD_H
