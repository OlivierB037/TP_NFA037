//
// Created by aperi on 01/12/2022.
//

#include "Labyrinthe.h"
#include "Perso.h"
#include "Labyrinth_Exception.h"
#include "Wall.h"
#include "Food.h"
#include "Fruit.h"
#include <fstream>
#include <iostream>

#include <SDL.h>
template<typename T>
bool Labyrinthe::instanceOf(Bloc *trgt)
{
    return dynamic_cast<T*>(trgt);
}
//Labyrinthe::Labyrinthe() : DIMENSION_X(56), DIMENSION_Y(62) {
//
////    for (int x = 0; x < std::size(map) ; x++) {
////
////        for (int y = 0; y< std::size(*map);y++) {
////            map[x][y] = new Bloc(false);
////        }
////    }
//    map = new Bloc*[DIMENSION_X];
//    for (int x =0; x < DIMENSION_X ; x++) {
//        map[x] = new Bloc[DIMENSION_Y];
//
//    }
//
//    //bordures horizontales
//    for (int y = 0; y < DIMENSION_Y; y++) {
//        map[0][y].setCrossable(true);
//        map[DIMENSION_X - 1][y].setCrossable(true);
//
//    }
//
//    //bordures verticales
//    for (int x = 0; x < DIMENSION_X; ++x) {
//        map[x][0].setCrossable(false);
//        map[x][DIMENSION_Y - 1].setCrossable(false);
//    }
//
//
//}

Bloc const *Labyrinthe::getSideBloc(const Position &position, Side direction) {
    if (direction == LEFT || direction == UP) {
        return map[position.x / BLOC_SIZE][position.y / BLOC_SIZE];
    }
    else{
        return map[(position.x + CHARACTER_SIZE - 1) / BLOC_SIZE][(position.y + CHARACTER_SIZE - 1) / BLOC_SIZE];
    }
}

int Labyrinthe::getSideLimit(const Position &position, Side direction, SDL_Window *window) const {
    switch (direction) {// inclure constante de retour indiquant le nombre de pixel manquants pour pouvoir tourner
        case LEFT: {
            if (!(map[position.x / BLOC_SIZE][position.y / BLOC_SIZE]->isCrossable())) { // is the player already inside a crossable
//                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","inside a wall",window);

                return -1;
            }
//            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","crossable on right bloc 1",window);

            int leftBlocX = (position.x / BLOC_SIZE) - 1;
            int leftBlocY = position.y / BLOC_SIZE;
            return (!(map[leftBlocX][leftBlocY]->isCrossable()) || !(map[leftBlocX][leftBlocY + 1]->isCrossable()) ||
                            !(map[leftBlocX][leftBlocY + 2]->isCrossable()) || !(map[leftBlocX][leftBlocY + 3]->isCrossable())) ? position.x - (position.x % BLOC_SIZE) : NO_WALL_NEXT;
            //TODO reprendre autres directions pour gérer différents blocs
        }
        case RIGHT: {
            if (!(map[(position.x + CHARACTER_SIZE - 1) / BLOC_SIZE][position.y / BLOC_SIZE]->isCrossable())) {
                return -1;
            }
            int rightBlocX = ((position.x + CHARACTER_SIZE - 1) / BLOC_SIZE) + 1;
            int rightBlocY = position.y / BLOC_SIZE;
            if (!(map[rightBlocX][rightBlocY]->isCrossable())){
//                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","crossable on right bloc 0",window);
                return ((position.x + CHARACTER_SIZE - 1) + (BLOC_SIZE - (position.x + CHARACTER_SIZE - 1) % (BLOC_SIZE)));
            }
            else if (!(map[rightBlocX][rightBlocY + 1]->isCrossable())){
//                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","crossable on right bloc 1",window);
                return ((position.x + CHARACTER_SIZE - 1) + (BLOC_SIZE - (position.x + CHARACTER_SIZE - 1) % (BLOC_SIZE)));
            }
            else if (!(map[rightBlocX][rightBlocY + 2]->isCrossable())){
//                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","crossable on right bloc 2",window);
                return ((position.x + CHARACTER_SIZE - 1) + (BLOC_SIZE - (position.x + CHARACTER_SIZE - 1) % (BLOC_SIZE)));

            }
            else if (!(map[rightBlocX][rightBlocY + 3]->isCrossable())){
//                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","crossable on right bloc 3",window);
                return ((position.x + CHARACTER_SIZE - 1) + (BLOC_SIZE - (position.x + CHARACTER_SIZE - 1) % (BLOC_SIZE)));

            }
            else{
                return NO_WALL_NEXT;
            }
//            return ((map[rightBlocX][rightBlocY].isWall()) || (map[rightBlocX][rightBlocY + 1].isCrossable()) ||
//                    map[rightBlocX][rightBlocY + 2].isWall() || map[rightBlocX][rightBlocY + 3].isCrossable()) ?
//                   (((position.x + CHARACTER_SIZE - 1) / BLOC_SIZE) + 1) * BLOC_SIZE : NO_WALL_NEXT;
        }
        case UP: {
            if (!(map[position.x / BLOC_SIZE][position.y / BLOC_SIZE]->isCrossable())) { // is the player already inside a crossable
                return -1;
            }
            int upBlocX = position.x / BLOC_SIZE;
            int upBlocY = (position.y / BLOC_SIZE) - 1;
            return (!(map[upBlocX][upBlocY]->isCrossable()) || !(map[upBlocX + 1][upBlocY]->isCrossable()) ||
                    !(map[upBlocX + 2][upBlocY]->isCrossable()) || !(map[upBlocX + 3][upBlocY]->isCrossable())) ?
                    position.y - (position.y % BLOC_SIZE) : NO_WALL_NEXT;
        }
        case DOWN: {

            if (!(map[position.x / BLOC_SIZE][(position.y + CHARACTER_SIZE - 1) / BLOC_SIZE]->isCrossable())) {
                return -1;
            }
            int downBlocX = position.x / BLOC_SIZE;
            int downBlocY = ((position.y + CHARACTER_SIZE - 1) / BLOC_SIZE) + 1;
            return (!(map[downBlocX][downBlocY]->isCrossable()) || !(map[downBlocX + 1][downBlocY]->isCrossable()) ||
                    !(map[downBlocX + 2][downBlocY]->isCrossable()) || !(map[downBlocX + 3][downBlocY]->isCrossable())) ?
                   ((position.y + CHARACTER_SIZE - 1) + (BLOC_SIZE - (position.y + CHARACTER_SIZE - 1) % (BLOC_SIZE))) : NO_WALL_NEXT;
        }
        default:
            return -1;
    }
}

Labyrinthe::Labyrinthe(const std::string& fileName, int terrain_width, int terrain_height, SDL_Window *window):
        DIMENSION_X(terrain_width), DIMENSION_Y(terrain_height), door{nullptr, nullptr, nullptr, nullptr}
{
    std::ifstream fileReader {fileName} ;
    std::string line;
    map = new Bloc**[DIMENSION_X];
    for (int x =0; x < DIMENSION_X ; x++) {
        map[x] = new Bloc*[DIMENSION_Y];

    }

    int doorIndex = 0;
    int doorY = -1;
    for (int y = 0; y < DIMENSION_Y; ++y) {
        std::getline(fileReader, line);
        if(std::size(line) != DIMENSION_X){
            throw Labyrinth_Exception("terrain width error (too many columns)");
        }
        for (int x = 0; x < DIMENSION_X; ++x) {

            if(line[x] == '#') {
                map[x][y] = new Wall();

            }
            else if(line[x] == '_'){
                //map[x][y].setCrossable(true);
                //const char c[] = {static_cast<char>('0' + ((char)doorIndex)),'-',static_cast<char>('0'+ ((char)doorY)),'\0'};


                if(door[0] == nullptr) { //first door bloc not set
                    if (line[x+1] == '_'){ //horizontal door
                        for (int i = 0; i < 4; ++i) {
                            if (line[x + i] == '_'){
                                map[x+i][y] = new Door(false);
                                door[i] = map[x + i][y];


                            }
                            else{
                                throw Labyrinth_Exception("doors format error : not enough door blocs (horizontal door detected)" );
                            }
                        }
                        x += 3;
                    }
                    else{// vertical door

                        doorY = y;
                        map[x][y] = new Door(false);
                        door[doorIndex] = map[x][y];

                        doorIndex++;
                    }


                }
                else{
                    if (door[doorIndex] == nullptr){

                       if(doorY == y - 1){
                           doorY = y;
                           map[x][y] = new Door(false);
                           door[doorIndex] = map[x][y];

                           doorIndex++;
                        }else{
                           throw Labyrinth_Exception("doors format error : not enough door blocs (vertical door detected)" );

                        }
                    }else {
                        throw Labyrinth_Exception("multiple doors error (all 4 door blocs already set)");
                    }
                }
            }
            else if (line[x] == '.'){
                map[x][y] = new Food();
            }
            else{
                map[x][y] = new Bloc(true);
            }

        }
    }
    if (!(fileReader.eof() || fileReader.fail())){
        throw Labyrinth_Exception("terrain height error (too many lines)");
    }
    if (door[0] == nullptr){
        throw Labyrinth_Exception("no door detected");
    }

}

Bloc const * const*Labyrinthe::getDoor() const {
    return door;
}

void Labyrinthe::setDoor(bool open) {
    for (int i = 0; i < 4; ++i) {
        door[i]->setCrossable(open);
    }
}

int Labyrinthe::checkFood(Hero &hero, FoodListener &listener) {
    //TODO overload == pour vérifier si Bloc instanceof Food
    int blocX = hero.getPosition().x / BLOC_SIZE;
    int blocY = hero.getPosition().y / BLOC_SIZE;
    if (instanceOf<Food>(map[blocX + 1][blocY + 1])){
        return PILL_EATEN;
    }
    else if(instanceOf<Fruit>(map[blocX + 1][blocY + 1])) {
        return FRUIT_EATEN;
    }
}









