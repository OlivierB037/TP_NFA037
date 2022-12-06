//
// Created by aperi on 30/11/2022.
//

#ifndef TP_01_MOUVEMENT_H
#define TP_01_MOUVEMENT_H

#define MOVING_SCALE 3
#define SPRITE_RATE 3
#include "Image.h"
#include "Perso.h"
#include "Terrain.h"

class Mouvement {
public:

    static void move(Side side, Perso &perso,Terrain const &terrain, SDL_Window *window);
private:
    static bool collision(Position const &position, Side direction,Terrain const &terrain);
};


#endif //TP_01_MOUVEMENT_H
