//
// Created by aperi on 30/11/2022.
//

#include "Perso.h"
#include "Mouvement.h"

Perso::Perso()
    : stepCount(1)
{
}

int Perso::getStepCount() const {
    return stepCount;
}

void Perso::setStepCount(int stepCount) {
    Perso::stepCount = stepCount;
}



const Position &Perso::getPosition() const {
    return position;
}



void Perso::incrementX(int value) {
    position.incrementX(value);

}

void Perso::incrementY(int value) {
    position.incrementY(value);

}

void Perso::setPosition(int _x, int _y) {
    position.setX(_x);
    position.setY(_y);
}

void Perso::incrementStepCount() {
    stepCount ++;
//    if (stepCount == SPRITE_RATE ){
//        stepCount = 1;
//    }
}


