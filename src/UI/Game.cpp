//
// Created by aperi on 08/12/2022.
//

#include "Game.h"
#include <fstream>

#include "../Characters/Hero.h"
#include "../Core/Mouvement.h"
#include "../Logger.h"
#include "../Labyrinth_Exception.h"
#include "Key.h"
#include "Arrows.h"
#include "../Environment/Food.h"


Game::Game(const std::string& labyrinthFilePath) {
    std::vector<SDL_Rect*> vector;
    this->emptyRects = std::make_unique<std::vector<SDL_Rect*>>(vector);

    Hero _hero;
    this->hero = std::make_unique<Hero>(_hero);
}
//TODO déplacer initialisation labyrinthe dans constructeur
void Game::foodEaten(int positionX, int positionY, int foodCount) {
//    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "message", "foodEaten called", window);
    this->emptyRects->push_back(new SDL_Rect({positionX,positionY,Food::FOOD_WIDTH,Food::FOOD_HEIGHT}));
    if (foodCount == 0){
//        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Victory", "You win !", window);
        //TODO créer fonction win
    }
}



void Game::start(Window *window) {

    try {
        labyrinthe = std::make_shared<Labyrinthe>("resources/terrain.txt", 56, 62, window->getWindow());
        //Labyrinthe labyrinthe;

    } catch (Labyrinth_Exception const &e) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "message", e.what(), window->getWindow());
    }

    int continuer = 1;
//    SDL_RenderClear(renderer);
//    SDL_RenderCopy(renderer, backgroundFull, NULL, NULL);
//    SDL_RenderCopy(renderer, persosTexture, hero->getImage().getBaseRect(LEFT), &(hero->getPosition()));
//    SDL_RenderPresent(renderer);
    SDL_EventState(SDL_MOUSEMOTION, SDL_IGNORE);



    SDL_Event event;


    bool timing = false;

//    Logger::getInstance()->newLogSection();

    // créer classe keys

    Key *lastArrowPressed = Arrows::getLeftKey();
//    Arrows::getLeftKey()->setPressed(true);
//    char *msg = new char[90];
//    sprintf(msg, "key pressed in arrows: %d ; in getInstance : ", lastArrowPressed->isPressed());
//    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "message", msg, window->getWindow());
    Side currentDirection = NONE;
//    Key* keys[] {&leftKey, &rightKey, &upKey,&downKey};
    while (continuer)
    {

        SDL_PollEvent(&event);

        switch (event.type)
        {

            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;

                    case SDLK_LEFT: {
                        //Logger::getInstance()->addInfoLog("left pressed");
                        if (currentDirection == NONE) {
                            currentDirection = LEFT;
                        }

                        lastArrowPressed = Arrows::getDirectionKey(LEFT);
                        Arrows::getLeftKey()->setPressed(true);
//                        char *msg = new char[90];
//                        sprintf(msg, "key pressed in arrows: %p ispressed = %p : ", lastArrowPressed, Arrows::getLeftKey());
//                        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "message", msg, window->getWindow());
                        break;
                    }
                    case SDLK_RIGHT:
                        //Logger::getInstance()->addInfoLog("right pressed");
                        if (currentDirection == NONE){
                            currentDirection = RIGHT;
                        }
                        Arrows::getRightKey()->setPressed(true);
                        lastArrowPressed = Arrows::getDirectionKey(RIGHT);

                        break;
                    case SDLK_UP:
                        //Logger::getInstance()->addInfoLog("up pressed");
                        if (currentDirection == NONE){
                            currentDirection = UP;
                        }
                        Arrows::getUpKey()->setPressed(true);
                        lastArrowPressed = Arrows::getDirectionKey(UP);
                        break;
                    case SDLK_DOWN:
                        //Logger::getInstance()->addInfoLog("down pressed");
                        if (currentDirection == NONE){
                            currentDirection = DOWN;
                        }
                        Arrows::getDownKey()->setPressed(true);
                        lastArrowPressed = Arrows::getDirectionKey(DOWN);
                        break;



                }

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {

                    case SDLK_LEFT:
                        Arrows::getLeftKey()->setPressed(false);


                        break;
                    case SDLK_RIGHT:
                        Arrows::getRightKey()->setPressed(false);


                        break;
                    case SDLK_UP:
                        Arrows::getUpKey()->setPressed(false);

                        break;
                    case SDLK_DOWN:
                        Arrows::getDownKey()->setPressed(false);


                        break;


                }

                break;

        }

        //envoyer le sdl_rect a mouvement pour changer partie sprite affichée

        //SDL_UpdateTexture(persosTexture, NULL, imageZabeth->pixels, imageZabeth->pitch);
        if (arrowPressed()){


//            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","msg",window->getWindow());
            //TODO ajouter acceleration (delay ou Move_SCALE) ou detection appui court
            //TODO: revoir appuis multiples (créer fonction verifiant si touche autre que  currentDirection est appuyée )
            //TODO réfléchir  fonction comparant a chaque itération quelles touches sont appuyées et créer file d'attente
            if (currentDirection != NONE){
                if (currentDirection == lastArrowPressed->getDirection() ) {
                    if(SDL_GetKeyboardState(nullptr)[lastArrowPressed->getScanCode()]) {


                        Mouvement::move(currentDirection, *(hero), *(labyrinthe), window->getWindow(), *this);
                    }
                } else {
                    if (SDL_GetKeyboardState(nullptr)[Arrows::getDirectionKey(currentDirection)->getScanCode()] && SDL_GetKeyboardState(nullptr)[lastArrowPressed->getScanCode()]){
//                        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "message", "other direction reached", window->getWindow());
                        if( Mouvement::move(currentDirection, lastArrowPressed->getDirection(), *hero, *labyrinthe, window->getWindow(), *this)) {
                            currentDirection = lastArrowPressed->getDirection();
                        }
                    }
                    else if (SDL_GetKeyboardState(nullptr)[lastArrowPressed->getScanCode()]){
                        currentDirection = lastArrowPressed->getDirection();
                        Mouvement::move(currentDirection, *hero, *labyrinthe, window->getWindow(), *this);
                    }
                }
            }

//            if(SDL_GetKeyboardState(nullptr)[lastArrowPressed->getScanCode()]) {
//
//                Mouvement::move(currentDirection, hero, labyrinthe, window->getWindow());
//            }
//            Mouvement::move(lastArrowPressed->getDirection(), hero, labyrinthe, window->getWindow());
        }
        else{
            currentDirection = NONE;
            hero->setCurrentSprite(hero->getImage().getBaseRect(lastArrowPressed->getDirection()));
            hero->setStepCount(SPRITE_RATE);
        }


        if (!(emptyRects->empty())){
            window->updateTextures(*hero,labyrinthe->getPhantoms());

        }
        else{
            window->updateTextures(*hero,labyrinthe->getPhantoms(),*emptyRects);
        }
//        SDL_Rect * test = new SDL_Rect({0,0,81,81});
//        SDL_RenderCopy(renderer,backgroundEmpty,test,test);

        SDL_Delay(20);

    }


}
bool Game::arrowPressed(){
    return (SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_UP] ||
            SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_DOWN] ||
            SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_LEFT] ||
            SDL_GetKeyboardState(nullptr)[SDL_SCANCODE_RIGHT]);



}
