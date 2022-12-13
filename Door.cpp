//
// Created by aperi on 08/12/2022.
//

#include "Door.h"

Door::Door(bool open) : Bloc(open) {

}
bool Door::isCrossable() const {
    return Bloc::isCrossable();
}

void Door::setCrossable(bool crossable) {
    Bloc::setCrossable(crossable);
}



