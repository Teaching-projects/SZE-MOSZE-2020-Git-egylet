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
	std::cout << "level:" << level << std::endl;

	
}



void Player::attack(Character& enemy) 
{
    int XpToAdd= 0;
	
    if (enemy.getHP() < characterDMG)
    {
		
		XpToAdd = enemy.getHP();
		
    }
    else
    {
		
		XpToAdd = characterDMG;
    }

	enemy.getDamage(this);
	XP += XpToAdd;

    if (XP >= 100)
    {
        int LvlToAdd = XP / 100;
        for (int i = 0; i < LvlToAdd; i++)
        {
            levelup();
			std::cout << "Level Up!" << std::endl;
        }
        XP -= LvlToAdd * 100;
    }
}


Player Player::parseUnit(const std::string& name) {
	std::string cname;
	std::ifstream file;
	file.open(name);
	if (file.fail()) throw "it does not exist";
	else
	{
		std::string separator = " : ";
		std::string chp, cdmg, row, part;
		while (std::getline(file, row)) {
			if (row.find("name") != std::string::npos) {
				cname = row.substr(row.find(separator) + 1);
				cname = cname.substr(cname.find('"') + 1, cname.find_last_of('"') - 3);
			}
			else if (row.find("hp") != std::string::npos) {
				part = row.substr(row.find(separator) + 3);
				chp = part.substr(0, part.find(","));
			}
			else if (row.find("dmg") != std::string::npos) {
				cdmg = row.substr(row.find(separator) + 3);
			}

		}
		file.close();
		return  Player(cname, stoi(chp), stoi(cdmg));
	}
}


 