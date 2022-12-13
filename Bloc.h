//
// Created by aperi on 01/12/2022.
//

#ifndef TP_01_BLOC_H
#define TP_01_BLOC_H
#include <SDL_rect.h>
#include <iostream>

class Bloc {

public:

    Bloc();
    explicit Bloc(bool _crossable);
//    virtual bool isInside();



    virtual bool isCrossable() const;



    virtual void setCrossable(bool _wall);
    // si difference entre position et bloc < deplacement_scale
protected:

private:
    bool crossable;



};


#endif //TP_01_BLOC_H
