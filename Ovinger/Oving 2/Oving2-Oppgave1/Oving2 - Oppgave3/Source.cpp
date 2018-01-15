#include <iostream>
#include <iomanip>

int inputIntegrer() {
	int number = 0;
	std::cout << "Skriv inn et heltall:" << std::ends;
	std::cin >> number;
	return number;
}

void inputTwoIntegerersAndPrintSum() {
	int number1 = 0;
	int number2 = 0;
	number1 = inputIntegrer(); // Brukte inputIntegerer() fordi denne returnerer input til variabel istedenfor å printe til konsoll
	number2 = inputIntegrer();
	std::cout << "Summen av tallene: " << (number1 * number2) << std::endl;
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

double inputDouble() {
	double number = 0;
	std::cout << "Skriv inn et flyttall:" << std::ends;
	std::cin >> number;
	return number;

}

void convCurrency() {
	double convRateEUR = 9.64;
	double NOKtoConv = -1;
	double currencyConv = 0;
	while (NOKtoConv < 0) {
		NOKtoConv = inputDouble();
	}
	currencyConv = NOKtoConv / convRateEUR;
	std::cout << NOKtoConv << " NOK blir:" << std::ends;
	std::cout << std::fixed;
	std::cout << std::setprecision(2) << currencyConv << " EUR" << std::endl;
}

void printMultiplicationTable() {
	int bredde = 0;
	int hoyde = 0;
	std::cout << "Angi bredde:" << std::ends;
	std::cin >> bredde;
	std::cout << "Angi hoyde:" << std::ends;
	std::cin >> hoyde;
	for (int h = 1; h <= hoyde; h++) {
		for (int b = 1; b <= bredde; b++) {
			std::cout << h * b << std::ends;
		}
		std::cout << std::endl;
	}
}

void menu() {
	int user = 0;
	while (user > -1) {
		std::cout << "\n" <<"Velg funkjson:\n" << "0) Avslutt\n" << "1) Summer to tall\n" << "2) Summer flere tall\n" << "3) Konverter NOK til EURO\n" << "4) Multiplikasjonstabell\n" << "Angi valg (0-3): " << std::ends;
		std::cin >> user;
		switch (user) {
		case 0: user = -1; break;
		case 1: inputTwoIntegerersAndPrintSum(); break;
		case 2: inputIntegerersAndPrintSum(); break;
		case 3: convCurrency(); break;
		case 4: printMultiplicationTable(); break;
		}
	}
}

int main() {
	//menu();
	printMultiplicationTable();
}