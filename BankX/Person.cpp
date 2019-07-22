#include"Person.h"
#include"Account.h"
#include"Xclass.h"
#include"Tools.h"

//endter data for new customer
void Person::createPerson() {
	Toolbox v;
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter surname: ";
	std::cin >> surname;
	std::cout << "Enter OIB: ";
	std::cin >> oib;
	v.checkElem(oib,"o") ? NULL : throw Xoib();
	std::cout << std::endl;
	savePerson();
}

//name print format->cout<< Person
std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << p.name << "\t\t" << p.surname << "\t\t" << p.oib << std::endl;
}

//save new customer
void Person::savePerson() {
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

void ManagerPers::searchByOIB() {
	Toolbox v;
	char c[12];
	std::cout << "Enter OIB: ";
	std::cin >> c;
	v.checkElem(c,"o") ? NULL : throw Xoib();
	v.allPerson(c);
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
