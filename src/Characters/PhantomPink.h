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

    bool operator==(const PhantomPink &rhs) const;

    bool operator!=(const PhantomPink &rhs) const;

    void setCurrentSprite(const SDL_Rect *currentSprite) override;

    void changeSprite(Side direction) override;

    const Position& getStartingPosition() const override;

    Side getDirection() override;

    void setDirection(Side _direction) override;

private:
    const Position startingPosition;

    Side currentDirection;

};



#endif //TP_NFA037_PHANTOMPINK_H
