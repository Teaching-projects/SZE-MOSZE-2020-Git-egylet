#include "MarkedMap.h"
#include <iostream>
#include <string>

MarkedMap::MarkedMap(
	std::string &filename
) : Map(
	filename
)
{}

coordinates MarkedMap::getHeroPosition() const {
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].length(); j++)
		{
			if (map[i][j] == 'H') return coordinates(i, j);
		}
	}
	throw notExist("it does not exist");
}

std::vector<coordinates> MarkedMap::getMonsterPositions(char c) const {
	std::vector<coordinates> toReturn;
	
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].length(); j++)
		{
			if (map[i][j] == c)
			{
				coordinates newest(i, j);
				toReturn.push_back(newest);
			}
		}
	}
	return toReturn;
}
