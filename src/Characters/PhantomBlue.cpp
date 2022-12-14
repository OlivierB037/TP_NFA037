//
// Created by aperi on 30/11/2022.
//

#include "PhantomBlue.h"

PhantomBlue::PhantomBlue()
        :   Phantom(72, 216, 108, 216,
                           0, 216, 36, 216,
                           144, 216, 180, 216,
                           216, 216, 252, 216)

{
    this->setPosition(START_POSITION_X,START_POSITION_Y);

}



void PhantomBlue::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;

}



void PhantomBlue::changeSprite(Side direction) {

}


