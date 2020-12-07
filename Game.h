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
	Map map;
	bool game_is_running;
	bool mapIsSet;
	bool heroset;
	Hero* hero;
	std::pair<int, int> hero_position;
	std::list<std::pair<Monster, std::pair<int, int>>> monster_position;

public:
	Game() : map(Map()), game_is_running(false), mapIsSet(false), heroset(false) {};
	Game(const std::string& mapfilename) : map(Map(mapfilename)), game_is_running(false), mapIsSet(true), heroset(false) {};
	virtual ~Game() { delete this->hero; }
	void setMap(Map maptoset);
	void putHero(Hero hero, int x, int y);
	void putMonster(Monster monster, int x, int y);
	void moveHero(const std::string direction);
	bool validateMove(const std::string dir );
	int getMonsterCount(int x, int y);
	Map getMap() const;
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
#endif