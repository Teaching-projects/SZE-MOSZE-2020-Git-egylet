#include <iostream>
#include <string>
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

void character::attack(character& target)  {
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


