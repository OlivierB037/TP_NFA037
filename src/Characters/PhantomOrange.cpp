//
// Created by aperi on 13/12/2022.
//

#include "PhantomOrange.h"
PhantomOrange::PhantomOrange()
        :   Phantom(72, 252, 108, 252,
                             0, 252, 36, 252,
                             144, 252, 180, 252,
                             216, 252, 252, 252), startingPosition(459,513)
{

    this->setPosition(startingPosition.x,startingPosition.y);
}

void PhantomOrange::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}



void PhantomOrange::changeSprite(Side direction) {

}

bool PhantomOrange::operator==(const PhantomOrange &rhs) const {
    return static_cast<const Phantom &>(*this) == static_cast<const Phantom &>(rhs) &&
           image == rhs.image &&
           currentSprite == rhs.currentSprite;
}

bool PhantomOrange::operator!=(const PhantomOrange &rhs) const {
    return static_cast<const Phantom &>(*this) != static_cast<const Phantom &>(rhs) ||
           image != rhs.image ||
           currentSprite != rhs.currentSprite;
}
const Position &PhantomOrange::getStartingPosition() const {
    return startingPosition;
}
