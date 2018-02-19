#include <iostream>
#include <ctime>
#include "tests.h"
#include "utilities.h"
#include "tasks.h"
#include "playMastermind.h"

int main() {
	std::srand(std::time(nullptr));
	setlocale(LC_ALL, "Norwegian");
	int repeat = 1;
	int toRun = -1;
	while (repeat) {
		std::cout
			<< "Hvilken oppgave vil du kjøre:\n"
			<< "0) Avslutt\t"
			<< "1) Oppgave 1\t"
			<< "2) Oppgave 2 og 3\t"
			<< "3) Oppgave 4\t"
			<< "4) Play Mastermind"
			<< std::endl;
		std::cin >> toRun;
		switch (toRun) {
		case 1: taskOne(); break;
		case 2: testTableSorting(); break;
		case 3: testCStrings(); break;
		case 4: playMastermind(); break;
		case 0: repeat = 0; break;
		}
	}
	
}

