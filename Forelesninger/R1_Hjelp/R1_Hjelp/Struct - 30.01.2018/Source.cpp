#include <iostream>

struct TemperatureMeasurement {
	double temp;
	int time;
};

void printTemperature(TemperatureMeasurement *temperature) {
	std::cout << "Peker til struct" << std::endl;
	std::cout << temperature->temp << " grader"<< std::endl;
	std::cout << temperature->time << " sekunder etter midnatt" << std::endl;
	std::cout << std::endl;
}

void printTemperature2(TemperatureMeasurement &temperature) {
	std::cout << "Referanse til struct" << std::endl;
	std::cout << temperature.temp << " grader" << std::endl;
	std::cout << temperature.time << " sekunder etter midnatt" <<  std::endl;
	std::cout << std::endl;
}

int main() {
	TemperatureMeasurement t = {
		17.6,
		1056,
	};

	printTemperature(&t);

	printTemperature2(t);

}