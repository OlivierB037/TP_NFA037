//
// Created by aperi on 30/11/2022.
//

#include "Hero.h"
#define HERO_START_POSITION_X 450
#define HERO_START_POSITION_Y 9
Hero::Hero()
   : Perso(CHARACTER_SIZE, CHARACTER_SIZE, 0, CHARACTER_SIZE,
           CHARACTER_SIZE, 0, 0, 0,
           CHARACTER_SIZE, (CHARACTER_SIZE * 2), 0, (CHARACTER_SIZE * 2),
           CHARACTER_SIZE, (3 * CHARACTER_SIZE), 0, (3 * CHARACTER_SIZE))

{
    Perso::setPosition(HERO_START_POSITION_X, HERO_START_POSITION_Y);
}
