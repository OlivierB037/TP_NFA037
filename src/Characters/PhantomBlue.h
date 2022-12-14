//
// Created by aperi on 30/11/2022.
//

#ifndef TP_01_PHANTOM_H
#define TP_01_PHANTOM_H


#include "Perso.h"
#include "Phantom.h"

class PhantomBlue  : public Phantom{
public:
    PhantomBlue();

    inline static const int PHANTOM_KEY{15635};
    inline static const int START_POSITION_X {9};
    inline static const int START_POSITION_Y {513};

    void setCurrentSprite(const SDL_Rect *currentSprite);

    void changeSprite(Side direction);

private:


};


#endif //TP_01_PHANTOM_H
