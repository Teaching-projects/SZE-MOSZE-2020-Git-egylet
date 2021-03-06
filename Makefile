OBJS := JSON.o Map.o Damage.o Monster.o Hero.o Game.o main.o 
CFLAGS := -std=c++17 -Wall -Wextra 
COMPILER := g++-9

CPPS := JSON.cpp Damage.cpp Monster.cpp Hero.cpp Map.cpp Game.cpp main.cpp 

build: $(OBJS)
	$(COMPILER) $(CFLAGS) -o a.out $(OBJS)

JSON.o: JSON.cpp JSON.h
	$(COMPILER) $(CFLAGS) -c JSON.cpp

Map.o: Map.cpp Map.h
	$(COMPILER) $(CFLAGS) -c Map.cpp

Damage.o: Damage.cpp Damage.h
	$(COMPILER) $(CFLAGS) -c Damage.cpp

Monster.o: Monster.cpp Monster.h JSON.h Damage.h
	$(COMPILER) $(CFLAGS) -c Monster.cpp

Hero.o: Hero.cpp Hero.h Monster.h JSON.h Damage.h
	$(COMPILER) $(CFLAGS) -c Hero.cpp

Game.o: Game.cpp Monster.h Hero.h Map.h
	$(COMPILER) $(CFLAGS) -c Game.cpp

main.o: main.cpp Monster.h Hero.h
	$(COMPILER) $(CFLAGS) -c main.cpp

clean:
	rm -rf $(OBJS) a.out cppcheck_output.txt scenario1_native.txt scenario2_native.txt

install_googletest_and_cmake:
	sudo apt install libgtest-dev && sudo apt install cmake && cd /usr/src/gtest && sudo cmake . && sudo make && sudo cp *.a /usr/lib && sudo ln -s /usr/lib/libgtest.a /usr/local/lib/libgtest.a && sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/libgtest_main.a

static_code_analysis:
	cppcheck $(CPPS) --output-file=cppcheck_output.txt && chmod +x tests/warningcheck.sh && ./tests/warningcheck.sh && chmod +x tests/errorcheck.sh && ./tests/errorcheck.sh

leakcheck:
	valgrind $(VFLAGS) $(VPARAMETER) ./tests/directions.sh

io-diff-tests:
	chmod +x tests/final_inout.sh && ./tests/final_inout.sh

doc:
	doxygen doxconf

build_monster_unittest:
	cd tests/monster_tests && cmake CMakeLists.txt && make

run_monster_unittest:
	cd tests/monster_tests && ./runTests

build_damage_unittest:
	cd tests/damage_tests && cmake CMakeLists.txt && make

run_damage_unittest:
	cd tests/damage_tests && ./runTests

build_map_unittest:
	cd tests/map_tests && cmake CMakeLists.txt && make

run_map_unittest:
	cd tests/map_tests && ./runTests

build_json_unittest:
	cd tests/json_tests && cmake CMakeLists.txt && make

run_json_unittest:
	cd tests/json_tests && ./runTests

build_hero_unittest:
	cd tests/hero_tests && cmake CMakeLists.txt && make

run_hero_unittest:
	cd tests/hero_tests && ./runTests
