//
// Created by aperi on 30/11/2022.
//

#ifndef TP_01_HERO_H
#define TP_01_HERO_H


#include "Perso.h"
class Hero :
        public Perso
{
public:
    Hero();
    const SDL_Rect *getCurrentSprite() const;

    void setCurrentSprite(const SDL_Rect *currentSprite);

    const Image &getImage() const;

    void changeSprite(Side direction);

    const Position& getStartingPosition() const;

private:
    Image image;
    SDL_Rect const *currentSprite;
    Position startingPosition;

};


#endif //TP_01_HERO_H
