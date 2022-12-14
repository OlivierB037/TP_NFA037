//
// Created by aperi on 30/11/2022.
//

#include "Perso.h"
#include "../Core/Mouvement.h"

Perso::Perso(int _left_1_x, int _left_1_y, int _left_2_x, int _left_2_y,
                int _right_1_x, int _right_1_y, int _right_2_x, int _right_2_y,
                int _up_1_x, int _up_1_y, int _up_2_x, int _up_2_y,
                int _down_1_x, int _down_1_y, int _down_2_x, int _down_2_y)

             : image( _left_1_x,  _left_1_y,  _left_2_x,  _left_2_y,
                      _right_1_x,  _right_1_y,  _right_2_x,  _right_2_y,
                      _up_1_x,  _up_1_y,  _up_2_x,  _up_2_y,
                      _down_1_x,  _down_1_y,  _down_2_x, _down_2_y),
                stepCount(1),
                currentSprite(& (image.getLeft1()))
{

}

const Sprites &Perso::getImage() const {
    return image;
}

const SDL_Rect *Perso::getCurrentSprite() const {
    return currentSprite;
}

int Perso::getStepCount() const {
    return stepCount;
}

void Perso::setStepCount(int _stepCount) {
    Perso::stepCount = _stepCount;
}

void Perso::setCurrentSprite(const SDL_Rect *_currentSprite) {
    Perso::currentSprite = _currentSprite;
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


