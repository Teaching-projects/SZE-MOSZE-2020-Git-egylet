#include "Character.h"
#include <iostream>



int main(int argc, char* argv[]) {
    try {
        if (argc == 3) {

			character player1 = character::parseUnit(argv[1]);
			character player2 = character::parseUnit(argv[2]);

            std::string winner = player1.attack(player1, player2);
			std::cout << winner << std::endl;
        }
        else {
            std::cout << "Inappropriate command line inputs. Game will now close." << std::endl;
            std::cout << "Input should look like: 'A.json B.json'" << std::endl;
            return 1;
        }

    }
    catch(std::exception & e) {
        std::cout << "Inappropriate command line inputs, or the file does not exist,please try again" << std::endl;
        std::cout << "Input should look like: 'A.json B.json'" << std::endl;
        return 1;
    }
    return 0;
}