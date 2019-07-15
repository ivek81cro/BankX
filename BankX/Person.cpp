#include"Person.h"
#include"Account.h"

void Person::createPerson() {
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter surname: ";
	std::cin >> surname;
	std::cout << "Enter OIB: ";
	std::cin >> oib;
	std::cout << std::endl;
}

void newPerson() {
	Person per;
	per.createPerson();
}
