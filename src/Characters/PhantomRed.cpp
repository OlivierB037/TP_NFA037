//
// Created by aperi on 13/12/2022.
//

#include "PhantomRed.h"

PhantomRed::PhantomRed()
        :   Phantom(72, 144, 108, 144,
                           0, 144, 36, 144,
                           144, 144, 180, 144,
                           216, 144, 252, 144)

{
    this->setPosition(START_POSITION_X,START_POSITION_Y);
}

void PhantomRed::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}

void PhantomRed::changeSprite(Side direction) {

}
