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
        Damage (int p, int m);  ///< Damage constructor

        void setPhysical(int p);    ///< This is a simple setter for physical damage
        void setMagical(int m);     ///< This is a simple getter for macial damage

        int getPhysical() const;	///< This is a simple getter for physical damage
        int getMagical() const;	///< This is a simple getter for magical damage
        
        friend Damage operator + (const Damage& dmg, const Damage& other);  ///< Operator overwrite
        friend Damage& operator += (Damage& dmg, const Damage& other);  ///< Operator overwrite
        friend Damage& operator *= (Damage& dmg, const Damage& other);  ///< Operator overwrite
        friend std::ostream& operator << (std::ostream& s, const Damage& dmg);  ///< Operator overwrite
};

#endif //DAMAGE_H