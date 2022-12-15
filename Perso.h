//
// Created by aperi on 30/11/2022.
//

#ifndef TP_01_PERSO_H
#define TP_01_PERSO_H


#include "Image.h"
#include "Position.h"

#include <string>
#define CHARACTER_SIZE 36
class Perso
{
protected:

    Perso();
public:
    bool operator==(const Perso &rhs) const;

    bool operator!=(const Perso &rhs) const;

    void setPosition(int _x, int _y);

    virtual void changeSprite(Side direction) = 0;

    const Position &getPosition() const;

    virtual const  Image &getImage() const = 0;

    void incrementX(int value);
    void incrementY(int value);

    int getStepCount() const;

    void incrementStepCount();

    void setStepCount(int _stepCount);

    virtual const SDL_Rect *getCurrentSprite() const = 0;

    virtual void setCurrentSprite(const SDL_Rect *currentSprite) = 0;

    virtual const Position& getStartingPosition() const = 0;

    inline static const char* sprite_fileName{ "persos24.bmp" };
    inline static const int MAXIMUM_MOTION_SCALE{6};

private:
    Position position;

    int stepCount;

};


#endif //TP_01_PERSO_H
