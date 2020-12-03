#include <iostream>
#include <string>
#include <list>
#include "Map.h"
#include "Monster.h"
#include "Hero.h"


class Game {

private:
	bool game_is_running;
	Map map;
	Hero* hero;
	std::pair<int, int> hero_position;
	std::list<std::pair<Monster, std::pair<int, int>>> monster_position;
	
	
public:
	Game();
	Game(std::string mapfilename);
	void setMap(Map maptoset);
	void putHero(Hero hero, int x, int y);
	void putMonster(Monster monster, int x, int y);
	void moveHero(const std::string direction);
	bool validateMove(const std::string dir );
	int getMonsterCount(int x, int y);
	bool mapIsSet();
	bool gameHasStarted();
	bool heroIsSet();
	void run();
	void printMap() ;

	class OccupiedException : virtual public std::runtime_error{
	public:
		OccupiedException(const std::string &err) : std::runtime_error(err) {}
	};

	class AlreadyHasHeroException : virtual public std::runtime_error {
	public:
		AlreadyHasHeroException(const std::string &err) : std::runtime_error(err) {}
	};

	class AlreadyHasUnitsException : virtual public std::runtime_error {
	public:
		AlreadyHasUnitsException(const std::string &err) : std::runtime_error(err) {}
	};

	class NotInitializedException : virtual public std::runtime_error {
	public:
		NotInitializedException(const std::string &err) : std::runtime_error(err) {}
	};

	class GameAlreadyStartedException : virtual public std::runtime_error {
	public:
		GameAlreadyStartedException(const std::string &err) : std::runtime_error(err) {}
	};
};
