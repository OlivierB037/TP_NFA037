//
// Created by aperi on 30/11/2022.
//

#include "Sprites.h"

const SDL_Rect &Sprites::getLeft1() const {
    return left_1;
}

const SDL_Rect &Sprites::getLeft2() const {
    return left_2;
}

const SDL_Rect &Sprites::getRight1() const {
    return right_1;
}

const SDL_Rect &Sprites::getRight2() const {
    return right_2;
}

const SDL_Rect &Sprites::getUp1() const {
    return up_1;
}

const SDL_Rect &Sprites::getUp2() const {
    return up_2;
}

const SDL_Rect &Sprites::getDown1() const {
    return down_1;
}

const SDL_Rect &Sprites::getDown2() const {
    return down_2;
}



Sprites::Sprites(int _left_1_x, int _left_1_y, int _left_2_x, int _left_2_y,
                 int _right_1_x, int _right_1_y, int _right_2_x, int _right_2_y,
                 int _up_1_x, int _up_1_y, int _up_2_x, int _up_2_y,
                 int _down_1_x, int _down_1_y, int _down_2_x, int _down_2_y)
             : left_1({_left_1_x,_left_1_y,35,35}),
                left_2({_left_2_x,_left_2_y,35,35}),
                right_1({_right_1_x,_right_1_y,35,35}),
                right_2({_right_2_x,_right_2_y,35,35}),
                up_1({_up_1_x, _up_1_y,35,35}),
                up_2({_up_2_x,_up_2_y,35,35}),
                down_1({_down_1_x, _down_1_y,35, 35}),
                down_2({_down_2_x, _down_2_y, 35, 35})

{
}

const SDL_Rect *Sprites::getBaseRect(Side side) const {
    switch (side) {
        case LEFT:
            return &left_1;
            break;
        case RIGHT:
            return &right_1;
            break;
        case UP:
            return &up_1;
            break;
        case DOWN:
            return &down_1;
            break;
        default:
            return nullptr;
            break;
    }
}


