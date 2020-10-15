#include "Character.h"
#include <math.h>
class Player : public Character
{	

protected:
	const std::string name;
	int characterDMG;
	int level;
	int XP;
	int maxHP;
	void levelup();

public:
	Player(const std::string characterName, int characterHP, int characterDMG, const int xp = 0) : Character(characterName, characterHP, characterDMG), XP(xp), maxHP(characterHP) {}

	static Player parseUnit(const std::string& name);
	void attack(Character* enemy);



	

};