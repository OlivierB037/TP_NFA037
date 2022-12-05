//
// Created by aperi on 01/12/2022.
//

#ifndef TP_01_BLOC_H
#define TP_01_BLOC_H
#include <SDL_rect.h>
#include "iostream"

class Bloc {

public:
    Bloc();
    explicit Bloc(bool _wall);
//    virtual bool isInside();

    void setWall(bool _wall);

    bool isWall() const;
    // si difference entre position et bloc < deplacement_scale


private:
    bool wall;


};


#endif //TP_01_BLOC_H
