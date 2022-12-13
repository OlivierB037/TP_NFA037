//
// Created by aperi on 13/12/2022.
//

#include "Phantom.h"
typedef Perso super;
bool Phantom::isVulnerable() const {
    return vulnerable;
}

void Phantom::setVulnerable(bool vulnerable) {
    Phantom::vulnerable = vulnerable;
}

void Phantom::startVulnerability() {

}

bool Phantom::isAlive() const {
    return alive;
}

void Phantom::setAlive(bool alive) {
    Phantom::alive = alive;
}

void Phantom::endVulnerability() {

}

Phantom::Phantom() : super(),vulnerable(false), alive(true)  {

}
