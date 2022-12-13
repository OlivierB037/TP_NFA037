//
// Created by aperi on 13/12/2022.
//

#ifndef TP_NFA037_PHANTOMPINK_H
#define TP_NFA037_PHANTOMPINK_H


#include "Phantom.h"

class PhantomPink  : public Phantom{
public:
    PhantomPink();

    const SDL_Rect *getCurrentSprite() const;

    void setCurrentSprite(const SDL_Rect *currentSprite);

    const Image &getImage() const;

    void changeSprite(Side direction);

private:
    Image image;
    SDL_Rect const *currentSprite;

};



#endif //TP_NFA037_PHANTOMPINK_H
