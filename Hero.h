#include "Monster.h"

class Hero : public Monster
{	

protected:
	const std::string name;
	int maxHP;
	int level;
	int XP;	
	void levelup();

public:
	Hero(const std::string& characterName, int characterHP, int characterDMG, double characterACD)
		: Monster
		(
		characterName,
		characterHP,
		characterDMG,
		characterACD
		),
		maxHP(characterHP),
		level(1),
		XP(0) 
		{};
	
	int getLevel();
	int getMaxHealthPoints();
	void getHit(Monster* target);
	void hit(Monster* target);
	static Hero parse(const std::string& name);
	//~ std::string attack(Monster& player1, Monster& player2);
	std::string fightTilDeath(Monster target);
};
