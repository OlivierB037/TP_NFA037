//
// Created by aperi on 30/11/2022.
//

#ifndef TP_01_MOUVEMENT_H
#define TP_01_MOUVEMENT_H

#define MOVING_SCALE 3
#define SPRITE_RATE 3
#include "../UI/Sprites.h"
#include "../Characters/Perso.h"
#include "Labyrinthe.h"
#include "../UI/Game.h"

class Mouvement {
public:

    static bool move(Side direction, Perso &perso, Labyrinthe &terrain, SDL_Window *window, Game &game);
    static bool move(Side currentDirection, Side pendingDirection, Perso &perso, Labyrinthe &terrain, SDL_Window *window, Game &game);
private:
    template<typename T> static bool instanceOf(Perso *trgt);
    static bool collision(Position const &position, Side direction, Labyrinthe const &terrain);
};


#endif //TP_01_MOUVEMENT_H
