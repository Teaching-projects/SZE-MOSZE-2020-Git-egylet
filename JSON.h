#include <iostream>
#include <map>
#include <regex>
#include <fstream>
#include <algorithm>
#include <variant>
#include <cctype>

class JSON
{

private:
	std::map<std::string, std::variant<std::string, int, double>> data;

public:
	JSON(std::map<std::string, std::variant<std::string, int, double>> data) : data(data){};

    static JSON jsonParser(std::istream& file);
    static JSON parseFromString(std::string str);
    static JSON parseFromFile(std::string filename);
    
    int count(std::string key){
		if (data.find(key) != data.end()) return 1; else return 0;
	}
	
	template <typename T>
    T get(const std::string& key)
    {
		if (!count(key)) throw ParseException("it does not exist");
        else return std::get<T>(data[key]);
    }
    
    class ParseException : public std::runtime_error
    {
    public:
        explicit ParseException(const std::string &content) : std::runtime_error(content) {}
    };
};
