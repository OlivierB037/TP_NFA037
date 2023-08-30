//
// Created by aperi on 30/11/2022.
//

#include "PhantomBlue.h"
typedef Phantom super;
PhantomBlue::PhantomBlue()
        :   Phantom(72, 216, 108, 216,
                           0, 216, 36, 216,
                           144, 216, 180, 216,
                           216, 216, 252, 216,RIGHT), startingPosition(9,513)
{

    this->setPosition(startingPosition.x,startingPosition.y);
    this->currentDirection = RIGHT;
}



void PhantomBlue::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;

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

Side PhantomBlue::getDirection() {
    return currentDirection;
}

void PhantomBlue::setDirection(Side _direction) {
    if (currentDirection != _direction){
        this->changeSprite(_direction);
    }
    this->currentDirection = _direction;

}

void PhantomBlue::changeSprite(Side direction) {
    if (direction != currentDirection){
        currentDirection = direction;
    }
    super::changeSprite(direction);
}


