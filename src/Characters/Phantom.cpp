//
// Created by aperi on 13/12/2022.
//

#include "Phantom.h"
typedef Perso super;

Phantom::Phantom(int _left_1_x, int _left_1_y, int _left_2_x, int _left_2_y,
                 int _right_1_x, int _right_1_y, int _right_2_x, int _right_2_y,
                 int _up_1_x, int _up_1_y, int _up_2_x, int _up_2_y,
                 int _down_1_x, int _down_1_y, int _down_2_x, int _down_2_y, Side startingSide)

        : super( _left_1_x,  _left_1_y,  _left_2_x,  _left_2_y,
                 _right_1_x,  _right_1_y,  _right_2_x,  _right_2_y,
                 _up_1_x,  _up_1_y,  _up_2_x,  _up_2_y,
                 _down_1_x,  _down_1_y,  _down_2_x, _down_2_y, startingSide),vulnerable(false), alive(true)  {

}

bool Phantom::isVulnerable() const {
    return vulnerable;
}

void Phantom::setVulnerable(bool _vulnerable) {
    Phantom::vulnerable = _vulnerable;
}



bool Phantom::isAlive() const {
    return alive;
}

void Phantom::setAlive(bool _alive) {
    Phantom::alive = _alive;
}

bool Phantom::operator==(const Phantom &rhs) const {
    return static_cast<const Perso &>(*this) == static_cast<const Perso &>(rhs) &&
           vulnerable == rhs.vulnerable &&
           alive == rhs.alive;
}

bool Phantom::operator!=(const Phantom &rhs) const {
    return static_cast<const Perso &>(*this) != static_cast<const Perso &>(rhs) ||
           vulnerable != rhs.vulnerable ||
           alive != rhs.alive;
}

template<typename T>
bool Phantom::instanceOf(Phantom *trgt) {
    return dynamic_cast<T*>(trgt);
}

void Phantom::changeSprite(Side direction) {
    //TODO ajouter if pour sprite vulnerable
    switch (direction) {
        case LEFT:
            if (currentSprite == &(image.getLeft1())){
                currentSprite = &(image.getLeft2());
            }
            else{
                currentSprite = &(image.getLeft1());
            }
            break;
        case RIGHT:
            if (currentSprite == &(image.getRight1())){
                currentSprite = &(image.getRight2());
            }
            else{
                currentSprite = &(image.getRight1());
            }
            break;
        case UP:
            if (currentSprite == &(image.getUp1())){
                currentSprite = &(image.getUp2());
            }
            else{
                currentSprite = &(image.getUp1());
            }
            break;
        case DOWN:
            if (currentSprite == &(image.getDown1())){
                currentSprite = &(image.getDown2());
            }
            else{
                currentSprite = &(image.getDown1());
            }
            break;
        case NONE:
            break;
    }
}









