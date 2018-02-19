#include <iostream>
#include <iomanip>
#include <cmath>
#include "utilities.h"

void testCallByValue() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes(v0, increment, iterations);
	std::cout 
		<< "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " results: " << result << std::endl;
}

void testCallByPointer() {
	int v0 = 5;
	int increment = 2;
	int iterations = 10;
	int result = incrementByValueNumTimes2(&v0, increment, iterations);
	std::cout
		<< "v0: " << v0
		<< " increment: " << increment
		<< " iterations: " << iterations
		<< " results: " << result << std::endl;
}

void testSwapNumbers() {
	int num1 = 5;
	int num2 = 10;
	std::cout << num1 << " " << num2 << std::endl;
	swapNumbers(&num1, &num2);
	std::cout << num1 << " " << num2 << std::endl;

}

//task2/3
void testTableSorting() {
	std::cout << "Kjører testTableSorting" << std::endl;
	int precentages[20] = {};
	randomizeArray(precentages, 20);
	std::cout << "Generert array m. 20 elementer:" << std::endl;
	printArray(precentages, 20);
	swapNumbers(&precentages[0], &precentages[1]);
	printArray(precentages, 20);
	sortArray(precentages, 20);
	printArray(precentages, 20);
	std::cout << "Median til array-en" << std::endl;
	std::cout << medianOfArray(precentages, 20) << std::endl;
}

//task4
void testCStrings() {
	std::cout << "Kjører testCStrings()" << std::endl;
	double theSum = 0;
	double theAverage = 0.0;
	int gradeCount[6] = {};
	char grades[9];

	for (int y = 0; y < 5; y++) {
		randomizeCString(grades, 9, 'A', 'E'); // HUSK å bruke enkle fnutter om char-verdier!
		std::cout << grades << std::endl;
		for (int i = 0; i < 6; i++) {
			gradeCount[i] = countOccurencesOfCharacter(grades, 8, ('A' + i));
		}
		for (int i = 1; i < 7; i++) {
			theSum += gradeCount[i - 1] * i;
		}
	}
	std::cout << "Printer ut gjennomsnittskarakteren som tall og bokstav" << std::endl;
	theAverage = theSum / (8 * 5);
	std::fixed;
	std::cout << std::setprecision(2) << theAverage << " : " << static_cast<char>('A' + (round(theAverage) - 1)) << std::endl;
	
	//------------------------------------------------------------------------------------------------------//
	
	theSum = 0;
	theAverage = 0;
	for (int y = 1; y < 6; y++) {
		std::cout << "Skriv inn de 8 karakteren du fikk " << y << ". år." << std::endl;
		readInputToCString(grades, 8);
		std::cout << grades << std::endl;
		for (int i = 0; i < 6; i++) {
			gradeCount[i] = countOccurencesOfCharacter(grades, 8, ('A' + i));
		}
		for (int i = 1; i < 7; i++) {
			theSum += gradeCount[i - 1] * i;
		}
	}
	std::cout << "SNitt karakteren din ble:" << std::endl;
	theAverage = theSum / (8*5);
	std::cout << std::setprecision(2) << theAverage << " : " << static_cast<char>('A' + (theAverage-1)) << std::endl;
}