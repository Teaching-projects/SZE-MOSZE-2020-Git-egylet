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
			Damage damage,
			double characterACD,
			double characterDEF,
			int characterLR,
			int XPperlevel,
			int HPperlevel,
			int PDMGperlevel,
			double ACDperlevel,
			double DEFperlevel,
			int MDMGperlevel,
			int LRperlevel
		) : Monster
		(	
			characterName,
			characterHP,
			damage,
			characterACD,
			characterDEF),
			level(1),
			maxHP(characterHP),
			XP(0),
			light_radius(characterLR),
			experience_per_level(XPperlevel),
			health_point_bonus_per_level(HPperlevel),
			physical_damage_bonus_per_level(PDMGperlevel),
			cooldown_multiplier_per_level(ACDperlevel),
			defense_bonus_per_level(DEFperlevel),
			magical_damage_bonus_per_level(MDMGperlevel),
			light_radius_bonus_per_level(LRperlevel)
{}



//Getters
int Hero::getLevel() const {
    return level;
}

int Hero::getExperience() const {
    return XP;
}

int Hero::getMaxHealthPoints() const {
    return maxHP;
}

int Hero::getLightRadius() const {
    return light_radius;
}

int Hero::getExperiencePerLevel() const {
    return experience_per_level;
}

int Hero::getHealthPointBonusPerLevel() const {
    return health_point_bonus_per_level;
}

int Hero::getPhysicalDamageBonusPerLevel() const {
    return physical_damage_bonus_per_level;
}

double Hero::getCooldownMultiplierPerLevel() const {
    return cooldown_multiplier_per_level;
}

double Hero::getDefenseBonusPerLevel() const {
    return defense_bonus_per_level;
}

int Hero::getMagicalDamageBonusPerLevel() const {
    return magical_damage_bonus_per_level;
}

int Hero::getLightRadiusBonusPerLevel() const {
    return light_radius_bonus_per_level;
}

//If the hero reaches the required amount of XP, this function buffs the hero, and restore it to maximum health
void Hero::levelup() {
	Damage bonus (physical_damage_bonus_per_level, magical_damage_bonus_per_level);
	
	level++;
	maxHP += health_point_bonus_per_level;
	maxHP = round(maxHP);
	damage += bonus;
	characterHP = maxHP;
	characterACD *= cooldown_multiplier_per_level;
	characterDEF += defense_bonus_per_level;

}

//Delivers the getHit function, and calculates the amount of XP the hero is going to get
void Hero::getHit(Monster* target ) {
	Damage tmp = target->getDamage();
	double finalphysicaldamage = tmp.getPhysical() - characterDEF;
	if (finalphysicaldamage < 0) finalphysicaldamage=0;
	characterHP -= finalphysicaldamage;	///< Takes one physical hit
	characterHP -= tmp.getMagical();	///< Takes one magical hit
	if (characterHP < 0) characterHP = 0;	///< Restores HP to 0 if HP decreases below 0
}

void Hero::hit(Monster* target) {
	int XpToAdd = 0;
	if (target->getHealthPoints() < damage.getPhysical())
	{

		XpToAdd = target->getHealthPoints();

	}
	else
	{

		XpToAdd = damage.getPhysical();
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
		"base_attack_cooldown",
		"defense",
		
		"experience_per_level",
		"health_point_bonus_per_level",
		"physical_damage_bonus_per_level",
		"cooldown_multiplier_per_level",
		"defense_bonus_per_level",
		"magical_damage_bonus_per_level"
	};	///< Set keywords
    
    bool load = true;
	for (auto k : find)
	{
		if(!values.count(k)) load = false;
	}
	
	if (load)	///< Load data from file
	{
		Damage monsterdamage (0,0);
		
		if(values.count("damage")) monsterdamage.setPhysical(values.get<int>("damage"));
	    else monsterdamage.setPhysical(0);
	
	    if(values.count("magical-damage")) monsterdamage.setMagical(values.get<int>("magical-damage"));
	    else monsterdamage.setMagical(0);

		return Hero
		(
			values.get<std::string>("name"),
			values.get<int>("base_health_points"),
			monsterdamage,
			values.get<double>("base_attack_cooldown"),
			values.get<double>("defense"),
			
			values.get<int>("experience_per_level"),
			values.get<int>("health_point_bonus_per_level"),
			values.get<int>("physical_damage_bonus_per_level"),
			values.get<double>("cooldown_multiplier_per_level"),
			values.get<double>("defense_bonus_per_level"),
			values.get<int>("magical_damage_bonus_per_level")
        );
	}
	else throw JSON::ParseException("incorrect values: " + name);
}