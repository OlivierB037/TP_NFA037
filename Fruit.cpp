//
// Created by aperi on 13/12/2022.
//

#include "Fruit.h"
typedef Bloc super;
Fruit::Fruit() : super(true), eaten(false) {

}
bool Fruit::isCrossable() const {
    return true;
}

bool Fruit::isEaten() const {
    return eaten;
}

void Fruit::setEaten(bool _eaten) {
    eaten = _eaten;
}


