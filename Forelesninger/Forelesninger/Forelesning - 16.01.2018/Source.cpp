#include <iostream>
#include <cassert>

const int SIZE = 5;

void reverser(const int original[], int copy[], const int size) {
	for (int i = 0, j = size - 1; i < size; i++, j--) {
		copy[j] = original[i];
	}
}

int main() {
	int tabA[SIZE] = { 1, 2, 3, 4, 5 };
	int tabB[SIZE] = {};
	reverser(tabA, tabB, SIZE);

	for (int i = 0; i < SIZE; i++) {
		std::cout << tabB[i] << " ";
	}
	std::cout << std::endl;
}
