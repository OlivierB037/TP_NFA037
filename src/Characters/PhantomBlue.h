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

    bool operator==(const PhantomBlue &rhs) const;

    bool operator!=(const PhantomBlue &rhs) const;

    inline static const int PHANTOM_KEY{15635};

    void setCurrentSprite(const SDL_Rect *currentSprite) override;

    void changeSprite(Side direction) override;

    const Position& getStartingPosition() const override;

    Side getDirection() override;

    void setDirection(Side _direction) override;

private:
    const Position startingPosition;

    Side currentDirection;

};


#endif //TP_01_PHANTOM_H
