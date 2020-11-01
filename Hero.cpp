#include "Hero.h"
#include "Monster.h"
#include "JSON.h"
#include <cmath>
#include <fstream>
#include <any>

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

//~ std::string Hero::attack(Monster& player1 /** This is a player parameter*/, Monster& player2 /** This is a player parameter*/) {
	//~ double time1 = 0;	///< First player's time counter
	//~ double time2 = 0;	///< Second player's time counter
	//~ int XpToAdd = 0;
	//~ while (player1.isAlive() && player2.isAlive()) {
		

		//~ if (player2.getHealthPoints() < player1.getDamage())
		//~ {

			//~ XpToAdd = player2.getHealthPoints();

		//~ }
		//~ else
		//~ {

			//~ XpToAdd = player1.getDamage();
		//~ }

		//~ XP += XpToAdd;

		//~ if (XP >= 100)
		//~ {
			//~ int LvlToAdd = XP / 100;
			//~ for (int i = 0; i < LvlToAdd; i++)
			//~ {
				//~ levelup();

			//~ }
			//~ XP -= LvlToAdd * 100;
		//~ }

		//~ ///Player1 is the next
		//~ if (time1 /**First player's time counter*/ < time2 /**Second player's time counter*/) {
			//~ player1.hit(player2 /**This is a player parameter*/);
			//~ if (!player2.isAlive(/** Here is no parameter*/)) {
				//~ std::string result = makeResults(player1.getName(/** Here is no parameter*/), player1.getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				//~ return result;	///< \return The winner and the remaining HP
			//~ }
			//~ time1 += player1.getAttackCoolDown();	///< Increases first player's time counter with first player's ACD
		//~ }

		//~ ///Player2 is the next
		//~ else if (time1 /**First player's time counter*/ > time2 /**Second player's time counter*/) {
			//~ player2.hit(player1 /**This is a player parameter*/);
			//~ if (!player1.isAlive(/** Here is no parameter*/)) {
				//~ std::string result = makeResults(player2.getName(/** Here is no parameter*/), player2.getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				//~ return result;	///< \return The winner and the remaining HP
			//~ }
			//~ time2 += player2.getAttackCoolDown();	///< Increases second player's time counter with first player's ACD
		//~ }

		//~ ///Both players hits at the same time, the first is who started the attack
		//~ else {
			//~ player1.hit(player2 /**This is a player parameter*/);
			//~ if (!player2.isAlive(/** Here is no parameter*/)) {
				//~ std::string result = makeResults(player1.getName(/** Here is no parameter*/), player1.getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				//~ return result;	///< \return The winner and the remaining HP
			//~ }
			//~ time1 += player1.getAttackCoolDown();	///< Increases first player's time counter with first player's ACD
			//~ player2.hit(player1 /**This is a player parameter*/);
			//~ if (!player1.isAlive(/** Here is no parameter*/)) {
				//~ std::string result = makeResults(player2.getName(/** Here is no parameter*/), player2.getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				//~ return result;	///< \return The winner and the remaining HP
			//~ }
			//~ time2 += player2.getAttackCoolDown();	///< Increases second player's time counter with first player's ACD
		//~ }
	//~ }
	//~ return 0;
//~ }
void Hero::getHit(Monster* target /** This is a player parameter*/) {
	this->characterHP -= target->getDamage(); ///< Takes one hit
	if (this->characterHP < 0) this->characterHP = 0; ///< Restores HP to 0 if HP decreases below 0
}

void Hero::hit(Monster* target) {
	target->getHit(this);
}
std::string Hero::fightTilDeath(Monster target) {
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
			if (!target.isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(this->getName(/** Here is no parameter*/), this->getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time1 +=this->getAttackCoolDown();	///< Increases first player's time counter with first player's ACD
		}

		///Player2 is the next
		else if (time1 /**First player's time counter*/ > time2 /**Second player's time counter*/) {
			target.hit(this /**This is a player parameter*/);
			if (!this->isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(target.getName(/** Here is no parameter*/), target.getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time2 += target.getAttackCoolDown();	///< Increases second player's time counter with first player's ACD
		}

		///Both players hits at the same time, the first is who started the attack
		else {
			this->hit(&target /**This is a player parameter*/);
			if (!target.isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(this->getName(/** Here is no parameter*/), this->getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time1 += this->getAttackCoolDown();	///< Increases first player's time counter with first player's ACD
			target.hit(this /**This is a player parameter*/);
			if (!this->isAlive(/** Here is no parameter*/)) {
				std::string result = makeResults(target.getName(/** Here is no parameter*/), target.getHealthPoints(/** Here is no parameter*/)); 	///< Makes result string, that contains the winner and the remaining HP
				return result;	///< \return The winner and the remaining HP
			}
			time2 += target.getAttackCoolDown();	///< Increases second player's time counter with first player's ACD
		}
	}
	return 0;
}

//~ Hero Hero::parse(const std::string& name) {
	//~ JSON values = JSON::jsonParser(name);
	//~ const std::vector<std::string> find{"name", "hp", "dmg", "acd"};
    //~ for (int i = 0; i < find.size(); i++)
    //~ {
        //~ if (!values.count(find[i]))
        //~ {
            //~ throw std::invalid_argument("JSON Error: " + name + "-> " + find[i]);
        //~ }
    //~ }

    //~ return Hero
		//~ (
        //~ values.get<std::string>("name"),
        //~ values.get<int>("hp"),
        //~ values.get<int>("dmg"),
        //~ values.get<float>("acd")
        //~ );
//~ }

Hero Hero::parse(const std::string& name) {
	JSON values = JSON::jsonParser(name);
	const std::vector<std::string> find{"name", "health_points", "damage", "attack_cooldown"};        
    
    bool load = true;
	for (auto key : find)
        if(!values.count(key))
			load = false;

	if (load) 
		return Hero
		(
        values.get<std::string>("name"),
        values.get<int>("health_points"),
        values.get<int>("damage"),
        values.get<float>("attack_cooldown")
        );
	else throw JSON::ParseException("Incorrect attributes in " + name + "!");
}
