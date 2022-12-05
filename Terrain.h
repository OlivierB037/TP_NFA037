//
// Created by aperi on 01/12/2022.
//

#ifndef TP_01_TERRAIN_H
#define TP_01_TERRAIN_H
#define BLOC_SIZE 9
#define TERRAIN_WIDTH 56
#define TERRAIN_HEIGHT 62
#define NO_WALL_NEXT 11111

#include "Bloc.h"
#include "Position.h"
#include "Image.h"

class Terrain {
public:
    Terrain();
    Bloc const& getSideBloc(Position const &position, Side direction );
    int getSideLimit(Position const &position,Side direction) const;
private:
    Bloc map[TERRAIN_WIDTH][TERRAIN_HEIGHT];

};


#endif //TP_01_TERRAIN_H
