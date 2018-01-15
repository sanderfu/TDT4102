#include <iostream>;

//a)
double max(double a, double b) {
	if (a > b) {
		std::cout << "A is greater than B" << std::endl;
		return a;
	}
	else {
		std::cout << "B is greater than A" << std::endl;
		return b;
	}
}

//c)
int fibonacci(int n) {
	int a = 0;
	int b = 1;
	std::cout << "Fibonacci numbers" << std::endl;
	for (int x = 1; x < n + 1; x++) {
		std::cout << (x, b) << std::endl;
		int temp = b;
		b += a;
		a = temp;
	}
	std::cout << "----" << std::endl;
	return b;
}

//d
int squareNumberSum(int n) {
	int totalSum = 0;
	for (int i = 0; i < n; i++) {
		totalSum += i * i;
		std::cout << i * i << std::endl;
	}
	std::cout << totalSum << std::endl;
	return totalSum;
}

//e
int triangleNumbersBelow(int n) {
	int acc = 1;
	int num = 2;
	std::cout << "Triangle numbers below " << n << ":" << std::ends;
		while (acc < n) {
			std::cout << acc << std::ends;
			acc += num;
			num += 1;
		}
	std::cout << "" << std::endl;
	return 0;
}

bool isTriangleNumber(int number) {
	int acc = 1;
	while (number > 0) {
		number -= acc;
		acc += 1;
	}
	return number == 0;
}

//f
bool isPrime(int n) {
	bool primeness = true;
	for (int j = 2; j < n; j++) {
		if (n % j == 0) {
			primeness = false;
			break;
		}
	}
	return primeness;
}

//g
int naivePrimeNumberSearch(int n) {
	for (int number = 2; number < n; number++) {
		if (isPrime(number)) {
			std::cout << number << " is a prime" << std::endl;
		}
	}
	return 0;
}

//h
int findGreatestDivisor(int n) {
	for (int divisor = n - 1; divisor > 0; --divisor) {
		if (n%divisor == 0) {
			return divisor;
		}
	}
}

//b++
int main() {
	std::cout << "Oppgave a)" << std::endl;
	std::cout << max(5, 6) << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Oppgave c)" << std::endl;
	std::cout << fibonacci(21) << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Oppgave d)" << std::endl;
    squareNumberSum(20);
	std::cout << "" << std::endl;

	std::cout << "Oppgave e)" << std::endl; //Spør om bedre måte å få alle på en linje
	triangleNumbersBelow(27);
	std::cout << "" << std::endl;

	std::cout << "Oppgave e)" << std::endl;
	std::cout << isTriangleNumber(15) << std::endl;
	std::cout << isTriangleNumber(8) << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Oppgave f)" << std::endl;
	std::cout << isPrime(7) << std::endl;
	std::cout << isPrime(8) << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Oppgave g)" << std::endl;
	naivePrimeNumberSearch(32);
	std::cout << "" << std::endl;

	std::cout << "Oppgave h" << std::endl;
	std::cout << "Skriv inn et tall: " << std::ends;
	int theInput = 0;
	std::cin >> theInput;
	std::cout << findGreatestDivisor(theInput) << std::ends;
	std::cout << " er storste divisor for " << theInput << std::endl;

	return 0;
}

