//
// Created by aperi on 08/12/2022.
//

#ifndef TP_NFA037_WALL_H
#define TP_NFA037_WALL_H


#include "Bloc.h"

class Wall : public Bloc {
public :

    Wall();

    bool isCrossable() const;
};


#endif //TP_NFA037_WALL_H
