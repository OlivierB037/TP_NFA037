//
// Created by aperi on 29/11/2022.
//

#ifndef TP_01_POSITION_H
#define TP_01_POSITION_H
#include <SDL.h>
class Position : public SDL_Rect {
public:
    Position(int x, int y);
    Position();

    int getX() const noexcept;
    int getY() const noexcept;
    void setX(int _x);
    void setY(int _y);

    void afficher() const noexcept;



private:


};



#endif //TP_01_POSITION_H
