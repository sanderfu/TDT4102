#include <iostream>
#include "cannonball.h"
#include "utilities.h"
#include <cmath>

#define PI 3.14159

//2a)
double acclY() {
	return -9.81;
}

//2b)
double velY(double initVelocityY, double time) {
	return initVelocityY + acclY()*time;
}

//2c)
double posX(double initPositionX, double initVelocityX, double time) {
	return initPositionX + initVelocityX * time;
}

double posY(double initPositionY, double initVelocityY, double time) {
	return initPositionY + initVelocityY * time + (acclY()*pow(time, 2)) / 2;
}

//2d)
void printTime(double time) {
	int hours = 0;
	int minutes = 0;
	double seconds = 0;
	while (time >= 3600) {
		time -= 3600;
		hours += 1;
	}
	while (time >= 60) {
		time -= 60;
		minutes += 1;
	}
}

//2e)
double flightTime(double initVelocityY) {
	return (-2 * initVelocityY) / acclY();
}

//---------------------------------------------//

//4a)
void getUserInput(double *theta, double *absVelocity) {
	std::cout << "Skriv inn en theta:" << std::ends;
	std::cin >> *theta;
	std::cout << "Skriv inn en fart:" << std::ends;
	std::cin >> *absVelocity;
}

double degToRad(double deg) {
	return (deg / 180)*PI;
}

double getVelocityX(double theta, double absVelocity) {
	return cos(degToRad(theta))*absVelocity;
}

double getVelocityY(double theta, double absVelocity) {
	return sin(degToRad(theta))*absVelocity;
}

void getVelocityVector(double theta, double absVelocity, double *velocityX, double *velocityY) {
	*velocityX = getVelocityX(theta, absVelocity);
	*velocityY = getVelocityY(theta, absVelocity);
}

//4b)
double getDistanceTraveled(double velocityX, double velocityY) {
	return flightTime(velocityY)*velocityX;
}

//4c)
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
	return distanceToTarget - getDistanceTraveled(velocityX, velocityY);
}

/* Gjort, ingen problemer oppdaget, fortsetter*/

//---------------------------------------------------//

//6a)
void playTargetPractice() {
	setlocale(LC_ALL, "Norwegian");
	double theta = 0;
	double absVelocity = 0;
	double velocityX = 0;
	double velocityY = 0;
	int targetDistance = randomWithLimits(100, 1000);
	for (int i = 1; i <= 10; i++) {
		std::cout << "Skriv inn vinkel (i grader) og startfart på følgende format\n"
			<< "vinkel fart" << std::endl;
		std::cin >> theta >> absVelocity;
		getVelocityVector(theta, absVelocity, &velocityX, &velocityY);
		double offset = targetPractice(targetDistance, velocityX, velocityY);
		if (abs(offset) < 5) {
			std::cout << "Gratulerer, du traff blinken på forsøk: " << i << std::endl;
			return;
		}
		else if (offset < 0) {
			std::cout << "Du var " << abs(offset) << " meter unna, kastet var for langt" << std::endl;
		}
		else if (offset > 0) {
			std::cout << "Du var " << abs(offset) << " meter unna, kastet var for kort" << std::endl;
		}
		std::cout << " " << std::endl;
	}
	std::cout << "Du klarte ikke skuddet på " << targetDistance << " meter." << std::endl;
}
