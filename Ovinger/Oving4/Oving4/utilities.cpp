#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cctype>

//b
int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
	for (int i = 0; i < numTimes; i++) {
		startValue += increment;
	}
	return startValue;
}


//d
int incrementByValueNumTimes2(int *startValue, int increment, int numTimes) {
	int returner = 0;
	for (int i = 0; i < numTimes; i++) {
		*startValue += increment;
	}
	return *startValue;
}

//e)
/*Funkjsonen før brukere pekere fordi funksjoner bare kan returnere en verdi 
og fordi variable kun er def. innenfor scopet til en funksjon*/
void swapNumbers(int *num1, int *num2) {
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

//task2
void printArray(int array[], int length) {
	for (int i = 0; i < length; i++) {
		std::cout << array[i] << std::ends;
	}
	std::cout << " " << std::endl;
}

int randomWithLimits(int lowerLimit, int upperLimit) {
	assert(lowerLimit < upperLimit);
	int range = abs(upperLimit - lowerLimit)+1; // SPør Studass om hvorfor må legge til 1 i range for å få med upper limit
	return (std::rand() % range) + lowerLimit;
}

void randomizeArray(int array[], int length) {
	for (int i = 0; i < length; i++) {
		array[i] = randomWithLimits(0, 100);
	}
}

//task3
void sortArray(int array[], int length) {
	for (int i = 0; i < length; i++) {
		for (int k = i + 1; k < length; k++) {
			if (array[i] > array[k]) {
				swapNumbers(&array[i], &array[k]);
			}
		}
	}
}

double medianOfArray(int array[], int length) {
	if (length % 2 != 0) {
		int medianIndex = (length / 2);
		return array[medianIndex];
	}
	else if (length%2==0) {
		int medianIndex = (length / 2)-1;
		return (array[medianIndex] + array[medianIndex + 1]) / 2; //Vær på vakt for om opprunding blir nødvendig i senere oppgaverc
	}
}

//task4
void randomizeCString(char array[], int length, char lowestChar, char highetsChar) {
	for (int i = 0; i < length-1; i++) {
		char toInput = static_cast<char>(randomWithLimits(static_cast<int>(lowestChar), static_cast<int>(highetsChar)));
		array[i] = toInput;
	}
	array[length - 1] = '\0';
}

void readInputToCString(char array[], int amount) {
	for (int i = 0; i < amount; i++) {
		char toInput = 0;
		while ((toupper(toInput) < 'A') || (toupper(toInput) > 'F')) {
			std::cin >> toInput;
			toInput = toupper(toInput);
		}
		*(array+i) = toInput;
	}
}

int countOccurencesOfCharacter(char array[], int length, char character) {
	int amount = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] == character) {
			amount += 1;
		}
	}
	return amount;
}