#include <iostream>

int main() {
	int temperatures = 0;
	std::cin >> temperatures;
	int theRecordings = 0;
	int lows = 0;
	for (int i = 0; i < temperatures; i++) {
		std::cin >> theRecordings; // Trikset i denne oppgaven ligger i at variabelen theRecordings vil gjennom iterasjonene få alle verdier vi originalt skrev inn iden med whitespace mellom
		if (theRecordings<0) {
			lows += 1;
		}
	}
	std::cout << lows << std::endl;
}