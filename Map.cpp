/**
\mainpage Git egylet's documentation
\class Map
This is the description of Map.cpp
\version 1.0
\author kokohun
\date 2020/11/20 11:11
Created on: 2020/11/20 11:11
*/

#include "Map.h"
#include <fstream>

Map::Map(const std::string& filename) ///< Reads map from file {
	std::ifstream file(filename);
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

Map::type Map::get(int x, int y) const ///< Get map field type {
	if (y >= map.size() || y < 0) throw WrongIndexException("y coordinate is out of range");
	if (x >= map[y].length() || x < 0) throw WrongIndexException("x coorfinate is out of range");

	if (map[y][x] == ' ') return Map::type::Free;
	else return Map::type::Wall;
}
