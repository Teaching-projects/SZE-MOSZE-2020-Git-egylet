#include <iostream>
#include <string>
#include "functions.h"


character::character(std::string name,int HP, int DMG)
{
    setName(name);
    setHP(HP);
    setDMG(DMG);
  
}


void character::setName(std::string name)
{
    characterName = name;
}
void character::setHP(int health)
{
    characterHP = health;
}
void character::setDMG(int dmg) {
    characterDMG = dmg;
}


void character::status() {
    std::cout << this->characterName << ": " << "HP: " << this->characterHP << " DMG: " << this->characterDMG << std::endl;
}


void character::attack(character& target) {
    std::cout << this->characterName << " -> " << target.characterName << std::endl;
    if (target.characterHP < this->characterDMG) {
        target.characterHP = 0;
    }
    else {
        target.characterHP -= this->characterDMG;
    }
}




bool character::isAlive() {
    if (this->characterHP> 0) {
        return true;
    }
    else {
        return false;
    }
    
}


