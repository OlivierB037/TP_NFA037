//
// Created by aperi on 13/12/2022.
//

#ifndef TP_NFA037_PHANTOMORANGE_H
#define TP_NFA037_PHANTOMORANGE_H


#include "Phantom.h"

class PhantomOrange  : public Phantom{
public:
    PhantomOrange();

    bool operator==(const PhantomOrange &rhs) const;

    bool operator!=(const PhantomOrange &rhs) const;

    inline static const int PHANTOM_KEY{15636};

    void setCurrentSprite(const SDL_Rect *currentSprite);

    void changeSprite(Side direction);

    const Position& getStartingPosition() const;

private:
    const Position startingPosition;
};


#endif //TP_NFA037_PHANTOMORANGE_H
