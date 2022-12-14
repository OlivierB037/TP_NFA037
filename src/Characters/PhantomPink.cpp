//
// Created by aperi on 13/12/2022.
//

#include "PhantomPink.h"
PhantomPink::PhantomPink()
        :   Phantom(72, 180, 108, 180,
                           0, 180, 36, 180,
                           144, 180, 180, 180,
                           216, 180, 252, 180)

{
    this->setPosition(START_POSITION_X,START_POSITION_Y);
}

void PhantomPink::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}


void PhantomPink::changeSprite(Side direction) {

}