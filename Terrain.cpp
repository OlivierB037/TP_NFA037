//
// Created by aperi on 01/12/2022.
//

#include "Terrain.h"
#include "Perso.h"
#include <iostream>
#include <SDL.h>

Terrain::Terrain(){

//    for (int x = 0; x < std::size(map) ; x++) {
//
//        for (int y = 0; y< std::size(*map);y++) {
//            map[x][y] = new Bloc(false);
//        }
//    }
    //bordures horizontales
    for (int y = 0; y< std::size(*map);y++) {
        map[0][y].setWall(true);
        map[TERRAIN_WIDTH -1][y].setWall(true);

    }

    //bordures verticales
    for (int x = 0; x < std::size(map); ++x) {
        map[x][0].setWall(true);
        map[x][TERRAIN_HEIGHT -1].setWall(true);
    }


}

Bloc const &Terrain::getSideBloc(const Position &position, Side direction) {
    if (direction == LEFT || direction == UP) {
        return map[position.x / BLOC_SIZE][position.y / BLOC_SIZE];
    }
    else{
        return map[(position.x + CHARACTER_SIZE) / BLOC_SIZE][(position.y + CHARACTER_SIZE) / BLOC_SIZE];
    }
}

int Terrain::getSideLimit(const Position &position, Side direction) const {
    switch (direction) {
        case LEFT:
            if (map[position.x / BLOC_SIZE][position.y / BLOC_SIZE].isWall()){
                return -1;
            }
            return (map[(position.x / BLOC_SIZE) -1][position.y / BLOC_SIZE].isWall()) ? position.x - (position.x % BLOC_SIZE): NO_WALL_NEXT;
            break;
        case RIGHT:
            if (map[(position.x + CHARACTER_SIZE) / BLOC_SIZE][position.y / BLOC_SIZE].isWall()){
                return -1;
            }
            return (map[((position.x + CHARACTER_SIZE) / BLOC_SIZE) + 1][position.y / BLOC_SIZE].isWall()) ? (((position.x + CHARACTER_SIZE) / BLOC_SIZE) + 1) * BLOC_SIZE : NO_WALL_NEXT;
        case UP:
            if (map[position.x / BLOC_SIZE][position.y / BLOC_SIZE].isWall()){
                return -1;
            }
            return (map[position.x / BLOC_SIZE][(position.y / BLOC_SIZE) -1].isWall()) ? position.y - (position.y % BLOC_SIZE): NO_WALL_NEXT;
        case DOWN:
            if (map[position.x / BLOC_SIZE][(position.y + CHARACTER_SIZE) / BLOC_SIZE].isWall()){
                return -1;
            }
            return (map[position.x/ BLOC_SIZE][((position.y + CHARACTER_SIZE) / BLOC_SIZE) + 1].isWall()) ? (position.y + CHARACTER_SIZE) + ((position.y + CHARACTER_SIZE) % BLOC_SIZE) : NO_WALL_NEXT;
    }
}


