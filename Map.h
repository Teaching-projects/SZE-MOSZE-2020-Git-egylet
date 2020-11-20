/**
\mainpage Git egylet's documentation
\class Map
This is the description of Map.h
\version 1.0
\author kokohun
\date 2020/11/20 10:56
Created on: 2020/11/20 10:56
*/

#include <string>
#include <fstream>
#include <vector>

class Map {
	
private:
	std::vector<std::string> map; ///< The map data array
	
public:
	Map(const std::string& filename); ///< Map class constructor, which reads map from file
	
	enum type
	{
		Free, Wall /** Map field types*/
	};
	
	Map::type get(int x, int y) const; ///< Get map field type
	
	class WrongIndexException : public std::runtime_error; ///< Map class Exception function
    {
    public:
        explicit WrongIndexException(const std::string &content) : std::runtime_error(content) {}
    };
};
