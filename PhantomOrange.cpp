//
// Created by aperi on 13/12/2022.
//

#include "PhantomOrange.h"
PhantomOrange::PhantomOrange()
        :   Phantom(), image(72, 252, 108, 252,
                             0, 252, 36, 252,
                             144, 252, 180, 252,
                             216, 252, 252, 252),
            currentSprite(&image.getLeft1())

{

}

const SDL_Rect *PhantomOrange::getCurrentSprite() const {
    return currentSprite;
}

void PhantomOrange::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}

const Image &PhantomOrange::getImage() const {
    return image;
}

void PhantomOrange::changeSprite(Side direction) {

}