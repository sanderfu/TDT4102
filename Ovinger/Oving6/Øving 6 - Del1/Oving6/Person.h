#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "Car.h"

class Person{
private:
	std::string name;
	std::string email;
	Car *car;
public:
	Person(std::string theName, std::string theEmail, Car *car);
	Person(std::string theName, std::string theEmail);
	std::string getName() const;
	std::string getEmail() const;
	void setEmail(std::string theEmail);
	bool hasAvailableSeats() const;
	bool reserveFreeSeat() const;
};

//MERK: Overloadinga som tar inn Person må være under klassedeklarasjonen!
std::ostream& operator<<(std::ostream &out, const Person &p);

bool operator<(const Person &p1, const Person &p2);