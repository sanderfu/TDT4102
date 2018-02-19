#pragma once
#include "person.h"
#include <vector>

enum Campus {TRH=1,GJO,AAl};

class Meeting{
private:
	int day;
	int startTime;
	int endTime;
	Campus location;
	std::string subject;
	const Person *leader;
	std::vector<const Person *>participants;
	static std::vector<const Meeting *> meetings;
public:
	Meeting(int day, int startTime, int endTime, Campus location, std::string subject, Person *person);
	~Meeting(void);
	int getDay() const { return day; }
	int getStartTime() const { return startTime; }
	int getEndTime() const { return endTime; }
	Campus getLocation() const { return location; }
	std::string getSubject() const { return subject; }
	Person getLeader() const { return *leader; }
	void addParticipants(const Person *person);
	std::vector<const Meeting *> getMeetings();
	std::vector<Person> getParticipantList() const;
	std::vector<const Person *> findPotentialCoDriving();
	

};

std::ostream& operator<<(std::ostream& out, const Campus &camp);

std::ostream& operator<<(std::ostream& out, const Meeting &meeting);
