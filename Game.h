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
	std::list<std::pair<Monster, std::pair<int, int>>> monster_positions;
	
	
public:
	Game(std::string mapfilename);
	void setMap(Map maptoset);
	void putHero(Hero hero, int x, int y);
	void putMonster(Monster monster, int x, int y);
	void run();
	void printMap() const;

	const std::string TOP_LEFT = "╔";
	const std::string TOP_RIGHT = "╗";
	const std::string BOTTOM_LEFT = "╚";
	const std::string BOTTOM_RIGHT = "╝";
	const std::string VERTICAL = "═";
	const std::string HORIZONTAL = "║";
	const std::string FREE_BLOCK = "░";
	const std::string WALL_BLOCK = "█";
	const std::string HERO_BLOCK = "┣┫";
	const std::string ONEMONSTER_BLOCK = "M";
	const std::string MOREMONSTERS_BLOCK = "MM";

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
