//
// Created by aperi on 08/12/2022.
//

#include "Food.h"
typedef Bloc super;
Food::Food() : super(true), eaten(false) {

}

bool Food::isCrossable() const {
    return true;
}

bool Food::isEaten() const {
    return eaten;
}

void Food::setEaten(bool _eaten) {
    this->eaten = _eaten;
}
