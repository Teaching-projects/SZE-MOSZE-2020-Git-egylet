#include <iostream>
#include <string>
#include <fstream>
#include "Character.h"
#include "JsonParser.h"

Character::Character(std::string name, int HP, int DMG) : characterName(name), characterHP(HP), characterDMG(DMG) {}

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

void Character::attack(Character& target) const  {

    if (target.characterHP < this->characterDMG) {
        target.characterHP = 0;
    }
    else {
        target.characterHP -= this->characterDMG;
    }
}

bool Character::isAlive() const {
     return this->characterHP > 0;
}

std::ostream& operator<<(std::ostream& os, const Character& obj) {
    return os << obj.getName() << ": HP: " << obj.getHP() << " DMG: " << obj.getDMG() << std::endl;
}

Character Character::parseUnit(const std::string& name) {
	std::ifstream file;
	file.open(name);

	Parser parser;
	std::map<std::string, std::string> values = parser.jsonParser(file);
	if (values.find("name") != values.end() && values.find("hp") != values.end() && values.find("dmg") != values.end()) {
		file.close();
		return Character(values["name"], stoi(values["hp"]), stoi(values["dmg"]));
	}
	else throw "incorrect values";
}
