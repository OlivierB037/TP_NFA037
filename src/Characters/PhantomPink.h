//
// Created by aperi on 13/12/2022.
//

#ifndef TP_NFA037_PHANTOMPINK_H
#define TP_NFA037_PHANTOMPINK_H


#include "Phantom.h"

class PhantomPink  : public Phantom{
public:
    PhantomPink();

    inline static const int PHANTOM_KEY{15634};
    inline static const int START_POSITION_X {9};
    inline static const int START_POSITION_Y {243};

    void setCurrentSprite(const SDL_Rect *currentSprite);

    void changeSprite(Side direction);

private:

};



#endif //TP_NFA037_PHANTOMPINK_H
