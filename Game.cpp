#include "Map.h"
#include "Game.h"

void Game::setMap(Map maptoset)
{
	/*if (!game_is_running) {
		if (heroset || !monster_position.empty()) throw AlreadyHasUnitsException("There are units on the map already!");
		else {
			map = maptoset;
			mapIsSet = true;
		}
	}*/
	if (!mapIsSet)
	{
		this->map = maptoset;
		mapIsSet = true;
	}
	else Map::WrongIndexException("Map already set!");
}

void Game::putHero(Hero hero, int x, int y)
{
	if (heroset) throw AlreadyHasHeroException("There is a hero already!");
	if (map.get(x, y) == Map::type::Free) {
		hero_position = std::make_pair(x, y);
		heroset = true;
		this->hero = new Hero(hero);
		
	}
	else throw OccupiedException("Location unavailable1! \n");
}

void Game::putMonster(Monster monster, int x, int y)
{
	if (map.get(x, y) != Map::type::Wall)
		monster_position.push_back(std::make_pair(monster, std::make_pair(x, y)));
	
	else throw OccupiedException("Location unavailable2! \n");
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
	if (direction == "north") hero_position.second-=1;
	if (direction == "south") hero_position.second+=1;
	if (direction == "east") hero_position.first+=1;
	if (direction == "west") hero_position.first-=1;
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
	for (int i = 0; i < MaxWidth; i++)
	{
		std::cout << "══";
	}

	std::cout << "╗" << std::endl;;

	for (int i = 0; i < map.getmapsize(); i++)
	{
		std::cout << "║";

		for (int j = 0; j < map.getwidth(i); j++)
		{
			if (std::make_pair(j,i)==hero_position) std::cout << "┣┫";
			else if (getMonsterCount(j, i) == 1) std::cout << "M░";
			else if (getMonsterCount(j, i) > 1) std::cout << "MM";
			else if (map.get(j, i) == Map::type::Free) std::cout << "░░";
			else if (map.get(j, i) == Map::type::Wall) std::cout << "██";
			
			
		}
		if (map.getwidth(i) < MaxWidth)
			for (int k = 0; k < (MaxWidth - map.getwidth(i)); k++)
			{
				std::cout << "██";
			}
		std::cout << "║" << std::endl;

	}

	std::cout << "╚";

	for (int i = 0; i < MaxWidth; i++)
	{
		std::cout << "══";
	}
	std::cout << "╝" << std::endl;

}


void Game::run()
{

	std::string direction;
	std::list<std::string> inputs = { "north","south","west","east" };
	if (heroset && mapIsSet && !game_is_running)
	{
		auto index = monster_position.begin();
		game_is_running = true;
		while (hero->isAlive() || !monster_position.empty())
		{
			printMap();

			do
			{
				std::cout << "Choose the direction! (north/south/west/east)" << std::endl;
				std::cin >> direction;
			}
			while (std::find(inputs.begin(), inputs.end(), direction) == inputs.end() || !validateMove(direction));
			

			moveHero(direction);
			

			while (index->second.first == hero_position.first && index->second.second == hero_position.second)
			{
				hero->fightTilDeath(index->first);
				if (!index->first.isAlive())
				{
					monster_position.pop_front();
				}
			}
		
		}
		//std::cout << (hero->isAlive() ? "The hero cleared the map." : "The hero died.") << std::endl;
		if (hero->isAlive())
			std::cout << std::endl << hero->getName() << " cleared the map." << std::endl;
		else std::cout << "The hero died";
	}
	else if (!mapIsSet) throw Map::WrongIndexException("Map was not set!");
}







