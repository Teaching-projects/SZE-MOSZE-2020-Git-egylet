#include "Character.h"
#include <iostream>



int main(int argc, char* argv[]) {
    try {
        if (argc == 3) {

            character player1 = character(character::parseUnit(argv[1]));
            character player2 = character(character::parseUnit(argv[2]));

            std::cout << player1 << player2 << std::endl;
            while (player1.isAlive() && player2.isAlive()) {

                player1.attack(player2);
                std::cout << player1 << player2 << std::endl;
                if (!player2.isAlive()) {
                    std::cout << player2.getName() << " died. " << player1.getName() << " wins." << std::endl;
                    break;
                }

                player2.attack(player1);
                std::cout << player1 << player2 << std::endl;
                if (!player1.isAlive()) {
                    std::cout << player1.getName() << " died. " << player2.getName() << " wins." << std::endl;
                    break;
                }
            }
        }
        else {
            std::cout << "Inappropriate command line inputs. Game will now close." << std::endl;
        }

    }
    catch(std::exception & e) {
        std::cout << "Inappropriate command line inputs, or the file does not exist,please try again" << std::endl;
            
    }
    return 0;
}