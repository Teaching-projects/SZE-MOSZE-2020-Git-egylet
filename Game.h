#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <string>
#include <list>
#include "Map.h"
#include "Monster.h"
#include "Hero.h"
#include <algorithm>


class Game {

private:
	Map map; ///< The game map
	bool game_is_running; ///< The game is running or not running
	bool mapIsSet;
	bool heroset;
	Hero* hero; ///< Hero type pointer
	std::pair<int, int> hero_position; ///< The hero x-y position storage
	std::list<std::pair<Monster, std::pair<int, int>>> monster_position; ///< The monster x-y position storage

public:
	Game() : map(Map()), game_is_running(false), mapIsSet(false), heroset(false) {}; ///< The Game default constructor
	Game(const std::string& mapfilename) : map(Map(mapfilename)), game_is_running(false), mapIsSet(true), heroset(false) {}; ///< The Game constructor according to the map
	virtual ~Game() { delete this->hero; } ///< The Game default destructor
	void setMap(Map maptoset); ///< Configure the map 
	void putHero(Hero hero, int x, int y); ///< Put the Hero to the map
	void putMonster(Monster monster, int x, int y); ///< Out the Monster to the map
	void moveHero(const std::string direction); ///< Player character control
	bool validateMove(const std::string dir ); ///< Player character control manipulation
	int getMonsterCount(int x, int y); ///< Get Monster number of pieces
	void run(); ///< Manipulation the full game structure
	void printMap() ; ///< Drawing the map

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
#endif
