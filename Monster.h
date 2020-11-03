/**
\mainpage Git egylet's documentation
\class character
This is the description of Character.h
\version 1.0
\author mrpig2000
\date 2020/10/11 12:39
Created on: 2020/10/11 12:39
*/

#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include <iostream>

class Monster
{
protected:
    std::string characterName;	///< The character's name
    int characterHP;	///< The character's HP
    int characterDMG;	///< The character's DMG
    double characterACD;	///< The character's ACD

public:
    Monster(std::string name /** This is a string parameter*/, int HP /** This is an int parameter*/, int DMG /** This is an int parameter*/, double ACD /** This is a double parameter*/);

    static Monster parse(const std::string& name);	///< This reads in the player data from file
    std::string getName() const;	///< This is a simple getter for Name
    int getHealthPoints() const;	///< This is a simple getter for HP
    int getDamage() const;	///< This is a simple getter for DMG
    double getAttackCoolDown() const;	///< This is a simple getter for ACD
    bool isAlive() const;	///< This shows that the player is alive or not
    void getHit(Monster* target);	///< This takes one hit
    virtual void hit(Monster* target);
    void fightTilDeath(Monster& target);	///< This commands the hole battle
    friend std::ostream& operator<<(std::ostream& os, const Monster& obj);	///< This is an operator overwrite

};

#endif
