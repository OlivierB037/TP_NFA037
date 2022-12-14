//
// Created by aperi on 14/12/2022.
//

#ifndef TP_NFA037_WINDOW_H
#define TP_NFA037_WINDOW_H
#include <SDL.h>
#include <vector>
#include "../Characters/Perso.h"
#include "../Characters/Hero.h"
#include "../Characters/Phantom.h"

class Window {
public:
    Window();
    void init();
    void addTexture(SDL_Texture *_texture, const SDL_Rect *src,const SDL_Rect *dest);

    SDL_Window *getWindow() const;

    SDL_Renderer *getRenderer() const;

    void render();

    void clearRendering();

    void updateTextures(const Hero &hero, const std::map<int, Phantom*> &phantoms);

    void updateTextures(const Hero &hero, const std::map<int, Phantom*> &phantoms,std::vector<SDL_Rect*> &emptyRects);

    SDL_Texture *getBackgroundFull() const;

    SDL_Texture *getBackgroundEmpty() const;

    SDL_Texture *getPersosTexture() const;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *backgroundFull, *backgroundEmpty, *persosTexture;


};


#endif //TP_NFA037_WINDOW_H
