//
// Created by aperi on 08/12/2022.
//

#ifndef TP_NFA037_DOOR_H
#define TP_NFA037_DOOR_H
#include "Bloc.h"

class Door : public Bloc {
public :

    Door(bool open);

    bool isCrossable() const;
    void setCrossable(bool crossable);
private:

};

#endif //TP_NFA037_DOOR_H
