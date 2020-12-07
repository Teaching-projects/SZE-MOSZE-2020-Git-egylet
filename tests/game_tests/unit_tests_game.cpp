#include "../../JSON.h"
#include "../../Map.h"
#include "../../Damage.h"
#include "../../Monster.h"
#include "../../Hero.h"
#include "../../Game.h"
#include <gtest/gtest.h>

//Game setMap
TEST(Game, setMap){
    //Game game = Game("../../maps/level1.txt");
	//Game game_test;

    Hero hero{Hero::parse("../../Dark_Wanderer.json")};
        std::list<Monster> monsters;
        monsters.push_back(Monster::parse("../../Fallen.json"));
        monsters.push_back(Monster::parse("../../Fallen.json"));

    Game game("../../maps/level1.txt");

	//Map map_test = game_test.getMap();
    Map map_test("../../maps/level1.txt");

	for (int i = 1; i <= 7; i++) {
		std::string test_line = map_test.getMapLine(i);
		std::string expected_line;
		switch(i) {
			case 1:
				expected_line = "##############";
				break;
			case 2:
				expected_line = "#   #  ####  #";
				break;
			case 3:
				expected_line = "# ####  ##  #";
				break;
			case 4:
				expected_line = "#   #  ##  #";
				break;
			case 5:
				expected_line = "### # ##  #";
				break;
			case 6:
				expected_line = "#        #";
				break;
			case 7:
				expected_line = "#########";
				break;
		}
		ASSERT_EQ(expected_line, test_line);
	}
}

//Game putHero


//Game putMonster


//Game moveHero


//Game validateMove

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
