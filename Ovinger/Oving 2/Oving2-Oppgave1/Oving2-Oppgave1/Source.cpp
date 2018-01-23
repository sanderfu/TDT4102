#include <iostream>

//a
void inputAndPrintIntegerer() {
	int theInput = 0;
	std::cout << "Skriv inn et heltall:" << std::ends;
	std::cin >> theInput;
	std::cout << "Du skrev: " << theInput << std::endl;
}

//b
int inputIntegrer() {
	int number = 0;
	std::cout << "Skriv inn et heltall:" << std::ends;
	std::cin >> number;
	return number;
}

//c
void inputIntegerersAndPrintSum() {
	int number1 = 0;
	int number2 = 0;
	number1 = inputIntegrer(); // Brukte inputIntegerer() fordi denne returnerer input til variabel istedenfor å printe til konsoll
	number2 = inputIntegrer();
	std::cout << "Summen av tallene: " << (number1 + number2) << std::endl;
}

//d
//Se kommentar i linje 23

//e
bool isOdd(int a) {
	if (a % 2 == 0) {
		return false;
	}
	else {
		return true;
	}
}

//f
void printHumanReadableTime(int s) {
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	hours = s / 3600;
	minutes = (s % 3600) / 60;
	seconds = ((s % 3600) % 60);
	std::cout << hours << " timer, " << minutes << " minutter, og " << seconds << " sekunder." << std::endl;
}

int main() {
	inputAndPrintIntegerer();

	inputIntegerersAndPrintSum();

	for (int i = 10; i < 15; i++) {
		if (isOdd(i)) {
			std::cout << i << " er et oddetall" << std::endl;
		}
		else {
			std::cout << i << " er et partall" << std::endl;
		}
	}

	printHumanReadableTime(10000);

}