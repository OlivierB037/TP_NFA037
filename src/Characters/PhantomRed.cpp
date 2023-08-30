//
// Created by aperi on 13/12/2022.
//

#include "PhantomRed.h"
typedef Phantom super;

PhantomRed::PhantomRed()
        :   Phantom(72, 144, 108, 144,
                           0, 144, 36, 144,
                           144, 144, 180, 144,
                           216, 144, 252, 144,LEFT), startingPosition(441,243)
{

    this->setPosition(startingPosition.x,startingPosition.y);
    this->currentDirection = LEFT;
}

void PhantomRed::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}

void PhantomRed::changeSprite(Side direction) {
    if (direction != currentDirection){
        currentDirection = direction;
    }
    super::changeSprite(direction);
}
bool PhantomRed::operator==(const PhantomRed &rhs) const {
    return static_cast<const Phantom &>(*this) == static_cast<const Phantom &>(rhs) &&
           image == rhs.image &&
           currentSprite == rhs.currentSprite;
}

bool PhantomRed::operator!=(const PhantomRed &rhs) const {
    return static_cast<const Phantom &>(*this) != static_cast<const Phantom &>(rhs) ||
           image != rhs.image ||
           currentSprite != rhs.currentSprite;
}

const Position &PhantomRed::getStartingPosition() const {
    return startingPosition;
}
Side PhantomRed::getDirection() {
    return currentDirection;
}

void PhantomRed::setDirection(Side _direction) {
    this->currentDirection = _direction;
}