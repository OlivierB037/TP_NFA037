//
// Created by aperi on 13/12/2022.
//

#include "PhantomRed.h"

PhantomRed::PhantomRed()
        :   Phantom(), image(72, 144, 108, 144,
                           0, 144, 36, 144,
                           144, 144, 180, 144,
                           216, 144, 252, 144),
            currentSprite(&image.getLeft1()), startingPosition(441,243)
{

    this->setPosition(startingPosition.x,startingPosition.y);
}

const SDL_Rect *PhantomRed::getCurrentSprite() const {
    return currentSprite;
}

void PhantomRed::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}

const Image &PhantomRed::getImage() const {
    return image;
}

void PhantomRed::changeSprite(Side direction) {

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


