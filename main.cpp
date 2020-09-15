#include "functions.h"
#include <iostream>



int main(int argc, char* argv[]) {
    character A(argv[1], std::stoi(argv[2]), std::stoi(argv[3]));
    character B(argv[4], std::stoi(argv[5]), std::stoi(argv[6]));

    A.status();
    B.status();
    while (A.isAlive() && B.isAlive()) {

        A.attack(B);
        A.status();
        B.status();
        if (!B.isAlive()) {
            std::cout << argv[4] << " died. " << argv[1] << " wins." << std::endl;
            break;
        }

        B.attack(A);
        A.status();
        B.status();
        if (!A.isAlive()) {
            std::cout << argv[1] << " died. " << argv[4] << " wins." << std::endl;
            break;
        }

    }
    




}