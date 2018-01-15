#include <iostream>
#include <iomanip>

//a
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

//b
	//Dersom bruker skal bestemme tall på forhånd er for-løkke bedre egnet fordi da bestemmer hvor mange inputs som skal tas inn og ikke trenger avbryte
	//mens dersom bruker skal avslutte når bruker etter hvert ønsker er while-løkke bedre egnet fordi den er klar til å avslutte på brukers forespørsel

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
	//Vi må bruke inputDouble() for ellers vil desimalene i et desimaltall i input forkastes og resultatet blir mindre presist.

int main() {
	//inputIntegerersAndPrintSum();

	//std::cout << inputDouble() << std::endl;

	convCurrency();
}
