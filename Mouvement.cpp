//
// Created by aperi on 30/11/2022.
//

#include "Mouvement.h"

//TODO: si appui sur deux touches en meme temps maintenir mouvement tant que 2ème direction non disponible

template<typename T>
bool Mouvement::instanceOf(Perso *trgt) {
    return dynamic_cast<T*>(trgt);
}

bool Mouvement::move(Side direction, Perso &perso, Labyrinthe &terrain, SDL_Window *window, Game &game) {

    switch (direction) {
        case LEFT: {
//            char* msg = new char[90];
//            sprintf(msg," left up corner = %d right up corner = %d",perso.getPosition().x,(perso.getPosition().x + (CHARACTER_SIZE -1 )));
//            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message",msg,window);
            int leftXLimit = terrain.getSideLimit(perso.getPosition(), direction, window);


            if (leftXLimit == -1){
                //TODO: prendre en compte perso dans le mur
                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a crossable ?",window);
                return false;

            }
            else if (leftXLimit == NO_WALL_NEXT || leftXLimit <= (perso.getPosition().x - MOVING_SCALE)) {
                perso.incrementX(-MOVING_SCALE);
                if (perso.getStepCount() >= SPRITE_RATE ) {
                    //changer de sprite
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","sprite change",window);
                    perso.changeSprite(direction);
                    perso.setStepCount(0);
                }
                perso.incrementStepCount();
            }
            break;
        }
        case RIGHT: {
            int rightXLimit = terrain.getSideLimit(perso.getPosition(), direction, window);
            if (rightXLimit == -1){
//                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a crossable ?",window);
                return false;

            }
            else if (rightXLimit == NO_WALL_NEXT || rightXLimit > ((perso.getPosition().x + (CHARACTER_SIZE -1)) + MOVING_SCALE)) {
                perso.incrementX(+MOVING_SCALE);

                if (perso.getStepCount() >= SPRITE_RATE) {
                    perso.changeSprite(direction);
                    perso.setStepCount(0);

                }
                perso.incrementStepCount();




            }
            else{
//                char* msg = new char[90];
//                sprintf(msg,"xlimit = %d left up corner = %d right up corner = %d",rightXLimit,perso.getPosition().x,(perso.getPosition().x + (CHARACTER_SIZE -1 )));
//                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message",msg,window);
            }
            break;


        }
        case UP:{
            int upYLimit = terrain.getSideLimit(perso.getPosition(), direction, window);
            if (upYLimit == -1){
//                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a crossable ?",window);
                return false;


            }
            else if (upYLimit == NO_WALL_NEXT || upYLimit <= (perso.getPosition().y - MOVING_SCALE)) {
                perso.incrementY(-MOVING_SCALE);
                if (perso.getStepCount() == SPRITE_RATE) {
                    perso.changeSprite(direction);
                    perso.setStepCount(0);

                }
                perso.incrementStepCount();
            }
            break;
        }
        case DOWN:{
            int downYLimit = terrain.getSideLimit(perso.getPosition(), direction, window);
            if (downYLimit == -1){
//                SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a crossable ?",window);
                return false;

            }
            else if (downYLimit == NO_WALL_NEXT || downYLimit >= ((perso.getPosition().y + (CHARACTER_SIZE -1 )) + MOVING_SCALE)) {
                perso.incrementY(+MOVING_SCALE);
                if (perso.getStepCount() == SPRITE_RATE) {
                    perso.changeSprite(direction);
                    perso.setStepCount(0);

                }
                perso.incrementStepCount();



                break;
            }
        }
        default:
            break;
    }
    if (instanceOf<Hero>(&perso)) {
//        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","pero is instance of hero",window);
        switch (terrain.checkFood(dynamic_cast<Hero &>(perso), game)) {
            case Labyrinthe::FRUIT_EATEN:{
                //TODO activer invincibilité hero
                break;
            }
            case Labyrinthe::PILL_EATEN:{
                //TODO modifier nombre de pill restantes
                break;
            }
        }
    }
        return true;
    }
bool Mouvement::move(Side currentDirection, Side pendingDirection, Perso &perso, Labyrinthe &terrain, SDL_Window *window, Game &game) {
    if (terrain.getSideLimit(perso.getPosition(),pendingDirection, window) == NO_WALL_NEXT) {
        switch (currentDirection) {
            case LEFT: {

                int leftXLimit = terrain.getSideLimit(perso.getPosition(), currentDirection, window);
                if (leftXLimit == -1){
                    //TODO: prendre en compte perso dans le mur
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a crossable ?",window);
                    return false;

                }
                else if (leftXLimit == NO_WALL_NEXT || leftXLimit <= (perso.getPosition().x - MOVING_SCALE)) {
                    perso.incrementX(-MOVING_SCALE);
                    if (perso.getStepCount() >= SPRITE_RATE ) {
                        //changer de sprite
                        //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","sprite change",window);
                        perso.changeSprite(currentDirection);
                        perso.setStepCount(0);
                    }
                    perso.incrementStepCount();
                }
                break;
            }
            case RIGHT: {
                int rightXLimit = terrain.getSideLimit(perso.getPosition(), currentDirection, window);
                if (rightXLimit == -1){
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a crossable ?",window);
                    return false;

                }
                else if (rightXLimit == NO_WALL_NEXT || rightXLimit > ((perso.getPosition().x + (CHARACTER_SIZE -1)) + MOVING_SCALE)) {
                    perso.incrementX(+MOVING_SCALE);

                    if (perso.getStepCount() >= SPRITE_RATE) {
                        perso.changeSprite(currentDirection);
                        perso.setStepCount(0);

                    }
                    perso.incrementStepCount();




                }
                else{
//                    char* msg = new char[90];
//                    sprintf(msg,"xlimit = %d left up corner = %d right up corner = %d",rightXLimit,perso.getPosition().x,(perso.getPosition().x + (CHARACTER_SIZE -1 )));
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message",msg,window);
                }
                break;


            }
            case UP:{
                int upYLimit = terrain.getSideLimit(perso.getPosition(), currentDirection, window);
                if (upYLimit == -1){
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a crossable ?",window);
                    return false;


                }
                else if (upYLimit == NO_WALL_NEXT || upYLimit <= (perso.getPosition().y - MOVING_SCALE)) {
                    perso.incrementY(-MOVING_SCALE);
                    if (perso.getStepCount() == SPRITE_RATE) {
                        perso.changeSprite(currentDirection);
                        perso.setStepCount(0);

                    }
                    perso.incrementStepCount();
                }
                break;
            }
            case DOWN:{
                int downYLimit = terrain.getSideLimit(perso.getPosition(), currentDirection, window);
                if (downYLimit == -1){
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a crossable ?",window);
                    return false;

                }
                else if (downYLimit == NO_WALL_NEXT || downYLimit >= ((perso.getPosition().y + (CHARACTER_SIZE -1 )) + MOVING_SCALE)) {
                    perso.incrementY(+MOVING_SCALE);
                    if (perso.getStepCount() == SPRITE_RATE) {
                        perso.changeSprite(currentDirection);
                        perso.setStepCount(0);

                    }
                    perso.incrementStepCount();



                    break;
                }
            }
            default:
                break;


        }
    }
    else{
        move(currentDirection,perso,terrain,window,game);
        return false;
    }
    return true;
}



bool Mouvement::collision(const Position &position, Side direction, const Labyrinthe &terrain) {
    return false;
}






