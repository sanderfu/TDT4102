#include <iostream>
#include "Blackjack.h"
#include "testBlackjack.h"

void testBlackjack() {
	CardDeck deckOne;
	Blackjack gameOne(deckOne);
	/*CardDeck temp = gameOne.getDeck();
	Card c;
	std::cout << "Running test for isAce()" << std::endl;
	for (int i = 0; i < 13; i++) {
		c = temp.drawCard();
		std::cout << c.toString() << std::endl;
		std::cout << gameOne.isAce(&c) << std::endl;
		std::cout << gameOne.getCardValue(&c) << std::endl;
		gameOne.getPlayerCardValue(&c);
	}
	gameOne.askPlayerDrawCard();*/
	gameOne.drawInitialCards();
}