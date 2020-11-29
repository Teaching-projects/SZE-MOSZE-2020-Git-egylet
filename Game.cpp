#include "Map.h"
#include "Game.h"


Game::Game() : map() {}
Game::Game(std::string mapfilename) : map(mapfilename) {}

void Game::setMap(Map maptoset)
{
	map = maptoset;
}

void Game::putHero(Hero hero, int x, int y)
{
	if (map.get(x, y) == Map::type::Free) {
		hero_position = std::make_pair(x, y);
		this->hero = new Hero(hero);
	}
	else throw Game::OccupiedException("Location unavailable! \n");
}

void Game::putMonster(Monster monster, int x, int y)
{
	if (map.get(x, y) == Map::type::Free)
	{
		monster_positions.push_back(std::make_pair(monster, std::make_pair(x, y)));
	}
}

void Game::moveHero(const std::string direction) {
	if (direction == "north") hero_position.second++;
	if (direction == "south") hero.second--;
	if (direction == "east") hero_position.first++;
	if (direction == "west") hero.first--;
}

void Game::printMap() 
{
	int MaxWidth = map.horizontalget();
	std::cout << "╔";
	for (int i = 0; i < MaxWidth; i++) std::cout << "║";
	std::cout << "╗";

	for (int i = 0; i < map.getmapsize(); i++)
	{
		std::cout << "═";
		for (int j = 0; j < map.getwidth(i); j++)
		{
			if (map.get(i, j) == Map::type::Free) std::cout << "░░";
			else if (map.get(i, j) == Map::type::Wall) std::cout << "██";
			else if (hero_position.first==i&&hero_position.second==j) std::cout << "┣┫";
			
		}
	}

	std::cout << "╚";

	for (int i = 0; i < MaxWidth; i++)
		std::cout << "═";

	std::cout << "╝" << std::endl;

}






