#include "../../JSON.h"
#include <gtest/gtest.h>

//Read in Player_1_Kakarott.json file
TEST(JSON, jsonParser) {
	std::ifstream file;
	file.open("../../units/Player_1_Kakarott.json");
	
    JSON values = JSON::jsonParser(file);
    file.close();
    
	ASSERT_EQ(values.get<std::string>("name"),"Kakarott");
	ASSERT_EQ(values.get<int>("health_points"),300);
	ASSERT_EQ(values.get<int>("damage"),150);
	ASSERT_EQ(values.get<int>("magical-damage"),40);
	ASSERT_EQ(values.get<double>("attack_cooldown"),5.5);
	ASSERT_EQ(values.get<double>("defense"),240.0);
}

//Read in Player_2_Sally.json file
TEST(JSON, parseFromString) {
    std::string filename = "../../units/Player_2_Sally.json";
	std::ifstream file;
	file.open(filename);
	std::string content, line;

	while (std::getline(file, line)) content += line;

	JSON values = JSON::parseFromString(content);
    
	ASSERT_EQ(values.get<std::string>("name"),"Sally");
	ASSERT_EQ(values.get<int>("health_points"),500);
	ASSERT_EQ(values.get<int>("damage"),250);
	ASSERT_EQ(values.get<int>("magical-damage"),25);
	ASSERT_EQ(values.get<double>("attack_cooldown"),3.5);
	ASSERT_EQ(values.get<double>("defense"),180.0);
}

//Read in Player_3_Maple.json file
TEST(JSON, parseFromFile) {
    JSON values = JSON::parseFromFile("../../units/Player_3_Maple.json");
    
	ASSERT_EQ(values.get<std::string>("name"),"Maple");
	ASSERT_EQ(values.get<int>("health_points"),700);
	ASSERT_EQ(values.get<int>("damage"),100);
	ASSERT_EQ(values.get<int>("magical-damage"),20);
	ASSERT_EQ(values.get<double>("attack_cooldown"),4.5);
	ASSERT_EQ(values.get<double>("defense"),120.0);
}

//Read in Fallen.json file
TEST(JSON, Fallen) {
	std::ifstream file;
	file.open("../../Fallen.json");
	
    JSON values = JSON::jsonParser(file);
    file.close();
    
    ASSERT_EQ(values.get<std::string>("name"),"Fallen");
	ASSERT_EQ(values.get<int>("health_points"),4);
	ASSERT_EQ(values.get<int>("damage"),2);
	ASSERT_EQ(values.get<int>("magical-damage"),1);
	ASSERT_EQ(values.get<double>("attack_cooldown"),1.6);
	ASSERT_EQ(values.get<double>("defense"),1.1);
}

//Read in NCPlayer_1_Mixi.json file
TEST(JSON, Mixi) {
	std::ifstream file;
	file.open("../../units/not_correct_units/NCPlayer_1_Mixi.json");
	
    JSON values = JSON::jsonParser(file);
    file.close();
    
	ASSERT_EQ(values.get<std::string>("name"),"Mixi");
	ASSERT_EQ(values.get<int>("health_points"),320);
	ASSERT_EQ(values.get<int>("damage"),140);
	ASSERT_EQ(values.get<int>("magical-damage"),100);
	ASSERT_EQ(values.get<double>("attack_cooldown"),5.3);
	ASSERT_EQ(values.get<double>("defense"),280.0);
}

//Read in NCPlayer_2_Spacy.json file
TEST(JSON, Spacy) {
	std::ifstream file;
	file.open("../../units/not_correct_units/NCPlayer_2_Spacy.json");
	
    JSON values = JSON::jsonParser(file);
    file.close();
    
	ASSERT_EQ(values.get<std::string>("name"),"Spacy");
	ASSERT_EQ(values.get<int>("health_points"),400);
	ASSERT_EQ(values.get<int>("damage"),250);
	ASSERT_EQ(values.get<int>("magical-damage"),30);
	ASSERT_EQ(values.get<double>("attack_cooldown"),6.5);
	ASSERT_EQ(values.get<double>("defense"),100.0);
}

//Read in NCPlayer_3_Mixpacy.json file
TEST(JSON, Mixpacy) {
	std::ifstream file;
	file.open("../../units/not_correct_units/NCPlayer_3_Mixpacy.json");
	
    JSON values = JSON::jsonParser(file);
    file.close();
    
    ASSERT_EQ(values.get<std::string>("name"),"Mixpacy");
	ASSERT_EQ(values.get<int>("health_points"),456);
	ASSERT_EQ(values.get<int>("damage"),259);
	ASSERT_EQ(values.get<int>("magical-damage"),69);
	ASSERT_EQ(values.get<double>("attack_cooldown"),6.9);
	ASSERT_EQ(values.get<double>("defense"),233.0);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
