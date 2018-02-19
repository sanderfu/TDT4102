#include "Person.h"

std::ostream& operator<<(std::ostream &out, const Person &p) {
	std::string available = "No";
	if (p.hasAvailableSeats()) {
	available = "Yes";
	}
	out << "Name:" << p.getName() << "\n" 
		<< "Email:" << p.getEmail() << "\n" 
		<< "Has available seats: " << available;
	return out;
}

bool operator <(const Person &p1, const Person &p2) {
	if (p1.getName().substr(0, 1) < p2.getName().substr(0, 1)) {
		return true;
	}
	else {
		return false;
	}
}


Person::Person(std::string theName, std::string theEmail, Car *car) {
	this->name = theName;
	this->email = theEmail;
	this->car = car;
}

Person::Person(std::string theName, std::string theEmail) : Person(theName, theEmail, nullptr) {} //Spør hvorfor ikke kan sette den andre construktøren inni {}


std::string Person::getName() const{
	return name;
}

std::string Person::getEmail() const {
	return email;
}

void Person::setEmail(std::string theEmail) {
	email = theEmail;
}

bool Person::hasAvailableSeats() const {
	if (car != nullptr && car->hasFreeSeats()) {
		return true;
	}
	else {
		return false;
	}
}

bool Person::reserveFreeSeat() const{
	if (hasAvailableSeats()) {
		car->reserveFreeSeat();
		return true;
	}
	else {
		return false;
	}
}

