#ifndef HERO_H
#define HERO_H
#include "Monster.h"

class Hero : public Monster
{	

protected:
	const std::string name;
	int level;
	int maxHP;
	int XP;	
	
	int experience_per_level;
	int health_point_bonus_per_level;
	int physical_damage_bonus_per_level;
	double cooldown_multiplier_per_level;
	double defense_bonus_per_level;
	int magical_damage_bonus_per_level;
	
	void levelup();

public:

	Hero(const std::string, int, Damage, double, double, int, int, int, double, double, int);

	int getLevel() const;
	int getMaxHealthPoints() const;
	int getExperiencePerLevel() const;
	int getHealthPointBonusPerLevel () const;
	int getPhysicalDamageBonusPerLevel () const;
	double getCooldownMultiplierPerLevel () const;
	double getDefenseBonusPerLevel () const;
	int getMagicalDamageBonusPerLevel ()  const;
	void getHit(Monster* target);
	void hit(Monster* target) override;
	static Hero parse(const std::string& name);
};
#endif