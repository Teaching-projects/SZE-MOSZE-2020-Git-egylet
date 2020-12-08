#include "../../Monster.h"
#include "../../Hero.h"
#include "../../Damage.h"
#include "../../JSON.h"
#include <gtest/gtest.h>

TEST(Hero, getLevel){
	Damage tmp (3, 1);
	Hero player_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	
	int test_level = player_test.getLevel();
	
	int expected_level = 1;
	
	ASSERT_EQ(expected_level, test_level);
}

TEST(Hero, getExperience){
	Damage tmp (3, 1);
	Hero player_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	
	int test_xp = player_test.getExperience();
	
	int expected_xp = 0;
	
	ASSERT_EQ(expected_xp, test_xp);
}

TEST(Hero, getMaxHealthPoints){
	Damage tmp (3, 1);
	Hero player_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	
	int test_mhp = player_test.getMaxHealthPoints();
	
	int expected_mhp = 30;
	
	ASSERT_EQ(expected_mhp, test_mhp);
}

TEST(Hero, getLightRadius){
	Damage tmp (3, 1);
	Hero player_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	
	int test_lr = player_test.getLightRadius();
	
	int expected_lr = 2;
	
	ASSERT_EQ(expected_lr, test_lr);
}

TEST(Hero, getExperiencePerLevel){
	Damage tmp (3, 1);
	Hero player_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	
	int test_epl = player_test.getExperiencePerLevel();
	
	int expected_epl = 20;
	
	ASSERT_EQ(expected_epl, test_epl);
}

TEST(Hero, getHealthPointBonusPerLevel){
	Damage tmp (3, 1);
	Hero player_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	
	int test_hpbpl = player_test.getHealthPointBonusPerLevel();
	
	int expected_hpbpl = 5;
	
	ASSERT_EQ(expected_hpbpl, test_hpbpl);
}

TEST(Hero, getPhysicalDamageBonusPerLevel){
	Damage tmp (3, 1);
	Hero player_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	
	int test_pdbpl = player_test.getPhysicalDamageBonusPerLevel();
	
	int expected_pdbpl = 1;
	
	ASSERT_EQ(expected_pdbpl, test_pdbpl);
}

TEST(Hero, getCooldownMultiplierPerLevel){
	Damage tmp (3, 1);
	Hero player_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	
	int test_cmpl = player_test.getCooldownMultiplierPerLevel();
	
	int expected_cmpl = 0.9;
	
	ASSERT_DOUBLE_EQ(expected_cmpl, test_cmpl);
}

TEST(Hero, getDefenseBonusPerLevel){
	Damage tmp (3, 1);
	Hero player_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	
	int test_dbpl = player_test.getDefenseBonusPerLevel();
	
	int expected_dbpl = 0.1;
	
	ASSERT_DOUBLE_EQ(expected_dbpl, test_dbpl);
}

TEST(Hero, getMagicalDamageBonusPerLevel){
	Damage tmp (3, 1);
	Hero player_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	
	int test_mdbpl = player_test.getMagicalDamageBonusPerLevel();
	
	int expected_mdbpl = 1;
	
	ASSERT_EQ(expected_mdbpl, test_mdbpl);
}

TEST(Hero, getLightRadiusBonusPerLevel){
	Damage tmp (3, 1);
	Hero player_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	
	int test_lrbpl = player_test.getLightRadiusBonusPerLevel();
	
	int expected_lrbpl = 1;
	
	ASSERT_EQ(expected_lrbpl, test_lrbpl);
}

TEST(Hero, hit_wo_levelup){
	Damage tmp (3, 1);
	Hero player_test_1 ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	Monster player_test_2("Kakarott", 30, tmp, 2.5, 1);
	
	player_test_1.hit(&player_test_2);
	
	int test_hp = player_test_2.getHealthPoints();
	int test_xp = player_test_1.getExperience();

	int expected_hp = 27;
	int expected_xp = 3;

	ASSERT_EQ(expected_hp, test_hp);
	ASSERT_EQ(expected_xp, test_xp);
}

TEST(Hero, hit_w_levelup){
	Damage tmp (3, 1);
	Hero hero_test ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 2, 5, 1, 0.9, 0.1, 1, 1);
	Monster monster_test ("Kakarott", 30, tmp, 2.5, 1);
	
	hero_test.hit(&monster_test);
	
	Damage test_dmg (hero_test.getDamage());
	
	int test_monster_hp = monster_test.getHealthPoints();
	int test_hero_level = hero_test.getLevel();
	int test_hero_mhp = hero_test.getMaxHealthPoints();
	int test_hero_pdmg = test_dmg.getPhysical();
	int test_hero_mdmg = test_dmg.getMagical();
	int test_hero_hp = hero_test.getHealthPoints();
	double test_hero_acd = hero_test.getAttackCoolDown();
	double test_hero_def = hero_test.getDefense();
	int test_hero_xp = hero_test.getExperience();
	int test_lr = hero_test.getLightRadius();

	int expected_monster_hp = 27;
	int expected_hero_level = 2;
	int expected_hero_mhp = 35;
	int expected_hero_pdmg = 4;
	int expected_hero_mdmg = 2;
	int expected_hero_hp = 35;
	double expected_hero_acd = 1.1*0.9;
	double expected_hero_def = 0.6;
	int expected_hero_xp = 1;
	int expected_lr = 3;

	ASSERT_EQ(expected_monster_hp, test_monster_hp);
	ASSERT_EQ(expected_hero_level, test_hero_level);
	ASSERT_EQ(expected_hero_mhp, test_hero_mhp);
	ASSERT_EQ(expected_hero_pdmg, test_hero_pdmg);
	ASSERT_EQ(expected_hero_mdmg, test_hero_mdmg);
	ASSERT_EQ(expected_hero_acd, test_hero_acd);
	ASSERT_EQ(expected_hero_def, test_hero_def);
	ASSERT_EQ(expected_hero_xp, test_hero_xp);
	ASSERT_EQ(expected_lr, test_lr);
}

TEST(Hero, getHit){
	Damage tmp (3, 1);
	Hero player_test_1 ("Prince Aidan of Khanduras", 30, tmp, 1.1, 0.5, 2, 20, 5, 1, 0.9, 0.1, 1, 1);
	Monster player_test_2("Kakarott", 30, tmp, 2.5, 1);
	
	player_test_2.getHit(&player_test_2);
	
	int test_hp = player_test_2.getHealthPoints();
	
	int expected_hp = 27;
	
	ASSERT_EQ(expected_hp, test_hp);
}

TEST(Hero, parse){
	Hero player_test = Hero::parse("../../Dark_Wanderer.json");
	
	std::string test_name = player_test.getName();
	int test_hp = player_test.getHealthPoints();
	Damage test_dmg = player_test.getDamage();
	int test_pdmg = test_dmg.getPhysical();
	int test_mdmg = test_dmg.getMagical();
	double test_acd = player_test.getAttackCoolDown();
	double test_def = player_test.getDefense();
	int test_epl = player_test.getExperiencePerLevel();;
	int test_hpbpl = player_test.getHealthPointBonusPerLevel();;
	int test_pdbpl = player_test.getPhysicalDamageBonusPerLevel();;
	double test_cmpl = player_test.getCooldownMultiplierPerLevel();
	double test_dbpl = player_test.getDefenseBonusPerLevel();;
	int test_mdbpl = player_test.getMagicalDamageBonusPerLevel();;
	
	std::string expected_name = "Prince Aidan of Khanduras";
	int expected_hp = 30;
	int expected_pdmg = 3;
	int expected_mdmg = 1;
	double expected_acd = 1.1;
	double expected_def = 0.5;
	int expected_epl = 20;
	int expected_hpbpl = 5;
	int expected_pdbpl = 1;
	double expected_cmpl = 0.9;
	double expected_dbpl = 0.1;
	int expected_mdbpl = 1;

	ASSERT_EQ(expected_name, test_name);
	ASSERT_EQ(expected_hp, test_hp);
	ASSERT_EQ(expected_pdmg, test_pdmg);
	ASSERT_EQ(expected_mdmg, test_mdmg);
	ASSERT_DOUBLE_EQ(expected_acd, test_acd);
	ASSERT_DOUBLE_EQ(expected_def, test_def);
	ASSERT_EQ(expected_epl, test_epl);
	ASSERT_EQ(expected_hpbpl, test_hpbpl);
	ASSERT_EQ(expected_pdbpl, test_pdbpl);
	ASSERT_DOUBLE_EQ(expected_cmpl, test_cmpl);
	ASSERT_DOUBLE_EQ(expected_dbpl, test_dbpl);
	ASSERT_EQ(expected_mdbpl, test_mdbpl);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
