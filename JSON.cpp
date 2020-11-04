/**
\mainpage Git egylet's documentation
\class JSON
This is the description of JSON.cpp
\version 1.0
\author kokohun
\date 2020/11/03 20:00
Created on: 2020/11/03 20:00
*/
#include "JSON.h"

///Getting datas from a JSON file
JSON JSON::jsonParser(std::istream& file) {
    std::string content, line; ///< Read rows from file values

    while (std::getline(file, line))
    {
        content += line;
    }

    return parseFromString(content); ///< Getting datas from strings
}

/// Getting datas from strings
JSON JSON::parseFromString(std::string str) {
    std::regex reg("\\s*\"([\\w]*)\"\\s*:\\s*\"?([\\s\\w\\.]*)\"?\\s*[,}]\\s*");
    std::map<std::string, std::string> values;
    std::smatch match;

    while(std::regex_search(str, match, reg)){
        if (match[1] == "") { ///< Wrong key
            throw ParseException("incorrect key"); 
        }

        else if (match[2] == "") { ///< Wrong value
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

/// Getting datas by filename
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
           std::map<std::string, std::string> values = jsonParser(file).data; ///< Reading file datas to values map
           file.close();
           
           return JSON(values);
        }
    }
    else return parseFromString(filename); ///< Getting datas from filenames(string)
}
