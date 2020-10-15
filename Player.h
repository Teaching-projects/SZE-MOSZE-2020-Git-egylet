#include "Character.h"
#include <math.h>
class Player : public Character
{	

protected:
	const std::string name;
	int level;
	int XP;
	int maxHP;
	void levelup();

public:
	Player(const std::string characterName, int characterHP, int characterDMG) : Character(characterName, characterHP, characterDMG), maxHP(characterHP), level(1), XP(1) {}
	static Player parseUnit(const std::string& name);
	void attack(Character* enemy);
};