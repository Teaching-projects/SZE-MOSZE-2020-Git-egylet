#include "Player.h"
#include "Character.h"
#include <cmath>
#include <fstream>






void Player::levelup() {
	level++;
	maxHP *= 1.1;
	maxHP = round(maxHP);
	characterDMG *= 1.1;
	characterHP = maxHP;
	

	
}

std::string Player::attack(Character& player1 /** This is a player parameter*/, Character& player2 /** This is a player parameter*/) {
	double time1 = 0;	///< First player's time counter
	double time2 = 0;	///< Second player's time counter
	int XpToAdd = 0;
	while (player1.isAlive() && player2.isAlive()) {
		

		if (player2.getHP() < player1.getDMG())
		{

			XpToAdd = player2.getHP();

		}
		else
		{

			XpToAdd = player1.getDMG();
		}

		XP += XpToAdd;

		if (XP >= 100)
		{
			int LvlToAdd = XP / 100;
			for (int i = 0; i < LvlToAdd; i++)
			{
				levelup();

			}
			XP -= LvlToAdd * 100;
		}

		///Player1 is the next
		if (time1 /**First player's time counter*/ < time2 /**Second player's time counter*/) {
			player1.hit(player2 /**This is a player parameter*/);
			if (!player2.isAlive(/** Here is no parameter*/)) {
				std::string result = player1.makeResults(player1); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time1 += player1.getACD();	///< Increases first player's time counter with first player's ACD
		}

		///Player2 is the next
		else if (time1 /**First player's time counter*/ > time2 /**Second player's time counter*/) {
			player2.hit(player1 /**This is a player parameter*/);
			if (!player1.isAlive(/** Here is no parameter*/)) {
				std::string result = player2.makeResults(player2); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time2 += player2.getACD();	///< Increases second player's time counter with first player's ACD
		}

		///Both players hits at the same time, the first is who started the attack
		else {
			player1.hit(player2 /**This is a player parameter*/);
			if (!player2.isAlive(/** Here is no parameter*/)) {
				std::string result = player1.makeResults(player1); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time1 += player1.getACD();	///< Increases first player's time counter with first player's ACD
			player2.hit(player1 /**This is a player parameter*/);
			if (!player1.isAlive(/** Here is no parameter*/)) {
				std::string result = player2.makeResults(player2); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time2 += player2.getACD();	///< Increases second player's time counter with first player's ACD
		}
	}
	return 0;
}



Player  Player::parseUnit(const std::string& name) {
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
		return  Player(cname, stoi(chp), stoi(cdmg), stoi(cacd));
	}
}
