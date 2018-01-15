#include <iostream>

int inputIntegrer() {
	int number = 0;
	std::cout << "Skriv inn et heltall:" << std::ends;
	std::cin >> number;
	return number;
}

void inputIntegerersAndPrintSum() {
	int amountOfNumbers = 0;
	int theSum = 0;
	std::cout << "Hvor mange tall vil du summere:" << std::ends;
	std::cin >> amountOfNumbers;
	for (int i = 0; i < amountOfNumbers; i++) {
		theSum += inputIntegrer();
	}
	std::cout << "Summen av tallene: " << theSum << std::endl;
}

int main() {
	inputIntegerersAndPrintSum();
}
