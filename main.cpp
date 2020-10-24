#include "Character.h"
#include "Player.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    try {
        if (argc == 3) {
			/**
			\brief The case of normal input.
			*/
            Player player1 = Player::parseUnit(argv[1] /** [in] first player's .json file*/);		///< Making the first player by the data from the .json file
            Character player2 = Character::parseUnit(argv[2] /** [in] second player's .json file*/);	///< Making the second player by the data from the .json file

            std::string winner = player1.attack(player1 /** the player from the first .json file*/, player2 /** the player from the second .json file*/);	///< Calculating the results
			      std::cout << winner << std::endl;	///< Write out the results on the screen
        }
        else {
			/**
			\brief The case of wrong input.
			*/
            std::cout << "Inappropriate command line inputs. Game will now close." << std::endl;	///< Write out the problem on the screen
            std::cout << "Input should look like: 'A.json B.json'" << std::endl;	///< Write out the correct input form on the screen
            return 1;
        }

    }
    catch(std::exception & e) {
		/**
		\brief The case of wrong input or missing file(s).
		*/
        std::cout << "Inappropriate command line inputs, or the file does not exist,please try again" << std::endl;	///< Write out the problem on the screen
        std::cout << "Input should look like: 'A.json B.json'" << std::endl;	///< Write out the correct input form on the screen
        return 1;
    }
    return 0;
}
