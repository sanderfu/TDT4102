#include <iostream>
#include "card.h"
#include "CardDeck.h"



CardDeck::CardDeck(){
	currentCardIndex = 0;
	int chooseSuit = 0;
	int suitHolder = 0;
	int chooseRank = 2;
	Card temp;
	for (int i = 0; i < DECKSIZE; i++) {
		chooseSuit = i / SUITSIZE;
		if (chooseSuit != suitHolder) {
			chooseRank = 2;
		}
		temp.initialize(Suit(chooseSuit), Rank(chooseRank));
		cards.push_back(temp);
		suitHolder = chooseSuit;
		chooseRank += 1;
	}
}

void CardDeck::swap(int index1, int index2) {
	Card temp = cards[index1];
	cards[index1] = cards[index2];
	cards[index2] = temp;
}

void CardDeck::print() {
	for (int i = 0; i < DECKSIZE; i++) {
		std::cout << cards[i].toString() << std::endl;
	}
}

void CardDeck::printShort() {
	for (int i = 0; i < DECKSIZE; i++) {
		std::cout << cards[i].toStringShort() << std::endl;
	}
}

void CardDeck::shuffle() {
	int cardOne = 0;
	int cardTwo = 0;
	Card temp;
	for (int i = 0; i < (std::rand() % 1000); i++) {
		cardOne = (std::rand() % DECKSIZE);
		cardTwo = (std::rand() % DECKSIZE);
		temp = cards[cardOne];
		cards[cardOne] = cards[cardTwo];
		cards[cardTwo] = temp;
	}
}

Card CardDeck::drawCard() {
	currentCardIndex += 1;				//Har testet, når i klasse vil denne endre på currentCardIndex i klassen uten peker-behov.
	return cards[currentCardIndex-1];
}
