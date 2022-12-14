//
// Created by aperi on 13/12/2022.
//

#include "PhantomOrange.h"
PhantomOrange::PhantomOrange()
        :   Phantom(72, 252, 108, 252,
                             0, 252, 36, 252,
                             144, 252, 180, 252,
                             216, 252, 252, 252)

{
    this->setPosition(START_POSITION_X,START_POSITION_Y);
}

void PhantomOrange::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}



void PhantomOrange::changeSprite(Side direction) {

}