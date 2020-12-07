/**
\class Map
This is the description of Map.h
\version 1.0
\author kokohun
\date 2020/11/20 10:56
Created on: 2020/11/20 10:56
*/

#pragma once
#include <string>
#include <fstream>
#include <vector>

class Map {
	
protected:
	std::vector<std::string> map; ///< The map data array
	
public:
	Map() {}
	Map(const std::string& filename); ///< Map class constructor, which reads map from file
	
	enum type
	{
		Free, Wall /** Map field types*/
	};
	
	Map::type get(unsigned int x, unsigned int y) const; ///< Get map field type
	int horizontalget();
	int getmapsize();
	int getwidth(int y);

	///< Map class Exception function
	class WrongIndexException : public std::runtime_error
    {
    public:
        explicit WrongIndexException(const std::string &content) : std::runtime_error(content) {}
    };
};
