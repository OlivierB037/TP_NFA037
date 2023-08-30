//
// Created by aperi on 13/12/2022.
//

#include "PhantomPink.h"
typedef Phantom super;

PhantomPink::PhantomPink()
        :   Phantom(72, 180, 108, 180,
                           0, 180, 36, 180,
                           144, 180, 180, 180,
                           216, 180, 252, 180,RIGHT), startingPosition(9,243)
{

    this->setPosition(startingPosition.x,startingPosition.y);
    this->currentDirection = RIGHT;
}

void PhantomPink::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}


void PhantomPink::changeSprite(Side direction) {
    if (direction != currentDirection){
        currentDirection = direction;
    }
    super::changeSprite(direction);
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
Side PhantomPink::getDirection() {
    return currentDirection;
}

void PhantomPink::setDirection(Side _direction) {
    this->currentDirection = _direction;
}
