#include <iostream>
#include "cannonball.h"
#include "utilities.h"
#include "ctime"

int main() {
	std::srand(std::time(nullptr)); //setter seed til std::rand()
	playTargetPractice();
}