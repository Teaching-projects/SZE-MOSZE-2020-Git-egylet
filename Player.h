#include "Character.h"
class Player : public Character
{	

protected:
	const std::string name;
	int maxHP;
	int level;
	int XP;	
	void levelup();

public:
	Player(const std::string characterName, int characterHP, int characterDMG) : Character(characterName, characterHP, characterDMG), maxHP(characterHP), level(1), XP(0) {}
	static Player parseUnit(const std::string& name);
	void attack(Character& enemy);
};