#include "../Monster.h"
#include "../Hero.h"
#include "../JSON.h"
#include "../Map.h"
#include "../Damage.h"
#include "../Game.h"
#include <gtest/gtest.h>

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
