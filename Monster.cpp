#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Monster.h"
#include "JSON.h"

Monster::Monster
(
	std::string name,
	int HP,
	int DMG,
	double ACD
	) : 
	characterName(name),
	characterHP(HP),
	characterDMG(DMG),
	characterACD(ACD)
{}

std::string Monster::getName(/** Here is no parameter*/) const {
    return characterName;
}

int Monster::getHealthPoints(/** Here is no parameter*/) const {
    return characterHP;
}

int Monster::getDamage(/** Here is no parameter*/) const {
    return characterDMG;
}

double Monster::getAttackCoolDown(/** Here is no parameter*/) const {
    return characterACD;
}

bool Monster::isAlive(/** Here is no parameter*/) const {
     return this->characterHP > 0;
}

void Monster::getHit(Monster* target /** This is a player parameter*/) {
	characterHP -= target->getDamage(); ///< Takes one hit
	if (characterHP < 0) characterHP = 0; ///< Restores HP to 0 if HP decreases below 0
}

void Monster::hit(Monster* target) {
	target->getHit(this);
}

void Monster::fightTilDeath(Monster& target) {
	double time1 = 0;	///< First player's time counter
	double time2 = 0;	///< Second player's time counter

	///Both players hits at the same time, the first is who started the attack
	this->hit(&target /**This is a player parameter*/);
	target.hit(this /**This is a player parameter*/);

	while (this->isAlive() && target.isAlive()) {
		
		if (time1 >= getAttackCoolDown()) {
			this->hit(&target);
			time1 = 0;
		}
		else {
			time1++;
		}
		if (time2 >= target.getAttackCoolDown()) {
			target.hit(this);
			time2 = 0;
		}
		else time2++;
	}
}

Monster Monster::parse(const std::string& name) {
	JSON values = JSON::parseFromFile(name);
	const std::vector<std::string> find
	{
		"name",
		"health_points", 
		"damage",
		"attack_cooldown"
	};        
    
    bool load = true;
	for (auto k : find)
	{
		if(!values.count(k)) load = false;
	}

	if (load)
	{
		return Monster
		(
			values.get<std::string>("name"),
			stoi(values.get<std::string>("health_points")),
			stoi(values.get<std::string>("damage")),
			stod(values.get<std::string>("attack_cooldown"))
        );
	}
	else throw JSON::ParseException("incorrect values:" + name);
}
