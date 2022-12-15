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
#include <thread>

/*
 * vérifie si le Bloc trgt est une instance de T
 */
template<typename T>
bool Labyrinthe::instanceOf(Bloc *trgt)
{
    return dynamic_cast<T*>(trgt);
}

Bloc const *Labyrinthe::getSideBloc(const Position &position, Side direction) {
    if (direction == LEFT || direction == UP) {
        return map[position.x / BLOC_SIZE][position.y / BLOC_SIZE];
    }
    else{
        return map[(position.x + CHARACTER_SIZE - 1) / BLOC_SIZE][(position.y + CHARACTER_SIZE - 1) / BLOC_SIZE];
    }
}

/*
 * renvoie la valeur X ou Y (selon la direction) du mur au bloc suivant ou une
 * constante si le chemin est libre
 */
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

Labyrinthe::Labyrinthe(const std::string& fileName, int terrain_width, int terrain_height, SDL_Window *_window):
        DIMENSION_X(terrain_width), DIMENSION_Y(terrain_height), door{nullptr, nullptr, nullptr, nullptr}
{
    this->window = _window;
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
                foodCount++;
                map[x][y] = new Food();
            }
            else if (line[x] == 'o'){

                map[x][y] = new Fruit();
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
/*
     * vérifie si la position de pacman correspond à la position d'un "Food"
     * Le résultat est envoyé à la classe Game via FoodListener
     */
int Labyrinthe::checkFood(Hero &hero, FoodListener &listener) {
    //TODO overload == pour vérifier si Bloc instanceof Food
    //TODO uytiliser futur fonction bloc->coordonnée pour parametre listener
    int blocX = hero.getPosition().x / BLOC_SIZE;
    int blocY = hero.getPosition().y / BLOC_SIZE;
//    char* msg = new char[90];
//    sprintf(msg,"blocX = %d blocY = %d ",blocX,blocY);
//    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"msg",msg,window);
    if (instanceOf<Food>(map[blocX + 1][blocY + 1]) && !( ((Food*)map[blocX + 1][blocY + 1])->isEaten() ) ){
//        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"msg","bloc is food",window);
        ((Food*)map[blocX + 1][blocY + 1])->setEaten(true);
        foodCount--;
        listener.foodEaten(((blocX+1) * BLOC_SIZE),((blocY+1) * BLOC_SIZE),foodCount);
        return PILL_EATEN;
    }
    else if(instanceOf<Fruit>(map[blocX + 1][blocY + 1])&& !( ((Fruit*)map[blocX + 1][blocY + 1])->isEaten() ) ) {
        ((Fruit*)map[blocX + 1][blocY + 1])->setEaten(true);
        listener.foodEaten(((blocX+1) * BLOC_SIZE),((blocY+1) * BLOC_SIZE),foodCount);
        /*
         * demarrage de l'invincibilité, l'usage du mutex et de try_lock permet de ne pas relancer l'ivincibilité une
         * deuxième fois si le joueur mange un fruit pendant qu'un autre est déja actif
         */
        std::thread t([&]() -> void {
            if(vulnerability_lock.try_lock()) {
                this->startPhantomsVulnerability();
                SDL_Delay(10000);
                this->endPhantomsVulnerability();
                vulnerability_lock.unlock();
                return;
            }
        });
        t.detach();
        return FRUIT_EATEN;

    }
    return 0;
}

int Labyrinthe::getPillCount() const {
    return foodCount;
}

void Labyrinthe::setPillCount(int foodCount) {
    Labyrinthe::foodCount = foodCount;
}

void Labyrinthe::incrementPillCount(int value) {
    this->foodCount += value;
}
//TODO rendre thread safe
void Labyrinthe::startPhantomsVulnerability() {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","phantoms are vulnerable",window);


}

void Labyrinthe::endPhantomsVulnerability() {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","phantoms are not vulnerable",window);
}

void Labyrinthe::checkCollision(Hero &hero, Side &direction) {

}

Labyrinthe::~Labyrinthe() {
    if (door != nullptr){
        delete[] *door;
    }
    if (map != nullptr){
        for (int x = 0; x < DIMENSION_X; ++x) {
            for (int y = 0; y < DIMENSION_Y; ++y) {
                if (map[x][y] != nullptr) {
                    delete map[x][y];

                }

            }
        }
    }

}

bool Labyrinthe::operator==(const Labyrinthe &rhs) const {
    return DIMENSION_X == rhs.DIMENSION_X &&
           DIMENSION_Y == rhs.DIMENSION_Y &&
           phantomBlue == rhs.phantomBlue &&
           phantomRed == rhs.phantomRed &&
           phantomPink == rhs.phantomPink &&
           phantomOrange == rhs.phantomOrange &&
           phantoms == rhs.phantoms &&
           map == rhs.map &&
           door[0] == rhs.door[0] &&
           door[1] == rhs.door[1] &&
           door[2] == rhs.door[2] &&
           door[3] == rhs.door[3] &&
           foodCount == rhs.foodCount &&
           window == rhs.window;
}

bool Labyrinthe::operator!=(const Labyrinthe &rhs) const {
    return DIMENSION_X != rhs.DIMENSION_X ||
           DIMENSION_Y != rhs.DIMENSION_Y ||
           phantomBlue != rhs.phantomBlue ||
           phantomRed != rhs.phantomRed ||
           phantomPink != rhs.phantomPink ||
           phantomOrange != rhs.phantomOrange ||
           phantoms != rhs.phantoms ||
           map != rhs.map ||
           door[0] != rhs.door[0] ||
           door[1] != rhs.door[1] ||
           door[2] != rhs.door[2] ||
           door[3] != rhs.door[3] ||
           foodCount != rhs.foodCount ||
           window != rhs.window;
}

Labyrinthe &Labyrinthe::operator=(const Labyrinthe &rhs) {
    if (*this == rhs){
        return *this;
    }
    if (rhs.DIMENSION_X == DIMENSION_X && rhs.DIMENSION_Y == DIMENSION_Y) {
        for (int x = 0; x < DIMENSION_X; ++x) {
            for (int y = 0; y < DIMENSION_Y; ++y) {
                if (map[x][y] != nullptr) {
                    delete map[x][y];

                }
                map[x][y] = rhs.map[x][y];
            }
        }
    }
    else{
        DIMENSION_X = rhs.DIMENSION_X;
        DIMENSION_Y = rhs.DIMENSION_Y;
        delete map;
        map = new Bloc**[DIMENSION_X];

        for (int x = 0; x < DIMENSION_X; ++x) {
            map[x] = new Bloc*[DIMENSION_Y];
            for (int y = 0; y < DIMENSION_Y; ++y) {

                map[x][y] = rhs.map[x][y];
            }
        }

    }


    for (int i = 0; i < 4; ++i) {
        if(door[i] != nullptr) {
            delete door[i];
        }
        door[i] = new Door(rhs.door[i]);
    }
    /*
     * dans le cas ou un labyrinthe serait réaffecté (peu probable) les phantomes restent les mêmes
     * ils seront probablement déplacés dans Game avec le Hero ou faits Singletons
     */
    foodCount = rhs.foodCount;



}

int Labyrinthe::getDimensionX() const {
    return DIMENSION_X;
}

int Labyrinthe::getDimensionY() const {
    return DIMENSION_Y;
}

Labyrinthe::Labyrinthe(const Labyrinthe& labyrinthe)
: phantomRed(labyrinthe.phantomRed), phantomBlue(labyrinthe.phantomBlue),
    phantomPink(labyrinthe.phantomPink), phantomOrange(labyrinthe.phantomOrange),
    phantoms(labyrinthe.phantoms), foodCount(labyrinthe.foodCount),DIMENSION_X(labyrinthe.DIMENSION_X),
    DIMENSION_Y(labyrinthe.DIMENSION_Y), door{nullptr,nullptr,nullptr,nullptr}, map(nullptr),window(nullptr)
{
    map = new Bloc**[DIMENSION_X];

    for (int x = 0; x < DIMENSION_X; ++x) {
        map[x] = new Bloc*[DIMENSION_Y];
        for (int y = 0; y < DIMENSION_Y; ++y) {

            map[x][y] = labyrinthe.map[x][y];
        }
    }
    for (int i = 0; i < 4; ++i) {
        door[i] = new Door(labyrinthe.door[i]);
    }
    window = labyrinthe.window;
}

Position Labyrinthe::getBlocCoordinates(int blocX, int blocY) {
    return Position(blocX * BLOC_SIZE, blocY * BLOC_SIZE);
}

Bloc *Labyrinthe::getBloc(Position _position) {
    return map[_position.x/CHARACTER_SIZE][_position.y / BLOC_SIZE];
}














