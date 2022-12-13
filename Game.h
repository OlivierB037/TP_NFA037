//
// Created by aperi on 08/12/2022.
//

#ifndef TP_NFA037_GAME_H
#define TP_NFA037_GAME_H



#include "Labyrinthe.h"
#include "FoodListener.h"
#include "Phantom.h"

class Game : private FoodListener{
public:
    Game(const std::string &labyrinthFilePath);

    void foodEaten(SDL_Rect *foodPosition);


    void start();

private:
    bool arrowPressed();
    std::unique_ptr<std::vector<SDL_Rect*>> emptyRects;
    std::unique_ptr<Hero> hero;
    Phantom *phantoms[4];
    std::shared_ptr<Labyrinthe> labyrinthe;


};


#endif //TP_NFA037_GAME_H
