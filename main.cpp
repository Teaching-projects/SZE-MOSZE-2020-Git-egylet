#include "Character.h"
#include <iostream>



int main(int argc, char* argv[]) {
    character player1(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
    character player2(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));

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