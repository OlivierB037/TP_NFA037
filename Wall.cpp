//
// Created by aperi on 08/12/2022.
//

#include "Wall.h"
typedef Bloc super;
Wall::Wall() : Bloc(false) {

}

bool Wall::isCrossable() const {
    return false;
}
