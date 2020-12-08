#include "../../Damage.h"
#include <gtest/gtest.h>


//Damage + operator
TEST(Damage, operatorPlus){
	Damage tmp_1 (10, 20);
	Damage tmp_2 (100, 200);
	Damage test_dmg = tmp_1 + tmp_2;

	int test_pdmg = test_dmg.getPhysical();
	int test_mdmg = test_dmg.getMagical();

	int expected_pdmg = 110;
	int expected_mdmg = 220;

	ASSERT_EQ(expected_pdmg, test_pdmg);
	ASSERT_EQ(expected_mdmg, test_mdmg);
}

//Damage += operator
TEST(Damage, operatorPlusEqual){
	Damage test_dmg (100, 200);
	Damage plus (10, 20);
	
	test_dmg += plus;
	
	int test_pdmg = test_dmg.getPhysical();
	int test_mdmg = test_dmg.getMagical();

	int expected_pdmg = 110;
	int expected_mdmg = 220;

	ASSERT_EQ(expected_pdmg, test_pdmg);
	ASSERT_EQ(expected_mdmg, test_mdmg);
}

//Damage *= operator
TEST(Damage, operatorMultiEqual){
	Damage test_dmg (10, 20);
	Damage multi (1, 2);
	
	test_dmg *= multi;
	
	int test_pdmg = test_dmg.getPhysical();
	int test_mdmg = test_dmg.getMagical();

	int expected_pdmg = 10;
	int expected_mdmg = 40;

	ASSERT_EQ(expected_pdmg, test_pdmg);
	ASSERT_EQ(expected_mdmg, test_mdmg);
}

TEST(Damage, getPhysical){
	Damage test_dmg (10, 20);
	
	int test_pdmg = test_dmg.getPhysical();

	int expected_pdmg = 10;

	ASSERT_EQ(expected_pdmg, test_pdmg);
}

TEST(Damage, getMagical){
	Damage test_dmg (10, 20);
	
	int test_mdmg = test_dmg.getMagical();

	int expected_mdmg = 20;

	ASSERT_EQ(expected_mdmg, test_mdmg);
}

TEST(Damage, setPhysical){
	Damage test_dmg (0, 0);
	
	test_dmg.setPhysical(10);
	
	int test_pdmg = test_dmg.getPhysical();

	int expected_pdmg = 10;

	ASSERT_EQ(expected_pdmg, test_pdmg);
}

TEST(Damage, setMagical){
	Damage test_dmg (0, 0);
	
	test_dmg.setMagical(20);
	
	int test_mdmg = test_dmg.getMagical();

	int expected_mdmg = 20;

	ASSERT_EQ(expected_mdmg, test_mdmg);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
