OBJs := Jsonparser.o Monster.o Hero.o main.o
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
	sudo apt install -y cppcheck && sudo apt install -y valgrind && sudo apt install -y gcc g++ && sudo apt install doxygen 

static_code_analysis:
	cppcheck $(CPPS) --output-file=cppcheck_output.txt && chmod +x tests/warningcheck.sh && ./warningcheck.sh && chmod +x test/errorcheck.sh && ./errorcheck.sh

leakcheck:
	valgrind $(VFLAGS) $(VPARAMETER)

io-diff-tests:
	chmod +x tests/task4_inout.sh && ./tests/task4_inout.sh

doc:
	doxygen doxyconf

