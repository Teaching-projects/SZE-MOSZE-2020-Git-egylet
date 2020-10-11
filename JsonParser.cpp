#include "JsonParser.h"

std::map <std::string, std::string> parser::jsonParser(std::istream& file) {
    std::string content, line;

    while (std::getline(file, line))
    {
        content += line;
    }

    return jsonParser(content);
}

std::map <std::string, std::string> parser::jsonParser(std::string str) {
    std::regex reg("\\s*\"([\\w]*)\"\\s*:\\s*\"?([\\w\\.]*)\"?\\s*[,}]\\s*");
    std::regex freg("([\\w]*).json$");
    std::map<std::string, std::string> values;
    std::smatch match;

    if (!std::regex_search(str, match, freg))
    {
        while (std::regex_search(str, match, reg))
        {
            values[match[1]] = match[2];
            str = match.suffix().str();
        }
        return values;
    }
    else
    {
        std::ifstream file;
        file.open(str);

        if (!file.fail()) 
        {
            values = jsonParser(file);
            return values;
            file.close();
        }
        else throw "it does not exist";
    }
}