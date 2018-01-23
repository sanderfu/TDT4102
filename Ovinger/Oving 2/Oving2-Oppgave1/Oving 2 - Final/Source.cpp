#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>


//Oppgave 3
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

//Oppgave 4
double discriminant(double a, double b, double c) {
	return pow(b, 2) - 4 * a*c;
}

void printRealRoots(double a, double b, double c) {
	setlocale(LC_ALL, "Norwegian");
	int disc = 0;
	disc = discriminant(a, b, c);
	if (disc > 0) {
		std::cout << "To relle røtter:" << std::endl;
		std::cout << ((-b + sqrt(discriminant(a, b, c))) / (2 * a)) << "    " << "og" << "   " << std::ends;
		std::cout << ((-b - sqrt(discriminant(a, b, c))) / (2 * a)) << std::endl;
	}
	else if (disc == 0) {
		std::cout << "En reell rot:" << std::endl;
		std::cout << (-b / 2 * a) << std::endl;
	}
	else {
		std::cout << "Ingen reelle røtter" << std::endl;
	}
}

void solveQuadricEquation() {
	setlocale(LC_ALL, "Norwegian");
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	std::cout << "Bestemm a, b og c på format:\n" << "a b c" << std::endl;
	std::cin >> a >> b >> c;
	printRealRoots(a,b,c);
	//Test med (a=1,b=2,c=4) (4,4,1) og (8,4,-1)
}


//Oppgave 5)
void calculateLoanPayments() {
	double loan = 0.0;
	double loanLeft = 0.0;
	double interest = 0.0;
	int payments = 10;
	double currentToPay = 0.0;
	std::cout << "Hvor mye skal du låne:" << std::ends;
	std::cin >> loan;
	loanLeft = loan;
	std::cout << "Hva er renta i prosent:" << std::endl;
	std::cin >> interest;
	std::cout << "År\t" << "Innbetaling\t" << "Gjenstående Lån" << std::endl;
	for (int i = 0; i < payments; i++) {
		currentToPay = (loan / payments) + (interest / 100)*loanLeft;
		loanLeft -= (loan / payments);
		std::string tp = std::to_string(currentToPay);
		std::string lo = std::to_string(loanLeft);
		std::cout << i << "\t" << tp+"\t" << lo << std::endl;
	}
}


void menu() {
	setlocale(LC_ALL, "Norwegian");
	int user = 0;
	while (user != -1) {
		std::cout << "\n" << "Velg funksjon:\n" << "0) Avslutt\n" << "1) Summer to tall\n" << "2) Summer flere tall\n" << "3) Konverter NOK til EURO\n" << "4) Multiplikasjonstabell\n" << "5) Finn reelle røtter\n" << "6) Beregn nedbetaling lån\n" << "Angi valg (0-3): " << std::ends;
		std::cin >> user;
		switch (user) {
		case 0: user = -1; break;
		case 1: inputTwoIntegerersAndPrintSum(); break;
		case 2: inputIntegerersAndPrintSum(); break;
		case 3: convCurrency(); break;
		case 4: printMultiplicationTable(); break;
		case 5: solveQuadricEquation(); break;
		case 6: calculateLoanPayments(); break;
		}
	}
}

int main() {
	menu();
}