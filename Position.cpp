//
// Created by aperi on 29/11/2022.
//

#include "Position.h"
#include <iostream>

Position::Position() : SDL_Rect() {
    x = 0;
    y = 0;
    w = 35;
    h = 35;
}
Position::Position(int x, int y) : SDL_Rect() {
    this->x = x;
    this->y = y;
    this->w = 35;
    this->h = 35;

}



int Position::getX() const noexcept {
    return x;
}

int Position::getY() const noexcept {
    return y;
}

void Position::setX(int _x) {
    this->x = _x;

}

void Position::setY(int _y) {
    this->y = _y;

}

void Position::afficher() const noexcept {
    std::cout << "(" << x << " ; " << y <<")" << std::endl;
}







