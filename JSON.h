#include <regex>
#include <map>
#include <iostream>
/**
\mainpage Git egylet's documentation
\class JSON
This is the description of JSON.h
\version 1.0
\author kokohun
\date 2020/11/03 21:00
Created on: 2020/11/03 21:00
*/

#include <fstream>
#include <any>

class JSON
{

private:
	std::map<std::string, std::string> data; ///< Create a data map with string type

public:
	JSON(std::map<std::string, std::string> data) : data(data){}; ///< Load data map in JSON class

    static JSON jsonParser(std::istream& file); ///< Getting datas from a JSON file
    static JSON parseFromString(std::string str); ///< Getting datas from string
    static JSON parseFromFile(std::string filename); ///< Getting datas by filename(string type)
    
    int count(std::string key){ ///< Checking a given input is a number or not 
		if (data.find(key) != data.end()) return 1; else return 0;
	}
	
	template <typename T>
    T get(const std::string &key)
    {
        return data[key];
    }
    
    class ParseException : public std::runtime_error ///<< Parse Excepction is a tool for debugging
    {
    public:
        explicit ParseException(const std::string &content) : std::runtime_error(content) {}
    };
};
