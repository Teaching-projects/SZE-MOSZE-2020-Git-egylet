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
	Hero(std::string name, int HP, int DMG, double ACD)
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
	
	static Hero parse(const std::string& name);
	std::string attack(Monster& player1, Monster& player2);
};
