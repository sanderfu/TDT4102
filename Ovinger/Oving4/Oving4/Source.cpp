#include <iostream>
#include <ctime>
#include "tests.h"
#include "utilities.h"
#include "tasks.h"
#include "playMastermind.h"

int main() {
	std::srand(std::time(nullptr));
	setlocale(LC_ALL, "Norwegian");
	int toRun = -1;
	std::cout
		<< "Hvilken oppgave vil du kjøre:\n"
		<< "1) Oppgave 1\t"
		<< "2) Oppgave 2 og 3\t" 
		<< "3) Oppgave 4\t"
		<< "4) Play Mastermind"
		<< std::endl;
	std::cin >> toRun;
	switch (toRun) {
		case 1: taskOne();
		case 2: testTableSorting();
		case 3: testCStrings();
		case 4: playMastermind();
	}
}

