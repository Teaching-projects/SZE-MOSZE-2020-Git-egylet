#include "Player.h"
#include "Character.h"
#include <math.h>
#include <fstream>


Player::Player(const std::string characterName, int characterHP, int characterDMG) : Character(characterName, characterHP, characterDMG), maxHP(characterHP), level(1), XP(1)
{
}



void Player::levelup() {
	level++;
	maxHP = round(maxHP * 1.1);
	characterDMG = round(characterDMG * 1.1);
	characterHP = maxHP;
	
}



void Player::attack(Character* enemy) 
{
    int enemyHP = enemy->getHP();
    int XpToAdd= 0;

    if (enemyHP < characterDMG)
    {
		XpToAdd = enemyHP;
    }
    else
    {
		XpToAdd = characterDMG;
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


 