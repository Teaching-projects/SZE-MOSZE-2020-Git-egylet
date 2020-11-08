#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Monster.h"
#include "JSON.h"

//This is the constructor
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

//Getters for protected parameters
std::string Monster::getName() const {
    return characterName;
}

int Monster::getHealthPoints() const {
    return characterHP;
}

int Monster::getDamage() const {
    return characterDMG;
}

double Monster::getAttackCoolDown() const {
    return characterACD;
}

bool Monster::isAlive() const {
     return this->characterHP > 0;
}

//Uses target's damage getter to lower the object's health
void Monster::getHit(Monster* target ) {
	characterHP -= target->getDamage(); ///< Takes one hit
	if (characterHP < 0) characterHP = 0; ///< Restores HP to 0 if HP decreases below 0
}
//Delivering getHit function on given target
void Monster::hit(Monster* target) {
	target->getHit(this);
}

void Monster::fightTilDeath(Monster& target) {
	double time1 = 0;	///< First player's time counter
	double time2 = 0;	///< Second player's time counter

	///Both players hits at the same time, the first is who started the attack
	this->hit(&target /**This is a player parameter*/);
	target.hit(this /**This is a player parameter*/);

	//The fight goes on until one of the participants die
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

//Parser function to return a Monster object from a JSON file
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
			values.get<int>("health_points"),
			values.get<int>("damage"),
			values.get<double>("attack_cooldown")
        );
	}
	else throw JSON::ParseException("incorrect values:" + name);
}