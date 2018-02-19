#pragma once
#include "CardDeck.h"

const int INTSIZE = 2;

class Blackjack{
private:
	CardDeck deck;
	int playerHand;
	int dealerHand;
	int playerCardsDrawn;
	int dealerCardsDrawn;
public:
	CardDeck getDeck();
	Blackjack(CardDeck theDeck);
	bool isAce(Card *card);
	int getCardValue(Card *card);
	int getPlayerCardValue(Card *card);
	int getDealerCardValue(Card *card, int hand);
	bool askPlayerDrawCard();
	void drawInitialCards();
	bool hasBlackjack(int handValue, int cardsDrawn); // Liten extra lagt inn selv
	void printFeedback(); //Lagt inn en liten extra til
	void playGame();
};

