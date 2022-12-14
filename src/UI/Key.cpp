//
// Created by aperi on 07/12/2022.
//

#include "Key.h"

Key::Key(int _scanCode, Side _direction) : scanCode(_scanCode), pressed(false),direction(_direction) {

}

int Key::getScanCode() const {
    return scanCode;
}

bool Key::isPressed() const {
    return pressed;
}

void Key::setPressed(bool _pressed) {
    this->pressed = _pressed;
}

const Side Key::getDirection() const {
    return direction;
}
