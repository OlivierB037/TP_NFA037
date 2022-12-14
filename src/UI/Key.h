//
// Created by aperi on 07/12/2022.
//

#ifndef TP_NFA037_KEY_H
#define TP_NFA037_KEY_H


#include "Sprites.h"

class Key {
public:
    Key(int _scanCode, Side _direction);

    int getScanCode() const;

    bool isPressed() const;

    void setPressed(bool pressed);

    const Side getDirection() const;

private:
    const int scanCode;
    bool pressed;
    const Side direction;
};


#endif //TP_NFA037_KEY_H
