#include "../Character.h"
#include "../JsonParser.h"
#include <gtest/gtest.h>

//Json file beolasasa file alapjan
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

//Json file beolasasa string alapjan
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

//Json file beolasasa fajlnev alapjan
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

//add some whitespaces in .json file
TEST(JsonParser, Spacy) {
	std::ifstream file;
	file.open("../units/not_correct_units/Player_2_Spacy.json");
	
	std::map<std::string, std::string> actual = Parser::jsonParser(file);
	std::map<std::string, std::string> whichis
	{
		{"name", "Spacy"},
		{"hp", "400"},
		{"dmg", "250"},
		{"acd", "6.5"}
	};
	
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
	
	file.close();
}

//mixed the lines in .json file
TEST(JsonParser, Mixi) {
	std::ifstream file;
	file.open("../units/not_correct_units/NCPlayer_1_Mixi.json");
	
	std::map<std::string, std::string> actual = Parser::jsonParser(file);
	std::map<std::string, std::string> whichis
	{
		{"name", "Mixi"},
		{"hp", "320"},
		{"dmg", "140"},
		{"acd", "5.3"}
	};
	
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
	
	file.close();
}

//mixed the lines and add some whitespaces in .json file
TEST(JsonParser, Mixpacy) {
	std::ifstream file;
	file.open("../units/not_correct_units/NCPlayer_3_Mixpacy.json");
	
	std::map<std::string, std::string> actual = Parser::jsonParser(file);
	std::map<std::string, std::string> whichis
	{
		{"name", "Mixpacy"},
		{"hp", "456"},
		{"dmg", "259"},
		{"acd", "6.9"}
	};
	
	for (auto entry : actual)
	{
		ASSERT_EQ(whichis[entry.first], entry.second);
	}
	
	file.close();
}

/* Direkt rossz test, a workflow rosszul fut le tole

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
*/

TEST(Character, getName){
	Character player_test("Kakarott", 300, 150, 5.5);
	std::string test_name = player_test.getName();
	std::string expected_name = "Kakarott";
	ASSERT_EQ(expected_name, test_name);
}

TEST(Character, getHP){
	Character player_test("Kakarott", 300, 150, 5.5);
	int test_hp = player_test.getHP();
	int expected_hp = 300;
	ASSERT_EQ(expected_hp, test_hp);
}

TEST(Character, getDMG){
	Character player_test("Kakarott", 300, 150, 5.5);
	int test_dmg = player_test.getDMG();
	int expected_dmg = 150;
	ASSERT_EQ(expected_dmg, test_dmg);
}

TEST(Character, getACD){
	Character player_test("Kakarott", 300, 150, 5.5);
	double test_acd = player_test.getACD();
	double expected_acd = 5.5;
	ASSERT_EQ(expected_acd, test_acd);
}

TEST(Character, isAlive){
	Character player_test("Kakarott", 300, 150, 5.5);
	bool test = player_test.isAlive();
	bool expected = true;
	ASSERT_EQ(expected, test);
}

TEST(Character, hit){
	Character player_test_1("Kakarott", 300, 150, 5.5);
	Character player_test_2("Kakarott_2", 300, 150, 5.5);
	player_test_1.hit(player_test_2);
	int test_hp = player_test_2.getHP();
	int expected_hp = 150;
	ASSERT_EQ(expected_hp, test_hp);
}

TEST(Character, parseUnit){
	Character player_test = Character::parseUnit("../units/Player_1_Kakarott.json");
	std::string test_name = player_test.getName();
	int test_hp = player_test.getHP();
	int test_dmg = player_test.getDMG();
	double test_acd = player_test.getACD();
	
	std::string expected_name = "Kakarott";
	int expected_hp = 300;
	int expected_dmg = 150;
	double expected_acd = 5.5;
	
	ASSERT_EQ(expected_name, test_name);
	ASSERT_EQ(expected_hp, test_hp);
	ASSERT_EQ(expected_dmg, test_dmg);
	ASSERT_DOUBLE_EQ(expected_acd, test_acd);
}

TEST(Character, attack){
	Character player_test_1("PLAYER1", 300, 100, 1.5);
	Character player_test_2("PLAYER2", 300, 50, 2.5);
	std::string test_winner = player_test_1.attack(player_test_1, player_test_2);
	std::string expected_winner = "PLAYER1 wins. Remaining HP: 200.";
	ASSERT_EQ(expected_winner, test_winner);
}

TEST(Character, makeResults){
	Character player_test("TESTPLAYER", 300, 150, 5.5);
	std::string test_results = player_test.makeResults(player_test);
	std::string expected_results = "TESTPLAYER wins. Remaining HP: 300.";
	ASSERT_EQ(expected_results, test_results);
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
