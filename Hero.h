/**
\class Hero
This is the description of Hero.h
\version 1.2
\author destrike00
\date 2020/10/30 14:36
Created on: 2020/10/30 14:36
*/

#ifndef HERO_H
#define HERO_H

#include "Monster.h"

class Hero : public Monster
{	

protected:
	const std::string name;	///< The hero's name
	int level;	///< The hero's level
	int maxHP;	///< The hero's maximum health points
	int XP;		///< The hero's experience
	int light_radius;		///< The hero's light radius
	
	int experience_per_level;	///< The hero's experience per level
	int health_point_bonus_per_level;	///< The hero's health point bonus per level
	int physical_damage_bonus_per_level;	///< The hero's physical damage bonus per level
	double cooldown_multiplier_per_level;	///< The hero's cooldown multiplier per level
	double defense_bonus_per_level;	///< The hero's defense bonus per level
	int magical_damage_bonus_per_level;	///< The hero's magical damage bonus per level
	int light_radius_bonus_per_level;	///< The hero's light radius bonus per level
	
	void levelup(); ///< Controlling levelup
	
public:

	Hero(const std::string, int, Damage, double, double, int, int, int, int, double, double, int, int);	///< This is a Hero constructor

	int getLevel() const;	///< This is a simple getter for level
	int getExperience() const; ///< This is a simple getter for experience
	int getMaxHealthPoints() const;	///< This is a simple getter for maxHP
	int getLightRadius() const; ///< This is a simple getter for light_radius
	int getExperiencePerLevel() const;	///< This is a simple getter for experience_per_level
	int getHealthPointBonusPerLevel() const;	///< This is a simple getter for health_point_bonus_per_level
	int getPhysicalDamageBonusPerLevel() const;	///< This is a simple getter for physical_damage_bonus_per_level
	double getCooldownMultiplierPerLevel() const;	///< This is a simple getter for cooldown_multiplier_per_level
	double getDefenseBonusPerLevel() const;	///< This is a simple getter for defense_bonus_per_level
	int getMagicalDamageBonusPerLevel()  const;	///< This is a simple getter for magical_damage_bonus_per_level
	int getLightRadiusBonusPerLevel() const; ///< This is a simple getter for light_radius_bonus_per_level
	void getHit(Monster* target);	///< This takes one hit
	void hit(Monster* target) override;	///< Hero hit function
	static Hero parse(const std::string& name);	///< This reads in the hero data from file
};

#endif //HERO_H