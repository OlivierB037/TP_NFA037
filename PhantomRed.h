//
// Created by aperi on 13/12/2022.
//

#ifndef TP_NFA037_PHANTOMRED_H
#define TP_NFA037_PHANTOMRED_H


#include "Phantom.h"

class PhantomRed  : public Phantom{
public:
    PhantomRed();

    const SDL_Rect *getCurrentSprite() const;

    void setCurrentSprite(const SDL_Rect *currentSprite);

    const Image &getImage() const;

    void changeSprite(Side direction);

private:
    Image image;
    SDL_Rect const *currentSprite;
    bool vulnerable;
    bool alive;

};


#endif //TP_NFA037_PHANTOMRED_H
