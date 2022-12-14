//
// Created by aperi on 30/11/2022.
//

#include "Hero.h"
#define HERO_START_POSITION_X 450
#define HERO_START_POSITION_Y 9
typedef Perso super;
Hero::Hero()
   : super(CHARACTER_SIZE, CHARACTER_SIZE, 0, CHARACTER_SIZE,
           CHARACTER_SIZE, 0, 0, 0,
           CHARACTER_SIZE, (CHARACTER_SIZE * 2), 0, (CHARACTER_SIZE * 2),
           CHARACTER_SIZE, (3 * CHARACTER_SIZE), 0, (3 * CHARACTER_SIZE))


{
    Perso::setPosition(HERO_START_POSITION_X, HERO_START_POSITION_Y);
}



void Hero::setCurrentSprite(const SDL_Rect *_currentSprite) {
    super::setCurrentSprite(_currentSprite);
}



void Hero::changeSprite(Side direction) {
switch (direction) {
    case LEFT:
        if (currentSprite == &(image.getLeft1())){
            currentSprite = &(image.getLeft2());
        }
        else{
            currentSprite = &(image.getLeft1());
        }
        break;
    case RIGHT:
        if (currentSprite == &(image.getRight1())){
            currentSprite = &(image.getRight2());
        }
        else{
            currentSprite = &(image.getRight1());
        }
        break;
    case UP:
        if (currentSprite == &(image.getUp1())){
            currentSprite = &(image.getUp2());
        }
        else{
            currentSprite = &(image.getUp1());
        }
        break;
    case DOWN:
        if (currentSprite == &(image.getDown1())){
            currentSprite = &(image.getDown2());
        }
        else{
            currentSprite = &(image.getDown1());
        }
        break;
    case NONE:
        break;
}
}
