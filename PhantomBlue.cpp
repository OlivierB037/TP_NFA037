//
// Created by aperi on 30/11/2022.
//

#include "PhantomBlue.h"

PhantomBlue::PhantomBlue()
        :   Phantom(), image(72, 216, 108, 216,
                           0, 216, 36, 216,
                           144, 216, 180, 216,
                           216, 216, 252, 216),
            currentSprite(&image.getLeft1())

{

}

const SDL_Rect *PhantomBlue::getCurrentSprite() const {
    return currentSprite;
}

void PhantomBlue::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}

const Image &PhantomBlue::getImage() const {
    return image;
}

void PhantomBlue::changeSprite(Side direction) {

}


