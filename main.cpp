#include "functions.h"
#include <iostream>



int main(int argc, char* argv[]) {
    character player1(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
    character player2(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));

    player1.status();
    player2.status();
    while (player1.isAlive() && player2.isAlive()) {

        player1.attack(player2);
        player1.status();
        player2.status();
        if (!player2.isAlive()) {
            std::cout << argv[4] << " died. " << argv[1] << " wins." << std::endl;
            break;
        }

        player2.attack(player1);
        player1.status();
        player2.status();
        if (!player1.isAlive()) {
            std::cout << argv[1] << " died. " << argv[4] << " wins." << std::endl;
            break;
        }

    }
    delete player1, player2;
}