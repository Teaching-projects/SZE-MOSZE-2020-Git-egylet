#include <iostream>
#include <string>
#include <fstream>
#include "Character.h"

character::character(std::string name, int HP, int DMG) : characterName(name), characterHP(HP), characterDMG(DMG) {}

std::string character::getName() const
{
    return characterName;
}
int character::getHP() const
{
    return characterHP;
}
int character::getDMG() const
{
    return characterDMG;
}

void character::attack(character& target) const  {
    std::cout << this->characterName << " -> " << target.characterName << std::endl;

    if (target.characterHP < this->characterDMG) {
        target.characterHP = 0;
    }
    else {
        target.characterHP -= this->characterDMG;
    }
}

bool character::isAlive() const {
     return this->characterHP > 0;
}

std::ostream& operator<<(std::ostream& os, const character& obj) {
    return os << obj.getName() << ": HP: " << obj.getHP() << " DMG: " << obj.getDMG() << std::endl;
}

character  character::parseUnit(const std::string& name) {
	std::string cname;
	std::ifstream file;
	file.open(name);
	if (file.fail()) std::cout << "XD";
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
		return character(cname, stoi(chp), stoi(cdmg));
	}
}