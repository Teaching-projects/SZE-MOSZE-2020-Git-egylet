#include <string>
#include <fstream>
#include <vector>
#include "Map.h"

struct coordinates {
	int x;
	int y;
	
	coordinates(int xg, int yg)
	{
		this->x = xg;
		this->y = yg;
	}
};

class MarkedMap : public Map {

public:
	MarkedMap(std::string& filename);
	
	coordinates getHeroPosition() const;
	std::vector<coordinates> getMonsterPositions(char c) const;
	
	class notExist : public std::runtime_error
    {
    public:
        explicit notExist(const std::string &content) : std::runtime_error(content) {}
    };
};
