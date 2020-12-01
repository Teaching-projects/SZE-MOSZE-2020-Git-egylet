/**
\mainpage Git egylet's documentation
\class Monstter
This is the description of Monster.h
\version 1.1
\author mrpig2000
\date 2020/12/01 10:56
Created on: 2020/10/11 12:39
*/

#ifndef MONSTER_H
#define MONSTER_H

#include "Damage.h"

#include <string>
#include <iostream>

class Monster
{
    protected:
        std::string characterName;	///< The monster's name
        int characterHP;	///< The monster's health points
        Damage damage;  ///< The monster's damage
        double characterACD;	///< The monster's attack cooldown
        double characterDEF;    ///< The monster's defense
        
    public:
        Monster
        (
            std::string name,
            int HP,
            Damage DMGS,
            double ACD,
            double DEF       
        );  ///< This is a Monster constructor

        static Monster parse(const std::string& name);	///< This reads in the monster data from file
        std::string getName() const;	///< This is a simple getter for Name
        int getHealthPoints() const;	///< This is a simple getter for HP
        Damage getDamage() const;	///< This is a simple getter for DMG
        double getAttackCoolDown() const;	///< This is a simple getter for ACD
        double getDefense() const;	///< This is a simple getter for DEF
        bool isAlive() const;	///< This shows if the player is alive or not
        void getHit(Monster* target);	///< This takes one hit
        virtual void hit(Monster* target);
        void fightTilDeath(Monster& target);	///< This is controlling the whole battle
        //friend std::ostream& operator<<(std::ostream& os, const Monster& obj);	///< This is an operator overwrite
};

#endif