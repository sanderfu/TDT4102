#include <iostream>
#include <iomanip>

//a
int inputIntegrer() {
	int number = 0;
	std::cout << "Skriv inn et heltall:" << std::ends;
	std::cin >> number;
	return number;
}

void inputIntegerersUsingLoopAndPrintSum() {
	int amountOfNumbers = 0;
	int theSum = 0;
	std::cout << "Hvor mange tall vil du summere:" << std::ends;
	std::cin >> amountOfNumbers;
	for (int i = 0; i < amountOfNumbers; i++) {
		theSum += inputIntegrer();
	}
	std::cout << "Summen av tallene: " << theSum << std::endl;
}

//b
	//Dersom bruker skal bestemme tall p� forh�nd er for-l�kke bedre egnet fordi da bestemmer hvor mange inputs som skal tas inn og ikke trenger avbryte
	//mens dersom bruker skal avslutte n�r bruker etter hvert �nsker er while-l�kke bedre egnet fordi den er klar til � avslutte p� brukers foresp�rsel

//c
double inputDouble() {
	double number = 0;
	std::cout << "Skriv inn et flyttall:" << std::ends;
	std::cin >> number;
	return number;

}

//d
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
	std::cout << std::setprecision(2) << currencyConv << " EUR" <<std::endl;
}

//e
	//Vi m� bruke inputDouble() for ellers vil desimalene i et desimaltall i input forkastes og resultatet blir mindre presist.

int main() {
	std::cout << "Deloppgave a) Summering" << std::endl;
	inputIntegerersUsingLoopAndPrintSum();

	std::cout << "Deloppgave b) inputDouble()" << std::endl;
	std::cout << inputDouble() << std::endl;

	std::cout << "Deloppgave d) NOK til EUR" << std::endl;
	convCurrency();
}
