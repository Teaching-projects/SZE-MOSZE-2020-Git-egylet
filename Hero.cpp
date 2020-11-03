#include "Hero.h"
#include "Monster.h"
#include "JSON.h"
#include <cmath>
#include <fstream>
#include <vector>

//This is the constructor
Hero::Hero(
			const std::string characterName,
			int characterHP,
			int characterDMG,
			double characterACD,
			int XPperlevel,
			int HPperlevel,
			int DMGperlevel,
			float ACDperlevel
		) : Monster
		(	
			characterName,
			characterHP,
			characterDMG,
			characterACD),
			level(1),
			maxHP(characterHP),
			XP(0),
			experience_per_level(XPperlevel),
			health_point_bonus_per_level(HPperlevel),
			damage_bonus_per_level(DMGperlevel),
			cooldown_multiplier_per_level(ACDperlevel)
{}

//Getters 
int Hero::getLevel(/** Here is no parameter*/) {
    return level;
}

int Hero::getMaxHealthPoints(/** Here is no parameter*/) {
    return maxHP;
}

//Buffs the hero when it hits a new level, and heals it to max health
void Hero::levelup() {
	level++;
	maxHP += health_point_bonus_per_level;
	maxHP = round(maxHP);
	characterDMG += damage_bonus_per_level;
	characterHP = maxHP;
	characterACD *= cooldown_multiplier_per_level;

}

void Hero::getHit(Monster* target ) {
	characterHP-= target->getDamage(); ///< Takes one hit
	if (characterHP < 0) characterHP = 0; ///< Restores HP to 0 if HP decreases below 0
}

//Delivers the getHit function to the target, and calculates the XP the hero is going to receive 
void Hero::hit(Monster* target) {
	int XpToAdd = 0;
	if (target->getHealthPoints() < characterDMG)
	{

		XpToAdd = target->getHealthPoints();

	}
	else
	{

		XpToAdd = characterDMG;
	}
	target->getHit(this);
	XP += XpToAdd;
	if (XP >= experience_per_level)
	{
		int LvlToAdd = XP / experience_per_level;
		for (int i = 0; i < LvlToAdd; i++)
		{

			levelup();

		}
		XP -= LvlToAdd * experience_per_level;
	}
}

//Parser function to return a Hero object from a JSON file
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
			stof(values.get<std::string>("base_attack_cooldown")),
			
			stoi(values.get<std::string>("experience_per_level")),
			stoi(values.get<std::string>("health_point_bonus_per_level")),
			stoi(values.get<std::string>("damage_bonus_per_level")),
			stof(values.get<std::string>("cooldown_multiplier_per_level"))
        );
	}
	else throw JSON::ParseException("incorrect values: " + name);
}
