#include "../JsonParser.h"
#include <gtest/gtest.h>

TEST(JsonParser, istream) {
	std::ifstream file;
	file.open("../units/Player_1_Kakarott.json");
	
	std::map<std::string, std::string> actual = Parser::jsonParser(file);
	std::map<std::string, std::string> whichis
	{
		{"name", "Kakarott"},
		{"hp", "300"},
		{"dmg", "150"},
		{"acd", "5.5"}
	};
	
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
	
	file.close();
}

TEST(JsonParser, string) {
	std::string filename = "../units/Player_2_Sally.json";
	std::ifstream file;
	file.open(filename);
	std::string content, line;
	
	std::map<std::string, std::string> whichis
	{
		{"name", "Sally"},
		{"hp", "500"},
		{"dmg", "250"},
		{"acd", "3.5"}
	};
	
	while (std::getline(file, line))
	{
		content += line;
	}
	
	std::map<std::string, std::string> actual = Parser::jsonParser(content);
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
}


TEST(JsonParser, filename) {
	std::string filename = "../units/Player_3_Maple.json";
	
	std::map<std::string, std::string> actual = Parser::jsonParser(filename);
	std::map<std::string, std::string> whichis
	{
		{"name", "Maple"},
		{"hp", "700"},
		{"dmg", "100"},
		{"acd", "4.5"}
	};
	
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
}

TEST(JsonParser, errorfile) {
	std::ifstream file;
	file.open("../units/error/Player_4_Enigma.json");
	std::map<std::string, std::string> actual = Parser::jsonParser(file);
	std::map<std::string, std::string> whichis
	{
		{"name", "Enigma"},
		{"hp", "3000"},
		{"dmg", "300"},
		{"acd", "5.0"}
	};
	
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
	
	file.close();
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
