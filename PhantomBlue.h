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

    const SDL_Rect *getCurrentSprite() const;

    void setCurrentSprite(const SDL_Rect *currentSprite);

    const Image &getImage() const;

    void changeSprite(Side direction);

private:
    Image image;
    SDL_Rect const *currentSprite;

};


#endif //TP_01_PHANTOM_H
