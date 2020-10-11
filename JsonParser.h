#include <regex>
#include <map>
#include <iostream>
#include <fstream>

class parser
{

public:

    std::map <std::string, std::string> jsonParser(std::istream& file);
    std::map <std::string, std::string> jsonParser(std::string file);

};