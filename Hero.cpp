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
			double characterDEF,
			int XPperlevel,
			int HPperlevel,
			int DMGperlevel,
			double ACDperlevel,
			double DEFperlevel
		) : Monster
		(	
			characterName,
			characterHP,
			characterDMG,
			characterACD,
			characterDEF),
			level(1),
			maxHP(characterHP),
			XP(0),
			experience_per_level(XPperlevel),
			health_point_bonus_per_level(HPperlevel),
			damage_bonus_per_level(DMGperlevel),
			defense_bonus_per_level(DEFperlevel),
			cooldown_multiplier_per_level(ACDperlevel)
{}



//Getters
int Hero::getLevel() {
    return level;
}

int Hero::getMaxHealthPoints() {
    return maxHP;
}

//If the hero reaches the required amount of XP, this function buffs the hero, and restore it to maximum health
void Hero::levelup() {
	level++;
	maxHP += health_point_bonus_per_level;
	maxHP = round(maxHP);
	characterDMG += damage_bonus_per_level;
	characterHP = maxHP;
	characterACD *= cooldown_multiplier_per_level;
	characterDEF += defense_bonus_per_level;

}

//Delivers the getHit function, and calculates the amount of XP the hero is going to get
void Hero::getHit(Monster* target ) {
	double finaledamage = target->getDamage() - characterDEF;
	if (finaledamage < 0) finaledamage=0;
	characterHP -= finaledamage; ///< Takes one hit
	if (characterHP < 0) characterHP = 0; ///< Restores HP to 0 if HP decreases below 0
}

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
		"defense",
		
		"experience_per_level",
		"health_point_bonus_per_level",
		"damage_bonus_per_level",
		"defense_bonus_per_level",
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
			values.get<int>("base_health_points"),
			values.get<int>("base_damage"),
			values.get<double>("base_attack_cooldown"),
			values.get<double>("defense"),
			
			values.get<int>("experience_per_level"),
			values.get<int>("health_point_bonus_per_level"),
			values.get<int>("damage_bonus_per_level"),
			values.get<double>("defense_bonus_per_level"),
			values.get<double>("cooldown_multiplier_per_level")
        );
	}
	else throw JSON::ParseException("incorrect values: " + name);
}