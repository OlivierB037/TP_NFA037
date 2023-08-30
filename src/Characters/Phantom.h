//
// Created by aperi on 13/12/2022.
//

#ifndef TP_NFA037_PHANTOM_H
#define TP_NFA037_PHANTOM_H


#include "Perso.h"
#include "../Callbacks/Vulnerability_Callback.h"

class Phantom : public Perso{
public:

    //TODO ajouter méthode abstraite equals pour identifier les phantomes
    //TODO envisager de faire des Singleton a partir des sous-classes de phantom

    bool operator==(const Phantom &rhs) const;

    bool operator!=(const Phantom &rhs) const;

    virtual Side getDirection() = 0;

    virtual void setDirection(Side _direction) = 0;

    inline static const int VULNERABILITY_TIME {10000};

    void changeSprite(Side direction);

    bool isVulnerable() const;

    bool isAlive() const;

    void setAlive(bool _alive);

    void setVulnerable(bool _vulnerable);

protected:
    Phantom(int _left_1_x, int _left_1_y, int _left_2_x, int _left_2_y, int _right_1_x, int _right_1_y, int _right_2_x,
            int _right_2_y, int _up_1_x, int _up_1_y, int _up_2_x, int _up_2_y, int _down_1_x, int _down_1_y,
            int _down_2_x, int _down_2_y, Side startingSide);
    Phantom() = delete;
private:
    template<typename T> static bool instanceOf(Phantom *trgt);
    bool vulnerable;
    bool alive;
};


#endif //TP_NFA037_PHANTOM_H
