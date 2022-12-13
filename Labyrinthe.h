//
// Created by aperi on 01/12/2022.
//

#ifndef TP_01_TERRAIN_H
#define TP_01_TERRAIN_H
#define BLOC_SIZE 9


#define NO_WALL_NEXT 11111

#include "Bloc.h"
#include "Position.h"
#include "Image.h"
#include "Door.h"
#include "Hero.h"
#include "FoodListener.h"

class Labyrinthe {
public:
    template<typename T> bool instanceOf(Bloc *trgt);

//    template<typename Lval, typename Rval>
//    bool operator==(Lval &lval, Rval&rval)
    static const int PILL_EATEN {56354};
    static const int FRUIT_EATEN {47854};
    //TODO créer fonctions numero de bloc <-> coordonnées
    //TODO créer template instanceOf
    Labyrinthe() = delete;
    const int DIMENSION_X;
    const int DIMENSION_Y;
    Labyrinthe(const std::string& fileName, int terrain_width, int terrain_height, SDL_Window *window);
    Bloc const* getSideBloc(Position const &position, Side direction );
    int getSideLimit(Position const &position,Side direction,SDL_Window *window) const;
    //TODO: créer callback dans main (futur classe UI) mettant a jour liste des SDL_Rect de field_empty à afficher
    int checkFood(Hero &hero, FoodListener &listener);
    Bloc const * const*getDoor() const;
    void setDoor(bool open);
private:
    Bloc ***map;
    Bloc *door[4];

};


#endif //TP_01_TERRAIN_H