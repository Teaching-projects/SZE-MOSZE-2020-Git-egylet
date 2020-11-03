#include "Character.h"
class Player : public Character
{	

protected:
	const std::string name;
	double maxHP;
	int level;
	int XP;	
	void levelup();

public:
	Player(const std::string& characterName, int characterHP, int characterDMG, double characterACD) : Character(characterName, characterHP, characterDMG,characterACD), maxHP(characterHP), level(1), XP(0) {};
	static Player parseUnit(const std::string& name);
	std::string attack(Character& player1, Character& player2);
};