#include "JSON.h"

JSON JSON::jsonParser(std::istream& file) {
    std::string content, line;

    while (std::getline(file, line))
    {
        content += line;
    }

    return parseFromString(content);
}

JSON JSON::parseFromString(std::string str) {
    std::regex reg("\\s*\"([\\w]*)\"\\s*:\\s*\"?([\\s\\w\\.]*)\"?\\s*[,}]\\s*");
    std::map<std::string, std::string> values;
    std::smatch match;

    while(std::regex_search(str, match, reg)){
        if (match[1] == "") {
            throw ParseException("incorrect key"); 
        }

        else if (match[2] == "") {
            throw ParseException("incorrect value"); 
        }

        else
        {
            values[match[1]] = match[2];
            str = match.suffix().str();
        }            
    }
    return JSON(values);
}

JSON JSON::parseFromFile(std::string filename) {
	std::smatch match;
	std::ifstream file;
    file.open(filename);

    std::regex freg("([\\w]*).json$");
    if (std::regex_search(filename, match, freg))
    {
        
        if (file.fail()) throw ParseException("it does not exist");
        else
        {
           std::map<std::string, std::string> values = jsonParser(file).data;
           file.close();
           
           return JSON(values);
        }
    }
    else return parseFromString(filename);
}
