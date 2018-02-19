#include <iostream>
#include "playMastermind.h"
#include "utilities.h"

const int SIZE = 4;
const int LETTERS = 6;

int checkCharactersAndPosition(char solution[], char guess[]) {
	int theResult = 0;
	for (int i = 0; i < SIZE; i++) {
		if (solution[i] == guess[i]) {
			theResult += 1;
		}
	}
	return theResult;
}

int checkCharacters(char solution[], char guess[]) {
	int theResult = 0;
	for (int i = 65; i < 65+LETTERS; i++) {
		if (countOccurencesOfCharacter(solution, SIZE, i) > countOccurencesOfCharacter(guess, SIZE, i)) {
			theResult += countOccurencesOfCharacter(guess, SIZE, i);
		}
		else {
			theResult += countOccurencesOfCharacter(solution, SIZE, i);
		}
	}
	return theResult;
}

void playMastermind() {
	std::cout << "Let's play mastermind\nGuess a combination of " << SIZE << " chars: " << std::endl;
	char code[SIZE+1] = {};
	char guess[SIZE+1] = {};
	char run = 'Y';
	while (run == 'Y') {
		int tries = 0;
		randomizeCString(code, 5, 'A', 'A' + (LETTERS - 1));
		while ((checkCharactersAndPosition(code, guess) < SIZE) and (tries < 10)) {
			readInputToCString(guess, SIZE);
			std::cout
				<< "Du har: " << checkCharactersAndPosition(code, guess) << " på rett plass\n"
				<< "Du har: " << checkCharacters(code, guess) << " riktige bokstaver" << std::endl;
			if (checkCharactersAndPosition(code, guess) == SIZE) {
				tries += 1;
				std::cout << "Gratulerer, du klarte det på: " << tries << " forsøk." << std::endl;
				return;
			}
			else {
				tries += 1;
			}
		}
		std::cout << "Du klarte det desverre ikke, koden var: " << code <<", vil du spille en runde til (Y/N)" << std::endl;
		std::cin >> run;
	}
}