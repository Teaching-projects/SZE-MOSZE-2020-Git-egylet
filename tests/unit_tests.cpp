#include "../Monster.h"
#include "../JSON.h"
#include <gtest/gtest.h>

//Player_1_Kakarott.json
TEST(JSON, jsonParser) {
	std::ifstream file;
	file.open("../units/Player_1_Kakarott.json");
	
    JSON values = JSON::jsonParser(file);
    file.close();
    
	ASSERT_EQ(values.get<std::string>("name"),"Kakarott");
	ASSERT_EQ(values.get<int>("health_points"),300);
	ASSERT_EQ(values.get<int>("damage"),150);
	ASSERT_EQ(values.get<double>("attack_cooldown"),5.5);
}

//Player_2_Sally.json
TEST(JSON, parseFromString) {
    std::string filename = "../units/Player_2_Sally.json";
	std::ifstream file;
	file.open(filename);
	std::string content, line;

	while (std::getline(file, line)) content += line;

	JSON values = JSON::parseFromString(content);
    
	ASSERT_EQ(values.get<std::string>("name"),"Sally");
	ASSERT_EQ(values.get<int>("health_points"),500);
	ASSERT_EQ(values.get<int>("damage"),250);
	ASSERT_EQ(values.get<double>("attack_cooldown"),3.5);
}

//Player_3_Maple.json
TEST(JSON, parseFromFile) {
    JSON values = JSON::parseFromFile("../units/Player_3_Maple.json");
    
	ASSERT_EQ(values.get<std::string>("name"),"Maple");
	ASSERT_EQ(values.get<int>("health_points"),700);
	ASSERT_EQ(values.get<int>("damage"),100);
	ASSERT_EQ(values.get<double>("attack_cooldown"),4.5);
}

//Read in Fallen.json file
TEST(JSON, Fallen) {
	std::ifstream file;
	file.open("../Fallen.json");
	
    JSON values = JSON::jsonParser(file);
    file.close();
    
    ASSERT_EQ(values.get<std::string>("name"),"Fallen");
	ASSERT_EQ(values.get<int>("health_points"),4);
	ASSERT_EQ(values.get<int>("damage"),2);
}

//mixed the lines in .json file
TEST(JSON, Mixi) {
	std::ifstream file;
	file.open("../units/not_correct_units/NCPlayer_1_Mixi.json");
	
    JSON values = JSON::jsonParser(file);
    file.close();
    
	ASSERT_EQ(values.get<std::string>("name"),"Mixi");
	ASSERT_EQ(values.get<int>("health_points"),320);
	ASSERT_EQ(values.get<int>("damage"),140);
	ASSERT_EQ(values.get<double>("attack_cooldown"),5.3);
}

//add some whitespaces in .json file
TEST(JSON, Spacy) {
	std::ifstream file;
	file.open("../units/not_correct_units/NCPlayer_2_Spacy.json");
	
    JSON values = JSON::jsonParser(file);
    file.close();
    
	ASSERT_EQ(values.get<std::string>("name"),"Spacy");
	ASSERT_EQ(values.get<int>("health_points"),400);
	ASSERT_EQ(values.get<int>("damage"),250);
	ASSERT_EQ(values.get<double>("attack_cooldown"),6.5);
}

//mixed the lines and add some whitespaces in .json file
TEST(JSON, Mixpacy) {
	std::ifstream file;
	file.open("../units/not_correct_units/NCPlayer_3_Mixpacy.json");
	
    JSON values = JSON::jsonParser(file);
    file.close();
    
    ASSERT_EQ(values.get<std::string>("name"),"Mixpacy");
	ASSERT_EQ(values.get<int>("health_points"),456);
	ASSERT_EQ(values.get<int>("damage"),259);
	ASSERT_EQ(values.get<double>("attack_cooldown"),6.9);
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

TEST(Monster, getName){
	Monster player_test("Kakarott", 300, 150, 5.5);
	std::string test_name = player_test.getName();
	std::string expected_name = "Kakarott";
	ASSERT_EQ(expected_name, test_name);
}

TEST(Monster, getHealthPoints){
	Monster player_test("Kakarott", 300, 150, 5.5);
	int test_hp = player_test.getHealthPoints();
	int expected_hp = 300;
	ASSERT_EQ(expected_hp, test_hp);
}

TEST(Monster, getDamage){
	Monster player_test("Kakarott", 300, 150, 5.5);
	int test_dmg = player_test.getDamage();
	int expected_dmg = 150;
	ASSERT_EQ(expected_dmg, test_dmg);
}

TEST(Monster, getAttackCoolDown){
	Monster player_test("Kakarott", 300, 150, 5.5);
	double test_acd = player_test.getAttackCoolDown();
	double expected_acd = 5.5;
	ASSERT_EQ(expected_acd, test_acd);
}

TEST(Monster, isAlive){
	Monster player_test("Kakarott", 300, 150, 5.5);
	bool test = player_test.isAlive();
	bool expected = true;
	ASSERT_EQ(expected, test);
}

TEST(Monster, hit){
	Monster player_test_1("Kakarott", 300, 150, 5.5);
	Monster player_test_2("Kakarott_2", 300, 150, 5.5);
	player_test_1.hit(&player_test_2);
	int test_hp = player_test_2.getHealthPoints();
	int expected_hp = 150;
	ASSERT_EQ(expected_hp, test_hp);
}

TEST(Monster, parse){
	Monster player_test = Monster::parse("../units/Player_1_Kakarott.json");
	std::string test_name = player_test.getName();
	int test_hp = player_test.getHealthPoints();
	int test_dmg = player_test.getDamage();
	double test_acd = player_test.getAttackCoolDown();
	
	std::string expected_name = "Kakarott";
	int expected_hp = 300;
	int expected_dmg = 150;
	double expected_acd = 5.5;
	
	ASSERT_EQ(expected_name, test_name);
	ASSERT_EQ(expected_hp, test_hp);
	ASSERT_EQ(expected_dmg, test_dmg);
	ASSERT_DOUBLE_EQ(expected_acd, test_acd);
}

TEST(Monster, fightTilDeath){
	Monster player_test_1("PLAYER1", 300, 100, 1.5);
	Monster player_test_2("PLAYER2", 300, 50, 2.5);
	std::string expected_winner = "Good.";
	std::string test_winner = "";
	
	player_test_1.fightTilDeath(player_test_2);
	
	if (player_test_1.isAlive() && !player_test_2.isAlive()) test_winner = "Good."; 
	else test_winner = "Bad";

	ASSERT_EQ(expected_winner, test_winner);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
