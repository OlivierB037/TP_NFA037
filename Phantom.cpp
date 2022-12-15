//
// Created by aperi on 13/12/2022.
//

#include "Phantom.h"
typedef Perso super;
bool Phantom::isVulnerable() const {
    return vulnerable;
}

void Phantom::setVulnerable(bool _vulnerable) {
    Phantom::vulnerable = _vulnerable;
}

void Phantom::startVulnerability() {

}

bool Phantom::isAlive() const {
    return alive;
}

void Phantom::setAlive(bool _alive) {
    Phantom::alive = _alive;
}

void Phantom::endVulnerability() {

}

Phantom::Phantom() : super(),vulnerable(false), alive(true)  {

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
