//
// Created by aperi on 30/11/2022.
//

#include "Mouvement.h"


void Mouvement::move(Side side, Perso &perso,Terrain const &terrain, SDL_Window *window) {

        switch (side) {
            case LEFT: {

                int leftXLimit = terrain.getSideLimit(perso.getPosition(), side);
                if (leftXLimit == -1){
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a wall ?",window);
                }
                else if (leftXLimit == NO_WALL_NEXT || leftXLimit <= (perso.getPosition().x - MOVING_SCALE)) {
                    perso.incrementX(-MOVING_SCALE);
                    if (perso.getStepCount() >= SPRITE_RATE ) {
                        //changer de sprite
                        //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","sprite change",window);
                        perso.changeSprite(side);
                        perso.setStepCount(0);
                    }
                    perso.incrementStepCount();
                }
                break;
            }
            case RIGHT: {
                int rightXLimit = terrain.getSideLimit(perso.getPosition(), side);
                if (rightXLimit == -1){
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a wall ?",window);
                }
                else if (rightXLimit == NO_WALL_NEXT || rightXLimit > ((perso.getPosition().x + (CHARACTER_SIZE -1)) + MOVING_SCALE)) {
                    perso.incrementX(+MOVING_SCALE);
//                    char* msg = new char[90];
//                    sprintf(msg,"xlimit = %d left up corner = %d right up corner = %d",rightXLimit,perso.getPosition().x,(perso.getPosition().x + (CHARACTER_SIZE )));
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message",msg,window);
                    if (perso.getStepCount() >= SPRITE_RATE) {
                        perso.changeSprite(side);
                        perso.setStepCount(0);

                    }
                    perso.incrementStepCount();



                    break;
                }

//                else{
//                    char* msg = new char[90];
//                    sprintf(msg,"limite atteinte a droite: xmax =%d x = %d + size = %d",rightXLimit,perso.getPosition().x,(perso.getPosition().x + (CHARACTER_SIZE )));
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message",msg,window);
//                }
            }
            case UP:{
                int upYLimit = terrain.getSideLimit(perso.getPosition(), side);
                if (upYLimit == -1){
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a wall ?",window);
                }
                else if (upYLimit == NO_WALL_NEXT || upYLimit <= (perso.getPosition().y - MOVING_SCALE)) {
                    perso.incrementY(-MOVING_SCALE);
                    if (perso.getStepCount() == SPRITE_RATE) {
                        perso.changeSprite(side);
                        perso.setStepCount(0);

                    }
                    perso.incrementStepCount();
                }
                break;
            }
            case DOWN:{
                int downYLimit = terrain.getSideLimit(perso.getPosition(), side);
                if (downYLimit == -1){
//                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"message","what are you doing inside a wall ?",window);
                }
                else if (downYLimit == NO_WALL_NEXT || downYLimit >= ((perso.getPosition().y + (CHARACTER_SIZE -1 )) + MOVING_SCALE)) {
                    perso.incrementY(+MOVING_SCALE);
                    if (perso.getStepCount() == SPRITE_RATE) {
                        perso.changeSprite(side);
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



bool Mouvement::collision(const Position &position, Side direction, const Terrain &terrain) {
    return false;
}


