#include"Person.h"
#include"Account.h"
#include"Xclass.h"

//endter data for new customer
void Person::createPerson() {
	ManagerPers m;
	ManagerAcc a;
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter surname: ";
	std::cin >> surname;
	std::cout << "Enter OIB: ";
	std::cin >> oib;
	a.checkOib(oib) ? NULL : throw Xoib();
	std::cout << std::endl;
	m.savePerson(this);
}

//name print format->cout<< Person
std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << p.name << ' ' << p.surname;
}

//person print
void Person::allPrint() {
	std::cout << name << "\t\t" << surname << "\t\t" << oib << std::endl;
}

//save new customer
void ManagerPers::savePerson(Person* p) {
	std::ofstream f;
	f.open("person.bank", std::ios::binary | std::ios::app);
	if (!f)	throw Xfile();
	f.write(reinterpret_cast<char*>(p), sizeof(*p));
	f.close();
}
//create new customer
void ManagerPers::newPerson() {
	Person p; p.createPerson();
}
//check if customer exists in records
bool ManagerPers::checkCust(const char* n) {
	std::ifstream f;
	Person t;
	f.open("person.bank", std::ios::binary);
	if (!f)	throw Xfile();
	while (!f.eof()) {
		if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
		{
			if (!strcmp(t.getOib() , n)) return true;
		}
	}
	f.close();
	return false;
}
//print name in account search
Person& ManagerPers::printName(const char* n, Person& t) {
	std::ifstream f;
	f.open("person.bank", std::ios::binary);
	if (!f)	throw Xfile();
	while (!f.eof()) {
		if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
		{
			if (!strcmp(t.getOib(), n)) return t;
		}
	}
	f.close();
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
				t.allPrint();
		}
	}
	else {
		Person p;
		int flag = 1;
		printName(c, p);
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				if (!strcmp(c, t.getoib())) { t.allPrint(); flag = 0; }
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
