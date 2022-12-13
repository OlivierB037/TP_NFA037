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
    Perso(int _left_1_x, int _left_1_y,
          int _left_2_x, int _left_2_y,
          int _right_1_x, int _right_1_y,
          int _right_2_x, int _right_2_y,
          int _up_1_x, int _up_1_y,
          int _up_2_x, int _up_2_y,
          int _down_1_x, int _down_1_y,
          int _down_2_x, int _down_2_y);
    Perso() = delete;
public:


    void setPosition(int _x, int _y);

    void changeSprite(Side direction);

    const Position &getPosition() const;

    const Image &getImage() const;

    void incrementX(int value);
    void incrementY(int value);

    int getStepCount() const;

    void incrementStepCount();

    void setStepCount(int stepCount);

    const SDL_Rect *getCurrentSprite() const;

    void setCurrentSprite(const SDL_Rect *currentSprite);

    inline static const char* sprite_fileName{ "persos.bmp" };
    inline static const int MAXIMUM_MOTION_SCALE{6};

private:
    Position position;
    Image image;
    SDL_Rect const *currentSprite;
    int stepCount;

};


#endif //TP_01_PERSO_H
