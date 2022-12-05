//
// Created by aperi on 01/12/2022.
//

#include "Terrain.h"
#include "Perso.h"
#include "Terrain_Exception.h"
#include <fstream>
#include <iostream>

#include <SDL.h>

constexpr Terrain::Terrain() : TERRAIN_WIDTH(56), TERRAIN_HEIGHT(62) {

//    for (int x = 0; x < std::size(map) ; x++) {
//
//        for (int y = 0; y< std::size(*map);y++) {
//            map[x][y] = new Bloc(false);
//        }
//    }
    map = new Bloc*[TERRAIN_WIDTH];
    for (int x =0; x < TERRAIN_WIDTH ; x++) {
        map[x] = new Bloc[TERRAIN_HEIGHT];

    }

    //bordures horizontales
    for (int y = 0; y< TERRAIN_HEIGHT;y++) {
        map[0][y].setWall(true);
        map[TERRAIN_WIDTH - 1][y].setWall(true);

    }

    //bordures verticales
    for (int x = 0; x < TERRAIN_WIDTH; ++x) {
        map[x][0].setWall(true);
        map[x][TERRAIN_HEIGHT - 1].setWall(true);
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
            return (map[(position.x / BLOC_SIZE) - 1][position.y / BLOC_SIZE].isWall()) ? position.x - (position.x % BLOC_SIZE) : NO_WALL_NEXT;
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
            return (map[position.x / BLOC_SIZE][(position.y / BLOC_SIZE) - 1].isWall()) ? position.y - (position.y % BLOC_SIZE) : NO_WALL_NEXT;
        case DOWN:
            if (map[position.x / BLOC_SIZE][(position.y + CHARACTER_SIZE) / BLOC_SIZE].isWall()){
                return -1;
            }
            return (map[position.x / BLOC_SIZE][((position.y + CHARACTER_SIZE) / BLOC_SIZE) + 1].isWall()) ? (position.y + CHARACTER_SIZE) + ((position.y + CHARACTER_SIZE) % BLOC_SIZE) : NO_WALL_NEXT;
    }
}

Terrain::Terrain(std::string fileName, int terrain_width, int terrain_height):
    TERRAIN_WIDTH(terrain_width), TERRAIN_HEIGHT(terrain_height), door(nullptr)
{
    std::ifstream fileReader {fileName} ;
    std::string line;
    map = new Bloc*[TERRAIN_WIDTH];
    for (int x =0; x < TERRAIN_WIDTH ; x++) {
        map[x] = new Bloc[TERRAIN_HEIGHT];

    }


    for (int y = 0; y < TERRAIN_HEIGHT; ++y) {
        std::getline(fileReader, line);
        if(std::size(line) != TERRAIN_WIDTH){
            throw Terrain_Exception("terrain width error (too many columns)");
        }
        for (int x = 0; x < TERRAIN_WIDTH; ++x) {

            if(line[x] == '#') {
                map[x][y].setWall(true);
            }
            else if(line[x] == '_'){
                if(door == nullptr) {
                    door = &(map[x][y]);
                    map[x][y].setWall(true);
                }
                else{
                    throw Terrain_Exception("multiple doors error");
                }
            }
        }
    }
    if (!(fileReader.eof() || fileReader.fail())){
        throw Terrain_Exception("terrain height error (too many lines)");
    }
    if (door == nullptr){
        throw Terrain_Exception("no door detected");
    }

}

Bloc const *Terrain::getDoor() const {
    return door;
}




