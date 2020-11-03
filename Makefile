OBJS := Jsonparser.o Monster.o Hero.o main.o
CFLAGS := -std=c++17 -Wall -Wextra 
COMPILER := g++-9

CPPS := Jsonparser.cpp Monster.cpp Hero.cpp main.cpp

VFLAGS:= --leak-check=full --error-exitcode=1
VPARAMETER:=  ./a.out scenario1.json

build: $(OBJS)
	$(COMPILER) $(CFLAGS) -o a.out $(OBJS)

Jsonparser.o: Jsonparser.cpp Jsonparser.h
	$(COMPILER) $(CFLAGS) -c Jsonparser.cpp

Monster.o: Monster.cpp Monster.h Jsonparser.h
	$(COMPILER) $(CFLAGS) -c Monster.cpp

Hero.o: Hero.cpp Hero.h Monster.h Jsonparser.h
	$(COMPILER) $(CFLAGS) -c Hero.cpp

main.o: main.cpp Monster.h Hero.h
	$(COMPILER) $(CFLAGS) -c main.cpp

clean:
	rm -rf $(OBJS) a.out cppcheck_output.txt scenario1_native.txt scenario2_native.txt

install_dependencies:
	sudo apt install -y cppcheck && sudo apt install -y valgrind && sudo apt install -y gcc g++ && sudo apt install doxygen && sudo apt install graphviz

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
	cd tests && cmake . && make

run_unittest:
	cd tests && ./runTests
