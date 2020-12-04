#include "Map.h"
#include "Game.h"


Game::Game() : map() {}
Game::Game(std::string mapfilename) : map(mapfilename) {}

void Game::setMap(Map maptoset)
{
	if (!mapIsSet) throw Map::WrongIndexException("Map was not set!");
	if (heroset || !monster_position.empty()) throw AlreadyHasUnitsException("There are units on the map already!");
	else {
		map = maptoset;
		mapIsSet = true;
	}
}

void Game::putHero(Hero hero, int x, int y)
{
	if (heroset) throw AlreadyHasHeroException("There is a hero already!");
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
	std::string direction;
	std::list<std::string> inputs = { "north","south","west","east" };
	auto index = monster_position.begin();
	if (heroset && mapIsSet && !game_is_running)
	{
		game_is_running = true;
		if (hero->isAlive() && !monster_position.empty())
		{
			printMap();
			std::cout << "Choose the direction! (north/south/west/east)"<<std::endl;
			std::cin >> direction;
			if ((std::find(inputs.begin(), inputs.end(), direction)!=inputs.end()) && validateMove(direction)) {
				moveHero(direction);
			}
			while (!monster_position.empty() && index != monster_position.end())
			{
				if (index->second.first == hero_position.first && index->second.first == hero_position.second)
				{
					hero->fightTilDeath(index->first);
				}
			}
			
			
			std::cout << (hero->isAlive()? "The hero cleared the map." : "The hero died.") << std::endl;
			std::cout << hero->getName() << ": LVL" << hero->getLevel() << std::endl
				<< "     HP: " << hero->getHealthPoints() << "/" << hero->getMaxHealthPoints() << std::endl
				<< "    DMG: " <<hero->getDamage() << std::endl
				<< "    ACD: " << hero->getAttackCoolDown() << std::endl
				<< "    DEF: " << hero->getDefense() << std::endl;
	
			game_is_running=false;
		}
	}
	else if (!heroset) throw AlreadyHasHeroException("There is a hero already!");
	else if (!mapIsSet) throw Map::WrongIndexException("Map was not set!");
}







