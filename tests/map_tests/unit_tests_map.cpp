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

TEST(Map, MaxWidth){
	Map map_test("../../maps/level1.txt");
	int expected_width = 14;

	ASSERT_EQ(map_test.horizontalget(), expected_width);
}

TEST(Map, getHorizontalSize){
	Map map_test("../../maps/level1.txt");
	int expected_width = 7;

	ASSERT_EQ(map_test.getmapsize(), expected_width);
}

TEST(Map, MinWidth){
	Map map_test("../../maps/level1.txt");
	int expected_width = 9;
	int out_width;
	
	for (int i = 0; i < map_test.getmapsize(); i++)
	{
		out_width = map_test.getwidth(i);
	}

	ASSERT_EQ(out_width, expected_width);
}

TEST(Map, getMapLine){
	Map map_test("../../maps/level1.txt");
	std::string expected_line = "#   #  ##  #";
	int test_index = 4;
	
	ASSERT_EQ(map_test.getMapLine(test_index), expected_line);
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
