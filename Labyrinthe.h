//
// Created by aperi on 01/12/2022.
//

#ifndef TP_01_TERRAIN_H
#define TP_01_TERRAIN_H
#define BLOC_SIZE 9


#define NO_WALL_NEXT 11111

#include <map>
#include "Bloc.h"
#include "Position.h"
#include "Image.h"
#include "Door.h"
#include "Hero.h"
#include "FoodListener.h"
#include "Phantom.h"
#include "PhantomBlue.h"
#include "PhantomRed.h"
#include "PhantomPink.h"
#include "PhantomOrange.h"

class Labyrinthe {
public:

    static const int PILL_EATEN {56354};
    static const int FRUIT_EATEN {47854};

    //TODO créer fonctions numero de bloc <-> coordonnées
    //TODO créer template instanceOf
    Labyrinthe() = delete;

    const int DIMENSION_X;
    const int DIMENSION_Y;

    Labyrinthe(const std::string& fileName, int terrain_width, int terrain_height, SDL_Window *_window);

    Bloc const* getSideBloc(Position const &position, Side direction );

    int getSideLimit(Position const &position,Side direction,SDL_Window *window) const;

    int checkFood(Hero &hero, FoodListener &listener);

    Bloc const * const*getDoor() const;

    void setDoor(bool open);

    int getPillCount() const;

    void setPillCount(int foodCount);

    void incrementPillCount(int value = 1);



private:
    void startPhantomsVulnerability();
    PhantomBlue phantomBlue;
    PhantomRed phantomRed;
    PhantomPink phantomPink;
    PhantomOrange phantomOrange;
    //TODO réflechir classe phantoms unique ou mettre les 4 differents dans la map
    //TODO ajouter clé de la map aux classes phantomes
    std::map<int,Phantom*> phantoms;
    Bloc ***map;
    Bloc *door[4];
    template<typename T> bool instanceOf(Bloc *trgt);
    SDL_Window *window;
    int foodCount;
//    template<typename Lval, typename Rval>
//    bool operator==(Lval &lval, Rval&rval)

};


#endif //TP_01_TERRAIN_H
