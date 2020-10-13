#include "../JsonParser.h"
#include <gtest/gtest.h>

TEST(JsonParser, istream) {
	Parser parser;
	std::ifstream file;
	file.open("unit_test_1.json");
	
	std::map<std::string, std::string> actual = parser.jsonParser(file);
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
	Parser parser;
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
	
	std::map<std::string, std::string> actual = parser.jsonParser(content);
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
}


TEST(JsonParser, filename) {
	Parser parser;
	std::string filename = "unit_test_3.json";
	
	std::map<std::string, std::string> actual = parser.jsonParser(filename);
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

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
