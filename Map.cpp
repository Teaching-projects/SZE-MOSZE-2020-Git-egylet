#include "Map.h"
#include <fstream>

Map::Map (std::string& filename) {
	std::ifstream file;
	if (!file.fail()) 
	{
		std::string line;
		while(getline(file, line)) 
		{
			map.push_back(line);
		}
	}
	else throw WrongIndexException("it does not exist");
	
	file.close();
}

Map::type Map::get(int x, int y) const {
	if (y >= map.size() || y < 0) throw WrongIndexException("y coordinate is out of range");
	if (x >= map[y].length() || x < 0) throw WrongIndexException("x coorfinate is out of range");

	if (map[y][x] == ' ') return Map::type::Free;
	else return Map::type::Wall;
}
