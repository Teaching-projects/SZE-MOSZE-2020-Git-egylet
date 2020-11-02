#include "Hero.h"
#include "Monster.h"
#include "JSON.h"
#include <cmath>
#include <fstream>
#include <vector>

int Hero::getLevel(/** Here is no parameter*/) {
    return level;
}

int Hero::getMaxHealthPoints(/** Here is no parameter*/) {
    return maxHP;
}

void Hero::levelup() {
	level++;
	maxHP *= 1.1;
	maxHP = round(maxHP);
	characterDMG *= 1.1;
	characterHP = maxHP;
}

void Hero::getHit(Monster* target /** This is a player parameter*/) {
	this->characterHP -= target->getDamage(); ///< Takes one hit
	if (this->characterHP < 0) this->characterHP = 0; ///< Restores HP to 0 if HP decreases below 0
}

void Hero::hit(Monster* target) {
	target->getHit(this);
}
void Hero::fightTilDeath(Monster& target) {
	double time1 = 0;	///< First player's time counter
	double time2 = 0;	///< Second player's time counter
	int XpToAdd = 0;
	while (this->isAlive() && target.isAlive()) {
		

		if (target.getHealthPoints() < this->getDamage())
		{

			XpToAdd = target.getHealthPoints();

		}
		else
		{

			XpToAdd = this->getDamage();
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

Hero Hero::parse(const std::string& name) {
	JSON values = JSON::parseFromFile(name);
	std::vector<std::string> find
	{
		"name",
		"base_health_points", 
		"base_damage",
		"base_attack_cooldown",
		
		"experience_per_level",
		"health_point_bonus_per_level",
		"damage_bonus_per_level",
		"cooldown_multiplier_per_level"
	};        
    
    bool load = true;
	for (auto k : find)
	{
		if(!values.count(k)) load = false;
	}
	
	if (load)
	{
		return Hero
		(
			values.get<std::string>("name"),
			stoi(values.get<std::string>("base_health_points")),
			stoi(values.get<std::string>("base_damage")),
			stod(values.get<std::string>("base_attack_cooldown")),
			
			stoi(values.get<std::string>("experience_per_level")),
			stoi(values.get<std::string>("health_point_bonus_per_level")),
			stoi(values.get<std::string>("damage_bonus_per_level")),
			stod(values.get<std::string>("cooldown_multiplier_per_level"))
        );
	}
	else throw JSON::ParseException("incorrect values: " + name);
}
