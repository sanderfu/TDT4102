#include <iostream>
#include <ctime>
#include "Blackjack.h"

int main() {
	std::srand(std::time(nullptr));
	bool keepPlaying = true;
	char playAgainCommand;
	while (keepPlaying) {
		CardDeck theDeck;
		Blackjack gameOne(theDeck);
		gameOne.playGame();
		std::cout << std::endl;
		std::cout << "Do you want to play again? (Y/N)" << std::endl;
		do {
			std::cin >> playAgainCommand;
		} while (toupper(playAgainCommand) != 'Y' && toupper(playAgainCommand) != 'N');
		if (toupper(playAgainCommand)=='N') {
			keepPlaying = false;
		}
	}
}