#include <regex>
#include <map>
#include <iostream>
#include <fstream>

class parser
{

public:

    static std::map <std::string, std::string> jsonParser(std::istream& file);
    static std::map <std::string, std::string> jsonParser(std::string file);

};
