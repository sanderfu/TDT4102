#include <iostream>
#include <string>
#include "Blackjack.h"
#include "card.h"

Blackjack::Blackjack(CardDeck theDeck) : deck(theDeck) {};

bool Blackjack::isAce(Card *card) {
	if ((*card).getRank() == ACE) { //Kunne også brukt card->getRank() tror jeg (Sjekk med Studass)
		return true;
	}
	else {
		return false;
	}
}

int Blackjack::getCardValue(Card *card) {
	if (isAce(card)) {
		return -1;
	}
	else if ((*card).getRank() > TEN) {
		return 10;
	}
	else {
		return (*card).getRank();
	}
}

//For debugging-purposes//
CardDeck Blackjack::getDeck() {
	return deck;
}
//----------------------//

int Blackjack::getPlayerCardValue(Card *card) {
	int playerChoice = 0;
	if (getCardValue(card) == -1) {
		do {
			std::cout << "Do you want the Ace to take value 1 or 11:" << std::ends;
			std::cin >> playerChoice;
		} while (playerChoice != 1 && playerChoice != 11);
		return playerChoice;
	}
	else {
		return getCardValue(card);
	}
}

int Blackjack::getDealerCardValue(Card *card, int hand) {
	if (isAce(card)) {
		if (hand + (*card).getRank() <= 21) {
			return 11;
		}
		else {
			return 1;
		}
	}
	else {
		return (*card).getRank();
	}
}

bool Blackjack::askPlayerDrawCard() {
	std::cout << std::endl;
	std::cout << "Your current value at hand is " << playerHand << std::endl;
	char playerChoice;
	std::cout << "Do you want to draw a card? (Y/N)" << std::endl;
	do {
		std::cin >> playerChoice;
	} while (toupper(playerChoice) != 'Y' && toupper(playerChoice) != 'N');
	if (toupper(playerChoice) == 'Y') {
		return true;
	}
	else {
		return false;
	}
}

void Blackjack::drawInitialCards() {
	for (int i = 0; i < INTSIZE; i++) {
		Card dealerCard = deck.drawCard();
		dealerHand += getDealerCardValue(&dealerCard,dealerHand);
		if (i == 0) {
			std::cout << "The first card the dealer drew was:" << std::endl;
			std::cout << dealerCard.toString() << std::endl;
		}
		playerHand += getPlayerCardValue(&deck.drawCard());
		playerCardsDrawn += 1;
		dealerCardsDrawn += 1;

	}
}

bool Blackjack::hasBlackjack(int handValue,int cardsDrawn) {
	if (handValue == 21 && cardsDrawn == 2) {
		return true;
	}
	else {
		return false;
	}
}

void Blackjack::printFeedback() {
	std::cout << std::endl;
	std::cout
		<< "Results:\n"
		<< "Your hand:\t" << playerHand << "\t" << "Cards drawn:\t" << playerCardsDrawn << "\n"
		<< "Dealer hand:\t" << dealerHand << "\t" << "Cards drawn:\t" << dealerCardsDrawn
		<< std::endl;
}

void Blackjack::playGame() {
	bool keepGoing = true;
	bool winner = false;
	bool drawChoice = false;
	std::cout << "Let's start the game!" << std::endl;
	deck.shuffle();
	drawInitialCards();
	while (keepGoing) {
		drawChoice = askPlayerDrawCard();
		if (drawChoice) {
			playerHand += getPlayerCardValue(&deck.drawCard());
			playerCardsDrawn += 1;
			if (playerHand > 21) {
				winner = false;
				std::cout << "You unfortunately lost this round of Blackjack, feel free to play again!" << std::endl;
				printFeedback();
				return;
			}
		}
		else if (!drawChoice && dealerHand > 17) {
			if (playerHand > dealerHand || (hasBlackjack(playerHand, playerCardsDrawn) && !hasBlackjack(dealerHand, dealerCardsDrawn))) {
				winner = true;
				std::cout << "Congratulations, you won this round of Blackjack, feel free to play again!" << std::endl;
				printFeedback();
				return;
			}
			else {
				winner = false;
				std::cout << "You unfortunately lost this round of Blackjack, feel free to play again!" << std::endl;
				printFeedback();
				return;
			}
		}
		if (dealerHand < 17) {
			dealerHand += getDealerCardValue(&deck.drawCard(), dealerHand);
			dealerCardsDrawn += 1;
			}
		if (dealerHand > 21) {
			winner = true;
			std::cout << "Congratulations, you won this round of Blackjack, feel free to play again!" << std::endl;
			printFeedback();
			return;
		}
	}
}

