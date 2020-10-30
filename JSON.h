#include <regex>
#include <map>
#include <iostream>
#include <fstream>
#include <any>

class JSON
{

private:
	std::map<std::string, std::any> data;

public:

    static JSON jsonParser(std::istream& file);
    static JSON jsonParser(std::string file);
    static JSON parseFromFile(std::string filename);
    static JSON parseFromString(std::string str);

	JSON(std::map<std::string, std::any> data) : data(data){};
	
	unsigned int count(const std::string &key)
    {
        return data.count(key);
    }

	
	template <typename T>
    T get(const std::string &key)
    {
        return std::any_cast<T>(data[key]);
    }
    
    class ParseException : virtual public std::runtime_error
    {
    public:
        explicit ParseException(const std::string &content) : std::runtime_error("JSON error: " + content) {}
    };
};
