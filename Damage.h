/**
\struct Damage
This is the description of Damage.h
\version 1.0
\author mrpig2000
\date 2020/11/23 21:20
Created on: 2020/11/23 21:20
*/


#ifndef DAMAGE_H
#define DAMAGE_H

#include <iostream>

struct Damage {
    protected:
        int physical;   ///< The physical damage
        int magical;    ///< The magical damage

    public:
        friend Damage operator + (const Damage& dmg, const Damage& other);
        friend Damage& operator += (Damage& dmg, const Damage& other);
        friend Damage& operator *= (Damage& dmg, const Damage& other);
        friend std::ostream& operator << (std::ostream& s, const Damage& dmg);
};

#endif //DAMAGE_H