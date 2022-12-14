//
// Created by aperi on 13/12/2022.
//

#ifndef TP_NFA037_PHANTOMORANGE_H
#define TP_NFA037_PHANTOMORANGE_H


#include "Phantom.h"

class PhantomOrange  : public Phantom{
public:
    PhantomOrange();

    inline static const int PHANTOM_KEY{15636};
    inline static const int START_POSITION_X {459};
    inline static const int START_POSITION_Y {513};
    void setCurrentSprite(const SDL_Rect *currentSprite);

    void changeSprite(Side direction);

private:

};


#endif //TP_NFA037_PHANTOMORANGE_H
