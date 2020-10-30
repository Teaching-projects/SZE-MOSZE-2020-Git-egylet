#include <regex>
#include <map>
#include <iostream>
#include <fstream>

class Parser
{

public:

    static std::map <std::string, std::string> jsonParser(std::istream& file);
    static std::map <std::string, std::string> jsonParser(std::string file);
    static std::map <std::string, std::string> jsonParserFileName(std::string filename);
    static std::map <std::string, std::string> jsonParserString(std::string str);


};
