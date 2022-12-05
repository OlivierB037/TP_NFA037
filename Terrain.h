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

class Terrain {
public:

    Terrain();
    const int TERRAIN_WIDTH;
    const int TERRAIN_HEIGHT;
    Terrain(std::string fileName, int terrain_width, int terrain_height);
    Bloc const& getSideBloc(Position const &position, Side direction );
    int getSideLimit(Position const &position,Side direction) const;
    Bloc const * const*getDoor() const;
private:
    Bloc **map;
    Bloc const *door[4];

};


#endif //TP_01_TERRAIN_H
