#include <string>
#include <fstream>
#include <vector>

class Map {
	
private:
	std::vector<std::string> map;
	
public:
	Map(std::string& filename);
	
	enum type
	{
		Free, Wall
	};
	
	Map::type get(int x, int y) const;
	
	class WrongIndexException : public std::runtime_error
    {
    public:
        explicit WrongIndexException(const std::string &content) : std::runtime_error(content) {}
    };
};
