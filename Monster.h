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
    const std::string characterName;	///< The character's name
    int characterHP;	///< The character's HP
    int characterDMG;	///< The character's DMG
    const double characterACD;	///< The character's ACD

public:
	Monster(std::string, int, int, double);	///< This builds  a character object
    static Monster parse(const std::string& name);	///< This reads in the player data from file
    std::string getName() const;	///< This is a simple getter for Name
    int getHP() const;	///< This is a simple getter for HP
    int getDMG() const;	///< This is a simple getter for DMG
    double getACD() const;	///< This is a simple getter for ACD
    bool isAlive() const;	///< This shows that the player is alive or not
    void hit(Monster& target);	///< This takes one hit
    std::string makeResults(std::string Name, int HP);	///< This makes the results into one string
    std::string attack(Monster& player1, Monster& player2);	///< This commands the hole battle
    friend std::ostream& operator<<(std::ostream& os, const Monster& obj);	///< This is an operator overwrite

};

#endif
