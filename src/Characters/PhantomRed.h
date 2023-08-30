//
// Created by aperi on 13/12/2022.
//

#ifndef TP_NFA037_PHANTOMRED_H
#define TP_NFA037_PHANTOMRED_H


#include "Phantom.h"

class PhantomRed  : public Phantom{
public:
    PhantomRed();

    bool operator==(const PhantomRed &rhs) const;

    bool operator!=(const PhantomRed &rhs) const;

    inline static const int PHANTOM_KEY{15633};


    void setCurrentSprite(const SDL_Rect *currentSprite) override;

    void changeSprite(Side direction) override;

    const Position& getStartingPosition() const override;

    Side getDirection() override;

    void setDirection(Side _direction) override;

private:
    const Position startingPosition;

    Side currentDirection;
};


#endif //TP_NFA037_PHANTOMRED_H
