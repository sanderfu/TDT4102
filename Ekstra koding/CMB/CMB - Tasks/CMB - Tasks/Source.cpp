#include <iostream>
#include <string>

int countZeros(int N, int M) {
	int zeros = 0;
	int temp = 0;
	int digit = 0;
	int numberArray[7] = {};
	for (int i = N; i <= M; i++) {
		temp = i;
		if (temp == 0) {
			zeros += 1;
		}
		while (temp>0) {
			digit = temp % 10;
			if (digit == 0) {
				zeros += 1;
			}
			temp /= 10;
		}
	}
	return zeros;
}

int main() {
	int T = 0;
	int N = 0;
	int M = 0;
	int totalZeros = 0;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		std::cin >> N >> M;
		totalZeros = countZeros(N, M);
		std::cout << totalZeros << std::endl;
	}
}