#include <iostream>
#include <string>
#include <fstream>
#include "Character.h"

Character::Character(const std::string name, int hp, int dmg) : characterName(name), characterHP(hp), characterDMG(dmg)
{	

}

std::string Character::getName() const
{
    return characterName;
}
int Character::getHP() const
{
    return characterHP;
}
int Character::getDMG() const
{
    return characterDMG;
}

void Character::getDamage(Character* target)
{
	characterHP = (getHP() - target->getDMG());
	if (characterHP < 0)
	{
		characterHP = 0;
	}
}
void Character::attack(Character& target)  {
	target.getDamage(this);
}

bool Character::isAlive() const {
     return this->characterHP > 0;
}

std::ostream& operator<<(std::ostream& os, const Character& obj) {
    return os << obj.getName() << ": HP: " << obj.getHP() << " DMG: " << obj.getDMG() << std::endl;
}

Character  Character::parseUnit(const std::string& name) {
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
		return  Character(cname, stoi(chp), stoi(cdmg));
	}
}

