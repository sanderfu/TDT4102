#include <iostream>

int main() {
	for (int s = 0; s < 10; s++) {
		int dataLogged = 0;
		std::cin >> dataLogged;
		if (dataLogged == -1) {
			break;
		}
		int totalDistance = 0;
		int currentSpeed = 0;
		int currentTime = 0;
		int prevTime = 0;
		for (int i = 0; i < dataLogged; i++) {
			int toAdd = 0;
			std::cin >> currentSpeed;
			std::cin >> currentTime;
			toAdd = currentSpeed * (currentTime - prevTime);
			prevTime = currentTime;
			totalDistance += toAdd;
		}
		std::cout << totalDistance << " miles" << std::endl;
	}
}