#include "Map.h"
#include "Game.h"

void Game::setMap(Map maptoset)
{
	if (!mapIsSet && !game_is_running && monster_position.empty() && hero == nullptr)
	{
		this->map = maptoset;
		mapIsSet = true;
	}
	else if (mapIsSet)Map::WrongIndexException("Map already set!");
	else if (game_is_running) GameAlreadyStartedException("Game already started!");
	else if (!monster_position.empty()) AlreadyHasUnitsException("There are units on the map!");
	else if (hero != nullptr) AlreadyHasHeroException("There is a hero already");
}

void Game::putHero(Hero hero, int x, int y)
{
	if (!game_is_running) {
		if (heroset) throw AlreadyHasHeroException("There is a hero already!");
		else {
			if (mapIsSet) {
				if (map.get(x, y) == Map::type::Free) {
					hero_position = std::make_pair(x, y);
					heroset = true;
					this->hero = new Hero(hero);

				}
				else throw OccupiedException("Location unavailable! \n");
			}
			else throw Map::WrongIndexException("Map was not set!");
		}
	}
	else throw GameAlreadyStartedException("Game is already running!");
}

void Game::putMonster(Monster monster, int x, int y)
{
	if (mapIsSet) {
		if (map.get(x, y) != Map::type::Wall)
			monster_position.push_back(std::make_pair(monster, std::make_pair(x, y)));
	}
	else throw Map::WrongIndexException("Map was not set!");
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

void Game::printLightRadiusMap() 
{
	int lr = hero->getLightRadius(); // Hero's light radius
	int flr = 2*lr + 1; // Full light radius
	
	int heroxstart = hero_position.first - lr;
	if (hero_position.first - lr < 0) while(heroxstart < 0) heroxstart++;

	int heroxend = hero_position.first + lr;
	if (hero_position.first + lr > map.horizontalget()) while(heroxend > map.horizontalget()) heroxend--;

	int heroystart = hero_position.second - lr;
	if (hero_position.second - lr < 0) while(heroystart < 0) heroystart++;

	int heroyend = hero_position.second + lr;
	if (hero_position.second + lr > map.getmapsize()) while(heroyend > map.getmapsize()) heroyend--;

	std::cout << "╔";
	for (int i = heroxstart; i <= heroxend; i++)
	{
		std::cout << "══";
	}

	std::cout << "╗" << std::endl;

	for (int i = heroystart; i < heroyend; i++)
	{
		std::cout << "║";

		for (int j = heroxstart; j <= heroxend; j++)
		{
			if (std::make_pair(j,i)==hero_position) std::cout << "┣┫";
			else if (getMonsterCount(j, i) == 1) std::cout << "M░";
			else if (getMonsterCount(j, i) > 1) std::cout << "MM";
			else if (map.get(j, i) == Map::type::Free) std::cout << "░░";
			else if (map.get(j, i) == Map::type::Wall) std::cout << "██";
			
			
		}
		if (map.getwidth(i) < flr)
			for (int k = 0; k < (flr - map.getwidth(i)); k++)
			{
				std::cout << "██";
			}
		std::cout << "║" << std::endl;

	}

	std::cout << "╚";

	for (int i = heroxstart; i <= heroxend; i++)
	{
		std::cout << "══";
	}
	std::cout << "╝" << std::endl;

}

Map Game::getMap() const 
{
	return map;
}

void Game::run()
{

	std::string direction;
	std::list<std::string> inputs = { "north","south","west","east" };
	if (heroset && mapIsSet && !game_is_running)
	{
	
		game_is_running = true;
		while (hero->isAlive() && !monster_position.empty())
		{
			//printMap();
			printLightRadiusMap();

			do
			{
				std::cout << "Choose the direction! (north/south/west/east)" << std::endl;
				std::cin >> direction;
			}
			while (std::find(inputs.begin(), inputs.end(), direction) == inputs.end() || !validateMove(direction));
			

			moveHero(direction);
			

			
			if(monster_position.front().second.first==hero_position.first&&monster_position.front().second.second==hero_position.second)
			{
				 while (hero->isAlive()&&!monster_position.empty()) {
					 
					 hero->fightTilDeath(monster_position.front().first);

					 if (!monster_position.front().first.isAlive())
					 {
						 monster_position.pop_front();
					 }
				 }
			}
		
		}
		std::cout << (hero->isAlive() ? "The hero cleared the map." : "The hero died.") << std::endl;
	
	}
	else throw NotInitializedException("Bad initialization!");
}







