#pragma once
#include <string>
#include <vector>
#include "card.h"

const int DECKSIZE = 52;
const int SUITSIZE = 13;

class CardDeck {
private:
	std::vector<Card> cards;
	int currentCardIndex;
	void swap(int index1, int index2);
public:
	CardDeck();
	void print();
	void printShort();
	void shuffle();
	Card drawCard();
};