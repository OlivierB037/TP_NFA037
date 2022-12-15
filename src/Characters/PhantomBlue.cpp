//
// Created by aperi on 30/11/2022.
//

#include "PhantomBlue.h"

PhantomBlue::PhantomBlue()
        :   Phantom(72, 216, 108, 216,
                           0, 216, 36, 216,
                           144, 216, 180, 216,
                           216, 216, 252, 216), startingPosition(9,513)
{

    this->setPosition(startingPosition.x,startingPosition.y);

}



void PhantomBlue::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;

}



void PhantomBlue::changeSprite(Side direction) {

}

bool PhantomBlue::operator==(const PhantomBlue &rhs) const {
    return static_cast<const Phantom &>(*this) == static_cast<const Phantom &>(rhs) &&
           image == rhs.image &&
           currentSprite == rhs.currentSprite;
}

bool PhantomBlue::operator!=(const PhantomBlue &rhs) const {
    return static_cast<const Phantom &>(*this) != static_cast<const Phantom &>(rhs) ||
           image != rhs.image ||
           currentSprite != rhs.currentSprite;
}

const Position &PhantomBlue::getStartingPosition() const {
    return startingPosition;
}


