//
// Created by aperi on 13/12/2022.
//

#include "PhantomPink.h"
PhantomPink::PhantomPink()
        :   Phantom(72, 180, 108, 180,
                           0, 180, 36, 180,
                           144, 180, 180, 180,
                           216, 180, 252, 180), startingPosition(9,243)
{

    this->setPosition(startingPosition.x,startingPosition.y);
}

void PhantomPink::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}


void PhantomPink::changeSprite(Side direction) {

}

bool PhantomPink::operator==(const PhantomPink &rhs) const {
    return static_cast<const Phantom &>(*this) == static_cast<const Phantom &>(rhs) &&
           image == rhs.image &&
           currentSprite == rhs.currentSprite;
}

bool PhantomPink::operator!=(const PhantomPink &rhs) const {
    return static_cast<const Phantom &>(*this) != static_cast<const Phantom &>(rhs) ||
           image != rhs.image ||
           currentSprite != rhs.currentSprite;
}

const Position &PhantomPink::getStartingPosition() const {
    return startingPosition;
}
