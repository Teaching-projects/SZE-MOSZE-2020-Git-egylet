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

	if (str.substr(0,1) != "{"){
        throw ParseException("{ missing"); 
    }
    else if (str.substr(str.size()-1, 1) != "}"){
        throw ParseException("} missing"); 
    }

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


	//~ while (std::regex_search(str, match, reg))
	//~ {
		//~ values[match[1]] = match[2];
		//~ str = match.suffix().str();
	//~ }
	//~ return JSON(values);
}

JSON JSON::parseFromFile(std::string filename) {
	std::ifstream file;
	file.open(filename);

    if (file.fail()) throw "it does not exist";
    else
    {
        std::map<std::string, std::string> values = jsonParser(file).data;
        
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
