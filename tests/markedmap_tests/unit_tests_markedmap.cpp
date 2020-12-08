#include "../../MarkedMap.h"
#include "../../Monster.h"
#include "../../Hero.h"
#include "../../Damage.h"
#include "../../Game.h"
#include "../../JSON.h"
#include "../../Map.h"
#include <gtest/gtest.h>

TEST(MarkedMap, getHeroValidCoordinates){
    Damage tmp (3, 1);
	Hero Herotest("Enigma", 30, tmp, 1.1, 0.5, 20, 5, 1, 0.9, 0.1, 1);
	
	int setX = 4;
	int setY = 5;
	Game game = Game("../ ../maps/level1.txt");
    game.putHero(Herotest, setX, setY);
    
	//~ ASSERT_THROW(1, 1);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
