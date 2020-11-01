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
    std::regex reg("\\s*\"([\\w]*)\"\\s*:\\s*\"?([\\w\\.]*)\"?\\s*[,}]\\s*");
    std::map<std::string, std::any> values;
    std::smatch match;

	while (std::regex_search(str, match, reg))
	{
		values[match[1]] = match[2];
		str = match.suffix().str();
	}
	return JSON(values);
}

JSON JSON::parseFromFile(std::string filename) {
	std::ifstream file;
	file.open(filename);

    if (file.fail()) throw "it does not exist";
    else
    {
        std::map<std::string, std::any> values = jsonParser(file).data;
        
        file.close();

        return JSON(values);
    }
}

JSON JSON::jsonParser(std::string fileNameOrString) {
    std::regex freg("([\\w]*).json$");
    std::smatch match;

    if (!std::regex_search(fileNameOrString, match, freg)) return parseFromString(fileNameOrString);
    else return parseFromFile(fileNameOrString);
}

int JSON::count(std::string key){
    if (data.find(key) != data.end()) return 1; else return 0;
}
