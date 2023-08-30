//
// Created by aperi on 30/11/2022.
//

#ifndef TP_01_PERSO_H
#define TP_01_PERSO_H


#include "../UI/Sprites.h"
#include "Position.h"

#include <string>
#define CHARACTER_SIZE 36
class Perso
{
protected:

    Perso(int _left_1_x, int _left_1_y,
          int _left_2_x, int _left_2_y,
          int _right_1_x, int _right_1_y,
          int _right_2_x, int _right_2_y,
          int _up_1_x, int _up_1_y,
          int _up_2_x, int _up_2_y,
          int _down_1_x, int _down_1_y,
          int _down_2_x, int _down_2_y, Side startingSide);
    Perso() = delete;

    SDL_Rect const *currentSprite;
    Sprites image;
public:

    bool operator==(const Perso &rhs) const;

    bool operator!=(const Perso &rhs) const;

    void setPosition(int _x, int _y);

    virtual void changeSprite(Side direction) = 0;

    const Position &getPosition() const;

    const  Sprites &getImage() const;

    void incrementX(int value);
    void incrementY(int value);

    int getStepCount() const;

    void incrementStepCount();

    void setStepCount(int _stepCount);

    const SDL_Rect *getCurrentSprite() const;

    virtual void setCurrentSprite(const SDL_Rect *_currentSprite);

    virtual const Position& getStartingPosition() const = 0;

    constexpr static char* const sprite_fileName{ "resources/persos24.bmp" };
    inline static const int MAXIMUM_MOTION_SCALE{6};

private:
    Position position;
    int stepCount;

};


#endif //TP_01_PERSO_H
