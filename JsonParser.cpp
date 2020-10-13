#include "JsonParser.h"

std::map <std::string, std::string> Parser::jsonParser(std::istream& file) {
    std::string content, line;

    while (std::getline(file, line))
    {
        content += line;
    }

    return jsonParser(content);
}

std::map <std::string, std::string> Parser::jsonParserString(std::string str) {
    std::regex reg("\\s*\"([\\w]*)\"\\s*:\\s*\"?([\\w\\.]*)\"?\\s*[,}]\\s*");
    std::map<std::string, std::string> values;
    std::smatch match;

	while (std::regex_search(str, match, reg))
	{
		values[match[1]] = match[2];
		str = match.suffix().str();
	}
	return values;
}

std::map <std::string, std::string> Parser::jsonParserFileName(std::string filename) {
	std::ifstream file;
	file.open(filename);

	if (!file.fail()) 
	{
		std::map <std::string, std::string> values = jsonParser(file);
		return values;
		
		file.close();
	}
	else throw "it does not exist";
}

std::map <std::string, std::string> Parser::jsonParser(std::string fileNameOrString) {
    std::regex freg("([\\w]*).json$");
    std::smatch match;

    if (!std::regex_search(fileNameOrString, match, freg)) return jsonParserString(fileNameOrString);
    else return jsonParserFileName(fileNameOrString);
}
