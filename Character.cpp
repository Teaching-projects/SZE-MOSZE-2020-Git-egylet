#include <iostream>
#include <string>
#include <fstream>
#include "Character.h"
#include "JsonParser.h"

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

character character::parseUnit(const std::string& name) {
	std::ifstream file;
	file.open(name);

	if (file.fail()) throw "it does not exist";
	else
	{
		parser parser;
		std::map<std::string, std::string> values = parser.jsonParser(file);
		if (values.find("name") != values.end() && values.find("hp") != values.end() && values.find("dmg") != values.end()) {
			file.close();
			return character(values["name"], stoi(values["hp"]), stoi(values["dmg"]));
		}
		else throw "incorrect values";
	}
}