#include "../Character.cpp"
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

/*
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
*/

/*Character tesztek alapja

TEST(Character, Character){ ??
	
}

TEST(Character, makeResults){
	
}

TEST(Character, attack){
	
}
*/


/*Refactor tesztek alapja
TEST(Monster, good_working){
	
}

TEST(parse, good_working){
	
}

TEST(getName, good_working){
	
}

TEST(getHealthPoints, good_working){
	
}

TEST(getDamage, good_working){
	
}

TEST(getAttackCoolDown, good_working){
	
}

TEST(isAlive, good_working){
	
}

TEST(hit, good_working){
	
}

TEST(makeResults, good_working){
	
}

TEST(fightTilDeath, good_working){
	
}
*/

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
