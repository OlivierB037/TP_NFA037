//
// Created by aperi on 14/12/2022.
//

#include <map>
#include "Window.h"
#include "../Characters/Perso.h"
#include "../Characters/Hero.h"
#include "../Characters/Phantom.h"

Window::Window() {

}

void Window::init() {
    SDL_Init(SDL_INIT_VIDEO);


    //TODO créer fenêtre après labyrinthe pour avoir la taille
    SDL_CreateWindowAndRenderer(504, 558, SDL_WINDOW_ALWAYS_ON_TOP, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);


    SDL_Surface* imagePerso = SDL_LoadBMP(Perso::sprite_fileName);
    //SDL_Surface* imagePerso = IMG_Load(Perso::sprite_fileName);
    persosTexture = SDL_CreateTextureFromSurface(renderer, imagePerso);
    SDL_Surface *backgroundSurface = SDL_LoadBMP("resources/field_full24.bmp");
    backgroundFull = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);
    SDL_Surface *emptyBackGroundSurface = SDL_LoadBMP("resources/field_empty.bmp");
    backgroundEmpty = SDL_CreateTextureFromSurface(renderer, emptyBackGroundSurface);
    SDL_FreeSurface(emptyBackGroundSurface);
    SDL_FreeSurface(imagePerso);

}

void Window::addTexture(SDL_Texture *_texture,const SDL_Rect *src,const SDL_Rect *dest) {
    SDL_RenderCopy(renderer, _texture, src, dest);


}

void Window::render(){
    SDL_RenderPresent(renderer);
}

SDL_Window *Window::getWindow() const {
    return window;
}

SDL_Renderer *Window::getRenderer() const {
    return renderer;
}

void Window::clearRendering() {
    SDL_RenderClear(renderer);
}

SDL_Texture *Window::getBackgroundFull() const {
    return backgroundFull;
}

SDL_Texture *Window::getBackgroundEmpty() const {
    return backgroundEmpty;
}

SDL_Texture *Window::getPersosTexture() const {
    return persosTexture;
}

void Window::updateTextures(const Hero &hero, const std::map<int, Phantom*> &phantoms,std::vector<SDL_Rect *> &emptyRects) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundFull, NULL, NULL);
    for (SDL_Rect *r : emptyRects ) {

        SDL_RenderCopy(renderer,backgroundEmpty, r, r);
    }
    SDL_RenderCopy(renderer,persosTexture,hero.getCurrentSprite(),&(hero.getPosition()));
    SDL_RenderPresent(renderer);

}

void Window::updateTextures(const Hero &hero, const std::map<int, Phantom*> &phantoms) {
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, backgroundFull, NULL, NULL);
    SDL_RenderCopy(renderer,persosTexture,hero.getCurrentSprite(),&(hero.getPosition()));
    for (auto phantom : phantoms) {
        if (phantom.second->isAlive()){
            SDL_RenderCopy(renderer,persosTexture,phantom.second->getCurrentSprite(),&(phantom.second->getPosition()));
        }
    }
    SDL_RenderPresent(renderer);
}


