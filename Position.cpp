//
// Created by aperi on 29/11/2022.
//

#include "Position.h"
#include "Logger.h"
#include <iostream>
#include <sstream>

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
    std::ostringstream outStream;
    outStream << "Position : (" << this->x << ";" << this->y << ")";
    Logger::getInstance()->addInfoLog(outStream.str());
}

void Position::incrementX(int value) {
    this->x+=value;
}

void Position::incrementY(int value) {
    this->y+=value;
}

bool Position::operator==(const SDL_Rect &rhs) {
    return x == rhs.x && y == rhs.y &&
           w == rhs.w && h == rhs.h;
}

bool Position::operator==(const Position& rhs) {

    return x == rhs.x &&
            y == rhs.y &&
            w == rhs.w &&
            h == rhs.h;
}

bool Position::operator!=(const SDL_Rect &rhs) {

    return x != rhs.x || y != rhs.y ||
           w != rhs.w || h != rhs.h;
}

bool Position::operator!=(const Position &rhs) {
    return x != rhs.x ||
           y != rhs.y ||
           w != rhs.w ||
           h != rhs.h;
}







