#include <map>
#include <regex>
#include <iostream>
#include <fstream>
#include <variant>
#include <cctype>
#include <algorithm>
#include <list>
#include <type_traits>

class JSON
{

private:
	std::map <std::string, std::variant<std::string, int, double>> pdata;
	
public:
	typedef std::list<std::variant<std::string, int, double>> list;

	JSON(std::map<std::string, std::variant<std::string, int, double>> data) : pdata(data){};
	
    static JSON jsonParser(std::istream& file);
    static JSON parseFromString(std::string str);
    static JSON parseFromFile(std::string filename);
    
    int count(std::string key){
		if (pdata.find(key) != pdata.end()) return 1; else return 0;
	}
	
	template <typename T>
	inline typename std::enable_if<std::is_same<T, JSON::list>::value, T>::type
    get(const std::string& key)
    {
		if (!count(key)) throw ParseException("it does not exist");
        else
        {
			list returns;
			std::istringstream values(std::get<std::string>(pdata[key]));
			std::copy(std::istream_iterator<std::string>(values),
			std::istream_iterator<std::string>(),
			std::back_inserter(returns));

			return returns;
			
		}
    }
    
    template <typename T> inline typename std::enable_if<!std::is_same<T, JSON::list>::value, T>::type
	get(const std::string& key)
	{
       	if (!count(key)) throw ParseException("it does not exist");
        else return std::get<T>(pdata[key]);
    }
    
    class ParseException : public std::runtime_error
    {
    public:
        explicit ParseException(const std::string &content) : std::runtime_error(content) {}
    };
};
