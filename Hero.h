#include "Monster.h"

class Hero : public Monster
{	

protected:
	const std::string name;
	int level;
	double maxHP;
	int XP;	
	
	int experience_per_level; //amount of experience needed to level up
	int health_point_bonus_per_level; //amount of bonus health the hero gets when leveling up
	int damage_bonus_per_level; //amount of bonus damage the hero gets when leveling up
	float cooldown_multiplier_per_level; // attack cooldown's multiplier when leveling up
	
	void levelup();

public:

	Hero(const std::string, int, int, double, int, int, int, float);

	int getLevel();
	int getMaxHealthPoints();
	void getHit(Monster* target);
	void hit(Monster* target) override;
	static Hero parse(const std::string& name);
};
