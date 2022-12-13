//
// Created by aperi on 13/12/2022.
//

#include "PhantomPink.h"
PhantomPink::PhantomPink()
        :   Phantom(), image(72, 180, 108, 180,
                           0, 180, 36, 180,
                           144, 180, 180, 180,
                           216, 180, 252, 180),
            currentSprite(&image.getLeft1())

{

}

const SDL_Rect *PhantomPink::getCurrentSprite() const {
    return currentSprite;
}

void PhantomPink::setCurrentSprite(const SDL_Rect *_currentSprite) {
    currentSprite = _currentSprite;
}

const Image &PhantomPink::getImage() const {
    return image;
}

void PhantomPink::changeSprite(Side direction) {

}