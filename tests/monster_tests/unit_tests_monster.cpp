#include "../../Monster.h"
#include "../../Damage.h"
#include "../../JSON.h"
#include <gtest/gtest.h>

TEST(Monster, getName){
	Damage tmp (150, 40);
	Monster player_test ("Kakarott", 300, tmp, 5.5, 240);
	
	std::string test_name = player_test.getName();
	
	std::string expected_name = "Kakarott";
	
	ASSERT_EQ(expected_name, test_name);
}

TEST(Monster, getHealthPoints){
	Damage tmp (150, 40);
	Monster player_test ("Kakarott", 300, tmp, 5.5, 240);
	
	int test_hp = player_test.getHealthPoints();
	
	int expected_hp = 300;
	
	ASSERT_EQ(expected_hp, test_hp);
}

TEST(Monster, getDamage){
	Damage tmp (150, 40);
	Monster player_test ("Kakarott", 300, tmp, 5.5, 240);
	Damage test_dmg (player_test.getDamage());

	int test_pdmg = test_dmg.getPhysical();
	int test_mdmg = test_dmg.getMagical();

	int expected_pdmg = 150;
	int expected_mdmg = 40;

	ASSERT_EQ(expected_pdmg, test_pdmg);
	ASSERT_EQ(expected_mdmg, test_mdmg);
}

TEST(Monster, getAttackCoolDown){
	Damage tmp (150, 40);
	Monster player_test ("Kakarott", 300, tmp, 5.5, 240);
	
	double test_acd = player_test.getAttackCoolDown();
	
	double expected_acd = 5.5;
	
	ASSERT_EQ(expected_acd, test_acd);
}

TEST(Monster, getDefense){
	Damage tmp (150, 40);
	Monster player_test ("Kakarott", 300, tmp, 5.5, 240);
	
	double test_def = player_test.getDefense();
	
	double expected_def = 240;
	
	ASSERT_EQ(expected_def, test_def);
}

TEST(Monster, isAlive){
	Damage tmp (150, 40);
	Monster player_test ("Kakarott", 300, tmp, 5.5, 240);
	
	bool test = player_test.isAlive();
	
	bool expected = true;
	
	ASSERT_EQ(expected, test);
}

TEST(Monster, hit){
	Damage tmp_1 (150, 40);
	Monster player_test_1 ("Kakarott", 300, tmp_1, 5.5, 240);
	Damage tmp_2 (150, 40);
	Monster player_test_2("Kakarott", 300, tmp_2, 5.5, 120);
	
	player_test_1.hit(&player_test_2);
	
	int test_hp = player_test_2.getHealthPoints();
	
	int expected_hp = 230;
	
	ASSERT_EQ(expected_hp, test_hp);
}

TEST(Monster, getHit){
	Damage tmp_1 (150, 40);
	Monster player_test_1 ("Kakarott", 300, tmp_1, 5.5, 240);
	Damage tmp_2 (150, 40);
	Monster player_test_2("Kakarott", 300, tmp_2, 5.5, 120);
	
	player_test_2.getHit(&player_test_2);
	
	int test_hp = player_test_2.getHealthPoints();
	
	int expected_hp = 230;
	
	ASSERT_EQ(expected_hp, test_hp);
}

TEST(Monster, parse){
	Monster player_test = Monster::parse("../../units/Player_1_Kakarott.json");
	
	std::string test_name = player_test.getName();
	int test_hp = player_test.getHealthPoints();
	Damage test_dmg = player_test.getDamage();
	int test_pdmg = test_dmg.getPhysical();
	int test_mdmg = test_dmg.getMagical();
	double test_acd = player_test.getAttackCoolDown();
	double test_def = player_test.getDefense();
	
	std::string expected_name = "Kakarott";
	int expected_hp = 300;
	int expected_pdmg = 150;
	int expected_mdmg = 40;
	double expected_acd = 5.5;
	double expected_def = 240.0;
	
	ASSERT_EQ(expected_name, test_name);
	ASSERT_EQ(expected_hp, test_hp);
	ASSERT_EQ(expected_pdmg, test_pdmg);
	ASSERT_EQ(expected_mdmg, test_mdmg);
	ASSERT_DOUBLE_EQ(expected_acd, test_acd);
	ASSERT_DOUBLE_EQ(expected_def, test_def);
}

TEST(Monster, fightTilDeath){
	Damage tmp_1 (150, 40);
	Monster player_test_1 ("Kakarott", 300, tmp_1, 5.5, 240);
	Damage tmp_2 (50, 10);
	Monster player_test_2("Kakarott", 300, tmp_2, 2.5, 120);
	
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