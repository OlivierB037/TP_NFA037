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


    void setCurrentSprite(const SDL_Rect *currentSprite);



    void changeSprite(Side direction);

private:


};


#endif //TP_01_HERO_H
