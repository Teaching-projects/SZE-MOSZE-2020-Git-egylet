#include "../../Map.h"
#include <gtest/gtest.h>

TEST(Map, coordinateOutOfRange){
    Map map_test("../../maps/level1.txt");
    
	ASSERT_THROW(map_test.get(1,200), Map::WrongIndexException);
}

TEST(Map, noSuchFile){
	ASSERT_THROW(Map map_test("../../maps/levelNoSuch.txt"), Map::WrongIndexException);
}

TEST(Map, constructor){
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

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
