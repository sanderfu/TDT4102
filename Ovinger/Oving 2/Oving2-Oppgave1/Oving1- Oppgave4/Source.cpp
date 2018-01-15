#include <iostream>
#include <cmath>


double discriminant(double a, double b, double c) {
	return pow(b,2) - 4 * a*c;
}

void printRealRoots(double a, double b, double c) {
	setlocale(LC_ALL, "Norwegian");
	double disc = 0.0;
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
}

void solveQuadricEquation() {
	setlocale(LC_ALL, "Norwegian");
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	std::cout << "Bestemm a, b og c på format:\n" << "a b c" << std::endl;
	std::cin >> a >> b >> c;
	printRealRoots(a, b, c);
}

int main() {
	return 0;
}