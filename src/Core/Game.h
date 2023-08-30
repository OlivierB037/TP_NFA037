//
// Created by aperi on 08/12/2022.
//

#ifndef TP_NFA037_GAME_H
#define TP_NFA037_GAME_H



#include "Labyrinthe.h"
#include "../Callbacks/FoodListener.h"
#include "../UI/Window.h"
#include "../Callbacks/Phantom_Callback.h"


class Game : public FoodListener, public Vulnerability_Callback, public Phantom_Callback{
public:
    explicit Game(const std::string &labyrinthFilePath);

    void foodEaten(int positionX, int positionY, int foodCount);

    void start(Window *_window);

    void endVulnerability() override;

    void startVulnerability() override;

    void wallCollision(int phantomKey) override;

    void heroCollision() override;

private:
    bool arrowPressed();
    std::map<int, Phantom*> phantoms;
    PhantomBlue phantomBlue;
    PhantomRed phantomRed;
    PhantomPink phantomPink;
    PhantomOrange phantomOrange;
    std::unique_ptr<std::vector<SDL_Rect*>> emptyRects;
    std::unique_ptr<Hero> hero;

    std::shared_ptr<Labyrinthe> labyrinthe;
    Window* window;

};


#endif //TP_NFA037_GAME_H
