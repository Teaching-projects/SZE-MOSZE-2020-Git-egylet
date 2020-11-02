#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Monster.h"
#include "JSON.h"

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
	target->characterHP -= this->characterDMG; ///< Takes one hit
	if (target->characterHP < 0) target->characterHP = 0; ///< Restores HP to 0 if HP decreases below 0
}

void Monster::hit(Monster* target) {
	target->getHit(this);
}

void Monster::fightTilDeath(Monster& target) {
	double time1 = 0;	///< First player's time counter
	double time2 = 0;	///< Second player's time counter
	while (this->isAlive() && target.isAlive()) {
		
		///Player1 is the next
		if (time1 /**First player's time counter*/ < time2 /**Second player's time counter*/) {
			this->hit(&target /**This is a player parameter*/);
			time1 +=this->getAttackCoolDown();	///< Increases first player's time counter with first player's ACD
		}

		///Player2 is the next
		else if (time1 /**First player's time counter*/ > time2 /**Second player's time counter*/) {
			target.hit(this /**This is a player parameter*/);
			time2 += target.getAttackCoolDown();	///< Increases second player's time counter with first player's ACD
		}

		///Both players hits at the same time, the first is who started the attack
		else {
			this->hit(&target /**This is a player parameter*/);
			time1 += this->getAttackCoolDown();	///< Increases first player's time counter with first player's ACD
			target.hit(this /**This is a player parameter*/);
			time2 += target.getAttackCoolDown();	///< Increases second player's time counter with first player's ACD
		}
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
