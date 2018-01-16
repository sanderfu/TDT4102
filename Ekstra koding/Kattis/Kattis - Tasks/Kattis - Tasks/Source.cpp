#include <iostream>

int main() {
	int H = 0;
	int M = 0;
	std::cin >> H >> M;
	if (M >= 45) {
		M -= 45;
	}
	else if (M < 45) {
		H -= 1;
		M += 60;
		M -= 45;
		if (H < 0) {
			H += 24;
		}
	}
	std::cout << H << " " << M << std::endl;
}