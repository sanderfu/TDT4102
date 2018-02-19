#include <cstdlib>
#include <ctime>
#include <cassert>


//5b-c)
int randomWithLimits(int lowerLimit, int upperLimit) {
	assert(lowerLimit < upperLimit);
	int range = abs(upperLimit - lowerLimit);
	int lowest = lowerLimit;
	int randomNumber = (std::rand() % range) + lowest;
	return randomNumber;
}

//-------------------------------------------------------//

//Utilities for SFML-tasks - Oving 6
//-------------------------------------------------------//

