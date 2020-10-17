#include "../JsonParser.h"
#include <gtest/gtest.h>

TEST(JsonParser, istream) {
	std::ifstream file;
	file.open("unit_test_1.json");
	
	std::map<std::string, std::string> actual = Parser::jsonParser(file);
	std::map<std::string, std::string> whichis
	{
		{"name", "Kakarott"},
		{"hp", "3000"},
		{"dmg", "400"}
	};
	
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
	
	file.close();
}

TEST(JsonParser, string) {
	std::string filename = "unit_test_2.json";
	std::ifstream file;
	file.open(filename);
	std::string content, line;
	
	std::map<std::string, std::string> whichis
	{
		{"name", "Sally"},
		{"hp", "3500"},
		{"dmg", "350"}
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
	std::string filename = "unit_test_3.json";
	
	std::map<std::string, std::string> actual = Parser::jsonParser(filename);
	std::map<std::string, std::string> whichis
	{
		{"name", "Maple"},
		{"hp", "4000"},
		{"dmg", "300"}
	};
	
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
}

TEST(JsonParser, errorfile) {
	std::ifstream file;
	file.open("error/unit_test_error.json");
	std::map<std::string, std::string> actual = Parser::jsonParser(file);
	std::map<std::string, std::string> whichis
	{
		{"name", "Enigma"},
		{"hp", "3000"},
		{"dmg", "300"}
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
