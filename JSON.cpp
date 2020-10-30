#include "JSON.h"

JSON JSON::jsonParser(std::istream& file) {
    std::string content, line;

    while (std::getline(file, line))
    {
        content += line;
    }

    return jsonParser(content);
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
	return values;
}

JSON JSON::parseFromFile(std::string filename) {
	std::ifstream file;
	file.open(filename);

    if (file.fail()) throw "it does not exist";
    else
    {
        JSON values = jsonParser(file);
        file.close();

        return values;
    }
    
}

JSON JSON::jsonParser(std::string fileNameOrString) {
    std::regex freg("([\\w]*).json$");
    std::smatch match;

    if (!std::regex_search(fileNameOrString, match, freg)) return parseFromString(fileNameOrString);
    else return parseFromFile(fileNameOrString);
}
