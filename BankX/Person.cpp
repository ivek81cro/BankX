#include"Person.h"
#include"Account.h"

void Person::createPerson(Person& per) {
	std::cout << "Enter name: ";
	std::cin >> per.name;
	std::cout << "Enter surname: ";
	std::cin >> per.surname;
	std::cout << "Enter OIB: ";
	std::cin >> per.oib;
	std::cout << std::endl;
}

void newPerson() {
	Person per;
	per.createPerson(per);
}
