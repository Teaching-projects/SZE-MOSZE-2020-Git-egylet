#include "Map.h"
#include <fstream>

Map::Map(const std::string& filename) {
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

Map::type Map::get(unsigned int x, unsigned int y) const {
	if (y >= map.size()) throw WrongIndexException("y coordinate is out of range");
	if (x >= map[y].length()) throw WrongIndexException("x coorfinate is out of range");

	else return type(map[x][y]);
}

int Map::horizontalget()
{
	 int length = 0;
	for ( int i = 0; i < (int)map.size(); i++)
	{
		if ((int)map[i].length() > length)
		{
			length = (int)map[i].length();
		}
	}
	return length;
}

int Map::getmapsize()
{
	return map.size();
}

int Map::getwidth(int i)
{
	return map[i].length();
}