#include <iostream>
#include <string>
#include <fstream>
#include "Character.h"

character::character(std::string name /** This is a string parameter*/, int HP /** This is an int parameter*/, int DMG /** This is an int parameter*/, double ACD /** This is a double parameter*/) : characterName(name), characterHP(HP), characterDMG(DMG), characterACD(ACD) {}

std::string character::getName(/** Here is no parameter*/) const {
    return characterName;
}

int character::getHP(/** Here is no parameter*/) const {
    return characterHP;
}

int character::getDMG(/** Here is no parameter*/) const {
    return characterDMG;
}

double character::getACD(/** Here is no parameter*/) const {
    return characterACD;
}

bool character::isAlive(/** Here is no parameter*/) const {
     return this->characterHP > 0;
}

void character::hit(character& target /** This is a player parameter*/) {
	target.characterHP -= this->characterDMG; ///< Takes one hit
	if (target.characterHP < 0) target.characterHP = 0; ///< Restores HP to 0 if HP decreases below 0
}

std::string makeResults(std::string Name /** This is a string parameter*/, int HP /** This is an int parameter*/) {
	std::string results = "";	///< This makes a new empty string: results
	results += Name; 	///< This add the Name to results string
	results += " wins. Remaining HP: ";	///< This add filling text to results string
	results += std::to_string(HP); 	///< This add the HP to results string
	results += ".";	///< This add filling text to results string
	return results;	///< \return This is the completed string
}

std::string character::attack(character& player1 /** This is a player parameter*/, character& player2 /** This is a player parameter*/){
	double time1 = 0;	///< First player's time counter
	double time2 = 0;	///< Second player's time counter
	while (player1.isAlive() && player2.isAlive()) {
		
		///Player1 is the next
		if (time1 /**First player's time counter*/ < time2 /**Second player's time counter*/) {
			player1.hit(player2 /**This is a player parameter*/);
			if (!player2.isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(player1.getName(/** Here is no parameter*/), player1.getHP(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time1 += player1.characterACD;	///< Increases first player's time counter with first player's ACD
		}
		
		///Player2 is the next
		else if (time1 /**First player's time counter*/ > time2 /**Second player's time counter*/) {
			player2.hit(player1 /**This is a player parameter*/);
			if (!player1.isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(player2.getName(/** Here is no parameter*/), player2.getHP(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time2 += player2.characterACD;	///< Increases second player's time counter with first player's ACD
		}
		
		///Both players hits at the same time, the first is who started the attack
		else {
			player1.hit(player2 /**This is a player parameter*/);
			if (!player2.isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(player1.getName(/** Here is no parameter*/), player1.getHP(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time1 += player1.characterACD;	///< Increases first player's time counter with first player's ACD
			player2.hit(player1 /**This is a player parameter*/);
			if (!player1.isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(player2.getName(/** Here is no parameter*/), player2.getHP(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time2 += player2.characterACD;	///< Increases second player's time counter with first player's ACD
		}
	}
	return 0;
}

std::ostream& operator<<(std::ostream& os, const character& obj) {
    return os << obj.getName(/** Here is no parameter*/) << ": HP: " << obj.getHP(/** Here is no parameter*/) << " DMG: " << obj.getDMG(/** Here is no parameter*/) << " ACD: " << obj.getACD(/** Here is no parameter*/) << std::endl;
}

character  character::parseUnit(const std::string& name) {
	std::string cname;
	std::ifstream file;
	file.open(name);
	if (file.fail(/** Here is no parameter*/)) throw "it does not exist";	///< Error sign
	else
	{
		std::string separator = " : ";
		std::string chp, cdmg, cacd, row, part;
		while (std::getline(file, row)) {
			///Finding and reading in name
			if (row.find("name") != std::string::npos) {
				cname = row.substr(row.find(separator) + 1);
				cname = cname.substr(cname.find('"') + 1, cname.find_last_of('"') - 3);
			}
			
			///Finding and reading in hp
			else if (row.find("hp") != std::string::npos) {
				part = row.substr(row.find(separator) + 3);
				chp = part.substr(0, part.find(","));
			}
			
			///Finding and reading in dmg
			else if (row.find("dmg") != std::string::npos) {
				cdmg = row.substr(row.find(separator) + 3);
			}
			
			///Finding and reading in acd
			else if (row.find("acd") != std::string::npos) {
				cacd = row.substr(row.find(separator) + 3);
			}			
		}
		file.close(/** Here is no parameter*/);
		return  character(cname, stoi(chp), stoi(cdmg), stoi(cacd));
	}
}