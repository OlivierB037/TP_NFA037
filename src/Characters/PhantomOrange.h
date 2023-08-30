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

    void setCurrentSprite(const SDL_Rect *currentSprite) override;

    void changeSprite(Side direction) override;

    const Position& getStartingPosition() const override;

    Side getDirection() override;

    void setDirection(Side _direction) override;

private:
    const Position startingPosition;

    Side currentDirection;
};


#endif //TP_NFA037_PHANTOMORANGE_H
