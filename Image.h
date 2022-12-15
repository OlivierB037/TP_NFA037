#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-nodiscard"
//
// Created by aperi on 30/11/2022.
//

#ifndef TP_01_IMAGE_H
#define TP_01_IMAGE_H

#ifdef USING_CLION //permet de vérifier l'IDE utilisé (define USING_CLION ajouté via CMake sous CLION)
#include "Include/SDL.h"
#else
#include <SDL.h>
#endif

#include <memory>
#include <vector>
enum Side
{
    LEFT, RIGHT, UP, DOWN, NONE
};
class Image
{
public:
    Image(int _left_1_x, int _left_1_y,
          int _left_2_x, int _left_2_y,
          int _right_1_x, int _right_1_y,
          int _right_2_x, int _right_2_y,
          int _up_1_x, int _up_1_y,
          int _up_2_x, int _up_2_y,
          int _down_1_x, int _down_1_y,
          int _down_2_x, int _down_2_y);

    bool operator==(const Image &rhs) const;

    bool operator!=(const Image &rhs) const;


    const SDL_Rect &getLeft1() const;

    const SDL_Rect &getLeft2() const;

    const SDL_Rect &getRight1() const;

    const SDL_Rect &getRight2() const;

    const SDL_Rect &getUp1() const;

    const SDL_Rect &getUp2() const;

    const SDL_Rect &getDown1() const;

    const SDL_Rect &getDown2() const;



    const SDL_Rect *getBaseRect(Side side) const;



private:
    const SDL_Rect left_1;
    const SDL_Rect left_2;
    const SDL_Rect right_1;
    const SDL_Rect right_2;
    const SDL_Rect up_1;
    const SDL_Rect up_2;
    const SDL_Rect down_1;
    const SDL_Rect down_2;


};


#endif //TP_01_IMAGE_H

#pragma clang diagnostic pop