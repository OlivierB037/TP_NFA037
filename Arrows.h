//
// Created by aperi on 07/12/2022.
//

#ifndef TP_NFA037_ARROWS_H
#define TP_NFA037_ARROWS_H


#include <SDL_scancode.h>
#include "Key.h"

class Arrows {
private:
    static Key *leftKey;
    static Key *rightKey;
    static Key *upKey;
    static Key *downKey;




public:


    Arrows() = delete;
    Arrows(Arrows &copy) = delete;
    void operator=(const Arrows &) = delete;
    static Key* getDirectionKey(Side direction);
    static Key *getLeftKey();

    static Key *getRightKey();

    static Key *getUpKey();

    static Key *getDownKey();







};


#endif //TP_NFA037_ARROWS_H
