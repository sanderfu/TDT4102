#include "card.h"
#include <string>

//task 1
std::string suitToString(Suit s) {
	std::string toReturn;
	switch (s) {
	case 0: toReturn = "CLUBS"; break;
	case 1: toReturn = "DIAMONDS"; break;
	case 2: toReturn = "HEARTS"; break;
	case 3: toReturn = "SPADES"; break;
	}
	return toReturn;
}

std::string rankToString(Rank r) {
	std::string toReturn;
	switch (r) {
	case 2: toReturn = "TWO"; break;
	case 3: toReturn = "THREE"; break;
	case 4: toReturn = "FOUR"; break;
	case 5: toReturn = "FIVE"; break;
	case 6: toReturn = "SIX"; break;
	case 7: toReturn = "SEVEN"; break;
	case 8: toReturn = "EIGHT"; break;
	case 9: toReturn = "NINE"; break;
	case 10: toReturn = "TEN"; break;
	case 11: toReturn = "JACK"; break;
	case 12: toReturn = "QUEEN"; break;
	case 13: toReturn = "KING"; break;
	case 14: toReturn = "ACE"; break;
	}
	return toReturn;
}


//task 2
std::string toString(CardStruct cs) {
	std::string toReturn;
	toReturn = rankToString(cs.r) + " OF " + suitToString(cs.s);
	return toReturn;
}

std::string toStringShort(CardStruct cs) {
	std::string toReturn = suitToString(cs.s).substr(0,1) + std::to_string(cs.r);
	return toReturn;
}


//task 3
void Card::initialize(Suit suit, Rank rank) {
	this->suit = suit;
	this->rank = rank;
	valid = true;
}

Suit Card::getSuit(){
	return suit;
}

Rank Card::getRank(){
	return rank;
}

std::string Card::toString(){
	std::string toReturn;
	if (valid) {
		toReturn = rankToString(rank) + " OF " + suitToString(suit);
	}
	else {
		toReturn = "Invalid Card";
	}
	return toReturn;
}

std::string Card::toStringShort() {
	std::string toReturn;
	if (valid) {
		toReturn = suitToString(suit).substr(0, 1) + std::to_string(rank);
	}
	else {
		toReturn = "Invalid Card";
	}
	return toReturn;
}

Card::Card() {
	valid = false;
}
Card::Card(Suit suit, Rank rank) {
	this->suit = suit;
	this->rank = rank;
	valid = true;
}
