#include "Monster.h"

class Hero : public Monster
{	

protected:
	const std::string name;
	int maxHP;
	int level;
	int XP;	
	
	int experience_per_level;
	int health_point_bonus_per_level;
	int damage_bonus_per_level;
	double cooldown_multiplier_per_level;
	
	void levelup();

public:

	Hero(
		
		const std::string& characterName,
		int characterHP,
		int characterDMG,
		double characterACD,
		
		int experience_per_level,
		int health_point_bonus_per_level,
		int damage_bonus_per_level,
		double cooldown_multiplier_per_level
		
		)
		: Monster
		(
			characterName,
			characterHP,
			characterDMG,
			characterACD
		),
			maxHP(characterHP),
			level(1),
			XP(0),
			
			experience_per_level(experience_per_level),
			health_point_bonus_per_level(health_point_bonus_per_level),
			damage_bonus_per_level(damage_bonus_per_level),
			cooldown_multiplier_per_level(cooldown_multiplier_per_level)
		{};
	
	int getLevel();
	int getMaxHealthPoints();
	void getHit(Monster* target);
	void hit(Monster* target);
	static Hero parse(const std::string& name);
	void fightTilDeath(Monster& target);
};
