//
// Created by aperi on 13/12/2022.
//

#include "PhantomOrange.h"
typedef Phantom super;

PhantomOrange::PhantomOrange()
        :   Phantom(72, 252, 108, 252,
                             0, 252, 36, 252,
                             144, 252, 180, 252,
                             216, 252, 252, 252,LEFT), startingPosition(459,513)
{

    this->setPosition(startingPosition.x,startingPosition.y);
    this->currentDirection = LEFT;
}

void PhantomOrange::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}



void PhantomOrange::changeSprite(Side direction) {
    if (direction != currentDirection){
        currentDirection = direction;
    }
    super::changeSprite(direction);
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

Side PhantomOrange::getDirection() {
    return currentDirection;
}

void PhantomOrange::setDirection(Side _direction) {
    this->currentDirection = _direction;
}
