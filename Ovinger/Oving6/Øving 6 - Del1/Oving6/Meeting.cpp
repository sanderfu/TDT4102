#include "Meeting.h"

std::ostream& operator<<(std::ostream& out, const Campus &camp) {
	switch (camp) {
	case TRH: out << "Trondheim"; break;
	case GJO: out << "Gjovik"; break;
	case AAl: out << "Aalesund"; break;
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const Meeting &meeting) {
	out << "Subject: " << meeting.getSubject() << "\n"
		<< "Location: " << meeting.getLocation() << "\n"
		<< "Start time: " << meeting.getStartTime() << "\n"
		<< "End time: " << meeting.getDay() << "\n"
		<< "Leader\n" << meeting.getLeader();
	return out;
}

std::vector<const Meeting *> Meeting::meetings;

Meeting::Meeting(int day, int startTime, int endTime, Campus location, std::string subject, Person *person) {
	this->day = day;
	this->startTime = startTime;
	this->endTime = endTime;
	this->location = location;
	this->subject = subject;
	this->leader = person;
	addParticipants(person);
	this->meetings.push_back(this);
}

Meeting::~Meeting(void) {
	for (int i = 0; i < meetings.size(); i++) {
		if (meetings[i] == this) {
			meetings.erase(meetings.begin()+i); //merk deg at vi ikke kan bruke i direkte men må ha allocator som har verdi til start av vector+i. Spør gjerne studass om hvordan dette funker.
}
	}
}

void Meeting::addParticipants(const Person *person) {
	participants.push_back(person);
	if (participants.size() == 1) {
		return;
	}
	else {
		leader->reserveFreeSeat();
		const Person *temp;
		for (unsigned int i = 0; i < participants.size(); i++) {
			for (unsigned int k = i+1; k < participants.size(); k++) {
				if (*participants[k] < *participants[i]) {
					temp = participants[i];
					participants[i] = participants[k];
					participants[k] = temp;
				}
			}
		}
	}
}

//Denne funksjonen er for debugging/testing kun.//
std::vector<const Meeting *> Meeting::getMeetings() {
	return meetings;
}
//----------------------------------------------//

std::vector<Person> Meeting::getParticipantList() const { //Spør om hvorfor ikke kan bruke const person her
	std::vector<Person> ParticipantList;
	for (int i = 0; i < participants.size(); i++) {
		ParticipantList.push_back(*participants[i]);
	}
	return ParticipantList;
}

std::vector<const Person *> Meeting::findPotentialCoDriving() {
	std::vector<const Person *> potentialLeaders;
	for (int i = 0; i < meetings.size(); i++) {
		if (meetings[i]->leader->hasAvailableSeats()) {
			potentialLeaders.push_back(meetings[i]->leader);
		}
	}
	return potentialLeaders;
}