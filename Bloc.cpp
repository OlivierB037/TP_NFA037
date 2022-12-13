//
// Created by aperi on 01/12/2022.
//

#include "Bloc.h"


Bloc::Bloc(bool _crossable) {
    this->crossable = _crossable;
}



void Bloc::setCrossable(bool _wall) {
    Bloc::crossable = _wall;
}

bool Bloc::isCrossable() const {
    return crossable;
}

Bloc::Bloc() {
    this->crossable = false;

}
