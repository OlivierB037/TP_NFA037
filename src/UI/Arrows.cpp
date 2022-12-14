//
// Created by aperi on 07/12/2022.
//

#include "Arrows.h"



Key* Arrows::leftKey = new Key(SDL_SCANCODE_LEFT, LEFT);
Key* Arrows::rightKey = new Key(SDL_SCANCODE_RIGHT, RIGHT);
Key* Arrows::upKey = new Key(SDL_SCANCODE_UP, UP);
Key* Arrows::downKey = new Key(SDL_SCANCODE_DOWN, DOWN);


Key *Arrows::getDirectionKey(Side direction) {
    switch (direction) {
        case LEFT: return Arrows::leftKey;
        case RIGHT: return Arrows::rightKey;
        case UP: return Arrows::upKey;
        case DOWN: return Arrows::downKey;
        default: return nullptr;
    }
}






Key *Arrows::getLeftKey() {
    return leftKey;
}

Key *Arrows::getRightKey(){
    return rightKey;
}

Key *Arrows::getUpKey(){
    return upKey;
}

Key *Arrows::getDownKey(){
    return downKey;
}


