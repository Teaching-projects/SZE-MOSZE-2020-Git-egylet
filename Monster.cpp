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
	Damage DMGS,
	double ACD,
	double DEF
	) : 
	characterName(name),
	characterHP(HP),
	damage(DMGS),
	characterACD(ACD),
	characterDEF(DEF)	
{}

//Getters for protected parameters
std::string Monster::getName() const {
    return characterName;
}

int Monster::getHealthPoints() const {
    return characterHP;
}

Damage Monster::getDamage() const {
    return damage;
}

double Monster::getAttackCoolDown() const {
    return characterACD;
}

double Monster::getDefense() const {
    return characterDEF;
}

bool Monster::isAlive() const {
     return this->characterHP > 0;
}

//Uses target's damage getter to lower the object's health
void Monster::getHit(Monster* target ) {
	Damage tmp = target->getDamage();
	double finalphysicaldamage = tmp.getPhysical() - characterDEF;
	if (finalphysicaldamage < 0) finalphysicaldamage=0;
	characterHP -= finalphysicaldamage;	///< Takes one physical hit
	characterHP -= tmp.getMagical();	///< Takes one magical hit
	if (characterHP < 0) characterHP = 0;	///< Restores HP to 0 if HP decreases below 0
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
	std::vector<std::string> find
	{
		"name",
		"health_points", 
		"attack_cooldown",
		"defense"
	};        
    
    bool load = true;
	for (auto k : find)
	{
		if(!values.count(k)) load = false;
	}

	if (load)
	{
		Damage monsterdamage;
		
		if(values.count("damage")) monsterdamage.setPhysical(values.get<int>("damage"));
	    else monsterdamage.setPhysical(0);
	
	    if(values.count("magical-damage")) monsterdamage.setMagical(values.get<int>("magical-damage"));
	    else monsterdamage.setMagical(0);


		//monsterdamage.setPhysical(values.get<int>("damage"));
		//monsterdamage.setMagical(values.get<int>("magical-damage"));
		
		return Monster
		(
			values.get<std::string>("name"),
			values.get<int>("health_points"),
			monsterdamage,
			values.get<double>("attack_cooldown"),
			values.get<double>("defense")
        );
	}
	else throw JSON::ParseException("incorrect values:" + name);
}