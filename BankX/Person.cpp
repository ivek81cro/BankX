#include"Person.h"
#include"Account.h"
#include"Xclass.h"

//endter data for new customer
void Person::createPerson() {
	ManagerAcc a;
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter surname: ";
	std::cin >> surname;
	std::cout << "Enter OIB: ";
	std::cin >> oib;
	a.checkOib(oib) ? NULL : throw Xoib();
	std::cout << std::endl;
	savePerson();
}

//print name in account search
Person& Person::printName(const char* n) {
	std::ifstream f;
	f.open("person.bank", std::ios::binary);
	if (!f)	throw Xfile();
	while (!f.eof()) {
		if (f.read(reinterpret_cast<char*>(this), sizeof(*this)))
		{
			if (!strcmp(getOib(), n))
				break;
		}
	}
	f.close();
}

//name print format->cout<< Person
std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << p.name << "\t\t" << p.surname << "\t\t" << p.oib << std::endl;
}

//save new customer
void ManagerPers::savePerson() {
	std::ofstream f;
	f.open("person.bank", std::ios::binary | std::ios::app);
	if (!f)	throw Xfile();
	f.write(reinterpret_cast<char*>(this), sizeof(*this));
	f.close();
}
//create new customer
void ManagerPers::newPerson() {
	Person p; p.createPerson();
}
//check if customer exists in records
bool Person::checkCust(const char* n) {
	std::ifstream f;
	f.open("person.bank", std::ios::binary);
	if (!f)	throw Xfile();
	while (!f.eof()) {
		if (f.read(reinterpret_cast<char*>(this), sizeof(*this)))
		{
			if (!strcmp(getOib() , n)) return true;
		}
	}
	f.close();
	return false;
}

void ManagerPers::searchByOIB() {
	ManagerAcc a;
	char c[12];
	std::cout << "Enter OIB: ";
	std::cin >> c;
	a.checkOib(c) ? NULL : throw Xoib();
	allPersons(c);
}

//print specific person (c) | (0) print all persons
void ManagerPers::allPersons(const char* c) {
	std::ifstream f;
	Person t;
	f.open("person.bank", std::ios::binary);
	if (!f)	throw Xfile();
	std::cout << "Name" << "\t\t" << "Surname" << "\t\t" << "OIB" << std::endl;
	std::cout << std::string(50, '-') << std::endl;
	if (c == 0) {
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				std::cout << t;
		}
	}
	else {
		Person p;
		int flag = 1;
		p.printName(c);
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				if (!strcmp(c, t.getOib())) { std::cout << p; flag = 0; }
		}
		if (flag) { std::cout << "Nothing found"; }
	}
	f.close();
}
//search for customer
void ManagerPers::searchPerson() {
	try {
		ManagerPers::searchByOIB();
	}
	catch (X& x) {
		x.errorx();
	}
}
