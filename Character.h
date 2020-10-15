/**
\mainpage Git egylet's documentation

\class character

This is the description of Character.h

\version 1.0

\author mrpig2000

\date 2020/10/11 12:39

Created on: 2020/10/11 12:39
*/

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <iostream>
class character
{
    
public:
    
	character(const std::string, const int, const int, const double);	///< This builds  a character object
    static character parseUnit(const std::string& name);	///< This reads in the player data from file
    std::string getName() const;	///< This is a simple getter for Name
    int getHP() const;	///< This is a simple getter for HP
    int getDMG() const;	///< This is a simple getter for DMG
	double getACD() const;	///< This is a simple getter for ACD
    bool isAlive() const ;	///< This shows that the player is alive or not
	std::string makeResults(std::string Name, int HP);	///< This makes the results into one string
	std::string attack(character& player1, character& player2);	///< This commands the hole battle
    friend std::ostream& operator<<(std::ostream& os, const character& obj);	///< This is an operator overwrite
   

private:
     
	const std::string characterName;	///< The character's name
	int characterHP;	///< The character's HP
	const int characterDMG;	///< The character's DMG
	const double characterACD;	///< The character's ACD

	void hit(character& target);	///< This takes one hit
     
};


#endif
