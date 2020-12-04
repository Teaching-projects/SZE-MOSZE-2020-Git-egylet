#include "Map.h"
#include "Game.h"


Game::Game() : map() {}
Game::Game(std::string mapfilename) : map(mapfilename) {}

void Game::setMap(Map maptoset)
{
	map = maptoset;
	mapIsSet = true;
}

void Game::putHero(Hero hero, int x, int y)
{
	if (map.get(x, y) == Map::type::Free) {
		hero_position = std::make_pair(x, y);
		heroset = true;
		this->hero = new Hero(hero);
	}
	else throw OccupiedException("Location unavailable! \n");
}

void Game::putMonster(Monster monster, int x, int y)
{
	if (map.get(x, y) == Map::type::Wall && std::make_pair(x, y) != hero_position)
		monster_position.push_back(std::make_pair(monster, std::make_pair(x, y)));
	
	else throw OccupiedException("Location unavailable! \n");
}


bool Game::validateMove(const std::string dir)
{
	if (dir == "north") return (map.get(hero_position.first, hero_position.second -1 ) != Map::type::Wall);
	else if (dir == "south") return (map.get(hero_position.first, hero_position.second + 1) != Map::type::Wall);
	else if (dir == "east") return (map.get(hero_position.first + 1, hero_position.second) != Map::type::Wall);
	else if (dir == "west") return (map.get(hero_position.first - 1, hero_position.second) != Map::type::Wall);
	else return false;
}


void Game::moveHero(const std::string direction) {
	if (direction == "north") hero_position.second--;
	if (direction == "south") hero_position.second++;
	if (direction == "east") hero_position.first++;
	if (direction == "west") hero_position.first--;
}

int Game::getMonsterCount(int x, int y)
{
	int monstercount = 0;
	for (auto i = monster_position.begin(); i != monster_position.end(); i++)
	{
		if (i->second.first == x && i->second.second == y) monstercount++;
	}
	return monstercount;
}

void Game::printMap() 
{
	int MaxWidth = map.horizontalget();
	std::cout << "╔";
	for (int i = 0; i < MaxWidth; i++) std::cout << "═";
	std::cout << "╗";

	for (int i = 0; i < map.getmapsize(); i++)
	{
		std::cout << "║";
		for (int j = 0; j < map.getwidth(i); j++)
		{
			if (map.get(i, j) == Map::type::Free) std::cout << "░░";
			else if (map.get(i, j) == Map::type::Wall) std::cout << "██";
			else if (std::make_pair(i, j) == hero_position) std::cout << "┣┫";
			else if (getMonsterCount(i, j) == 1) std::cout << "M";
			else if (getMonsterCount(i, j) > 1) std::cout << "MM";
			
		}
	}

	std::cout << "╚";

	for (int i = 0; i < MaxWidth; i++)
		std::cout << "═";

	std::cout << "╝" << std::endl;

}


void Game::run()
{

	if (!heroset && !mapIsSet && !game_is_running)
	{
		game_is_running = true;
		while (hero->isAlive() && !monster_position.empty())
		{
			printMap();


		}

	}
	else if (heroset) throw AlreadyHasHeroException("There is a hero already!");
	else if (mapIsSet) throw NotInitializedException("xd");





}







