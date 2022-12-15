//
// Created by aperi on 13/12/2022.
//

#ifndef TP_NFA037_PHANTOM_H
#define TP_NFA037_PHANTOM_H
#define VULNERABILITY_TIME 10000

#include "Perso.h"
#include "Vulnerability_Callback.h"

class Phantom : public Perso, Vulnerability_Callback {
public:
    bool operator==(const Phantom &rhs) const;

    bool operator!=(const Phantom &rhs) const;

    bool isVulnerable() const;

    void startVulnerability();

    bool isAlive() const;

    void setAlive(bool _alive);

    void endVulnerability();

    void setVulnerable(bool _vulnerable);

protected:
    Phantom();
private:
    bool vulnerable;
    bool alive;
};


#endif //TP_NFA037_PHANTOM_H
