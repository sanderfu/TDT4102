#pragma once
#include <string>


//task 1
enum Suit {CLUBS, DIAMONDS,HEARTS,SPADES};
enum Rank {TWO=2,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,ACE};

std::string suitToString(Suit s);
std::string rankToString(Rank r);


//task 2
struct CardStruct {
	Suit s;
	Rank r;
};

std::string toString(CardStruct cs);

std::string toStringShort(CardStruct cs);

//task 3
class Card {
private:
	Suit suit;
	Rank rank;
	bool valid;
public:
	Card();
	Card(Suit suit, Rank rank);
	void initialize(Suit suit, Rank rank);
	Suit getSuit();
	Rank getRank();
	std::string toString();
	std::string toStringShort();
};