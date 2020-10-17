#include "../JsonParser.h"
#include <gtest/gtest.h>

TEST(JsonParser, istream) {
	std::ifstream file;
	file.open("Player_1_Kakarott.json");
	
	std::map<std::string, std::string> actual = Parser::jsonParser(file);
	std::map<std::string, std::string> whichis
	{
		{"name", "Kakarott"},
		{"hp", "3000"},
		{"dmg", "400"},
		{"acd", "5.5"}
	};
	
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
	
	file.close();
}

TEST(JsonParser, string) {
	std::string filename = "Player_2_Sally.json";
	std::ifstream file;
	file.open(filename);
	std::string content, line;
	
	std::map<std::string, std::string> whichis
	{
		{"name", "Sally"},
		{"hp", "3500"},
		{"dmg", "350"},
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
	std::string filename = "Player_3_Maple.json";
	
	std::map<std::string, std::string> actual = Parser::jsonParser(filename);
	std::map<std::string, std::string> whichis
	{
		{"name", "Maple"},
		{"hp", "4000"},
		{"dmg", "300"},
		{"acd", "4.5"}
	};
	
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
}

TEST(JsonParser, errorfile) {
	std::ifstream file;
	file.open("error/Player_4_Enigma.json");
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
