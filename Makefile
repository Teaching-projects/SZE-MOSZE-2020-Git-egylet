OBJS := JSON.o Monster.o Hero.o main.o
CFLAGS := -std=c++17 -Wall -Wextra 
COMPILER := g++-9

CPPS := JSON.cpp Monster.cpp Hero.cpp main.cpp

VFLAGS:= --leak-check=full --error-exitcode=1
VPARAMETER:=  ./a.out scenarios/scenario1.json

build: $(OBJS)
	$(COMPILER) $(CFLAGS) -o a.out $(OBJS)

JSON.o: JSON.cpp JSON.h
	$(COMPILER) $(CFLAGS) -c JSON.cpp

Damage.o: Damage.cpp Damage.h
	$(COMPILER) $(CFLAGS) -c Damage.cpp

Monster.o: Monster.cpp Monster.h JSON.h Damage.h
	$(COMPILER) $(CFLAGS) -c Monster.cpp

Hero.o: Hero.cpp Hero.h Monster.h JSON.h Damage.h
	$(COMPILER) $(CFLAGS) -c Hero.cpp

main.o: main.cpp Monster.h Hero.h
	$(COMPILER) $(CFLAGS) -c main.cpp

clean:
	rm -rf $(OBJS) a.out cppcheck_output.txt scenario1_native.txt scenario2_native.txt

install_googletest_and_cmake:
	sudo apt install libgtest-dev && sudo apt install cmake && cd /usr/src/gtest && sudo cmake . && sudo make && sudo cp *.a /usr/lib && sudo ln -s /usr/lib/libgtest.a /usr/local/lib/libgtest.a && sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/libgtest_main.a

static_code_analysis:
	cppcheck $(CPPS) --output-file=cppcheck_output.txt && chmod +x tests/warningcheck.sh && ./tests/warningcheck.sh && chmod +x tests/errorcheck.sh && ./tests/errorcheck.sh

leakcheck:
	valgrind $(VFLAGS) $(VPARAMETER)

io-diff-tests:
	chmod +x tests/task4_inout.sh && ./tests/task4_inout.sh

doc:
	doxygen doxconf

build_unittest:
	cd tests && cmake CMakeLists.txt && make

run_unittest:
	cd tests && ./runTests
