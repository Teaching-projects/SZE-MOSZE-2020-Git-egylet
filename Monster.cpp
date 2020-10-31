#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Monster.h"
#include "JSON.h"

Monster::Monster(const std::string name, int HP, int DMG, double ACD)
	: characterName(name),
	characterHP(HP),
	characterDMG(DMG),
	characterACD(ACD)
	{}

std::string Monster::getName(/** Here is no parameter*/) const {
    return characterName;
}

int Monster::getHealthPoints(/** Here is no parameter*/) const {
    return characterHP;
}

int Monster::getDamage(/** Here is no parameter*/) const {
    return characterDMG;
}

double Monster::getAttackCoolDown(/** Here is no parameter*/) const {
    return characterACD;
}

bool Monster::isAlive(/** Here is no parameter*/) const {
     return this->characterHP > 0;
}

void Monster::hit(Monster& target /** This is a player parameter*/) {
	target.characterHP -= this->characterDMG; ///< Takes one hit
	if (target.characterHP < 0) target.characterHP = 0; ///< Restores HP to 0 if HP decreases below 0
}

std::string Monster::makeResults(std::string Name /** This is a string parameter*/, int HP /** This is an int parameter*/) {
	std::string results = "";	///< This makes a new empty string: results
	results += Name; 	///< This add the Name to results string
	results += " wins. Remaining HP: ";	///< This add filling text to results string
	results += std::to_string(HP); 	///< This add the HP to results string
	results += ".";	///< This add filling text to results string
	return results;	///< \return This is the completed string
}

std::string Monster::attack(Monster& player1 /** This is a player parameter*/, Monster& player2 /** This is a player parameter*/) {
	double time1 = 0;	///< First player's time counter
	double time2 = 0;	///< Second player's time counter
	while (player1.isAlive() && player2.isAlive()) {

		///Player1 is the next
		if (time1 /**First player's time counter*/ < time2 /**Second player's time counter*/) {
			player1.hit(player2 /**This is a player parameter*/);
			if (!player2.isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(player1.getName(/** Here is no parameter*/), player1.getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time1 += player1.characterACD;	///< Increases first player's time counter with first player's ACD
		}

		///Player2 is the next
		else if (time1 /**First player's time counter*/ > time2 /**Second player's time counter*/) {
			player2.hit(player1 /**This is a player parameter*/);
			if (!player1.isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(player2.getName(/** Here is no parameter*/), player2.getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time2 += player2.characterACD;	///< Increases second player's time counter with first player's ACD
		}

		///Both players hits at the same time, the first is who started the attack
		else {
			player1.hit(player2 /**This is a player parameter*/);
			if (!player2.isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(player1.getName(/** Here is no parameter*/), player1.getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time1 += player1.characterACD;	///< Increases first player's time counter with first player's ACD
			player2.hit(player1 /**This is a player parameter*/);
			if (!player1.isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(player2.getName(/** Here is no parameter*/), player2.getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time2 += player2.characterACD;	///< Increases second player's time counter with first player's ACD
		}
	}
	return 0;
}

std::ostream& operator<<(std::ostream& os, const Monster& obj) {
    return os << obj.getName(/** Here is no parameter*/) << ": HP: " << obj.getHealthPoints(/** Here is no parameter*/) << " DMG: " << obj.getDamage(/** Here is no parameter*/) << " ACD: " << obj.getAttackCoolDown(/** Here is no parameter*/) << std::endl;
}

Monster Monster::parse(const std::string& name) {
	JSON values = JSON::jsonParser(name);
	
	const std::vector<std::string> find{"name", "hp", "dmg", "acd"};
    for (int i = 0; i < find.size(); i++)
    {
        if (!values.count(find[i]))
        {
            throw std::invalid_argument("JSON error: " + name + "-> " + find[i]);
        }
    }

    return Monster
		(
        values.get<std::string>("name"),
        values.get<int>("hp"),
        values.get<int>("dmg"),
        values.get<float>("acd")
        );
}
