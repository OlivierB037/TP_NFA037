//
// Created by aperi on 01/12/2022.
//

#include "Bloc.h"


Bloc::Bloc(bool _wall) {
    this->wall = _wall;
}

void Bloc::setWall(bool _wall) {
    this->wall = _wall;
}

bool Bloc::isWall() const {
    return wall;
}

Bloc::Bloc() {
    this->wall = false;

}
