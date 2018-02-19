#include "Person.h"
#include "Meeting.h"

void testPersonClass() {
	Car car1(2);
	Person man1("Ivar Aasen", "ivar@aasen.no", &car1);
	Person man2("Yngve Aasen", "yngve@aasen.no");
	Person man3("Asbjorn Aasen", "asbjorn@aasen.no");
	std::cout << man1 << std::endl;
	std::cout << man2 << std::endl;
	std::cout << man3 << std::endl;
	int check = man1 < man2;
	int check2 = man1 < man3;
	std::cout << check << std::endl;
	std::cout << check2 << std::endl;
}

void testMeetingClass() {
	Car car1(3);
	Person man1("Ivar Aasen", "ivar@aasen.no", &car1);
	Person man2("Yngve Aasen", "yngve@aasen.no");
	Person man3("Asbjorn Aasen", "asbjorn@aasen.no");
	Person man4("Asgeir Asgaard", "asgaarden@gmail.com");
	std::string subject = "Test";
	Meeting meeting1(1, 5, 6, TRH, subject, &man1);
	meeting1.addParticipants(&man2);
	meeting1.addParticipants(&man3);
	std::vector<Person> theParticipants = meeting1.getParticipantList();
	std::cout << meeting1 << std::endl;
	std::vector<const Person*> potentialLeaders = meeting1.findPotentialCoDriving();

}