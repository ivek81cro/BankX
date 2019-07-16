#include"Person.h"
#include"Account.h"
#include"Xclass.h"
//endter data for new customer
void Person::createPerson() {
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter surname: ";
	std::cin >> surname;
	std::cout << "Enter OIB: ";
	std::cin >> oib;
	std::cout << std::endl;
	savePerson(this);
}
//save new customer
void savePerson(Person* p) {
	std::ofstream f;
	f.open("person.bank", std::ios::binary | std::ios::app);
	if (!f)	throw Xfile();
	f.write(reinterpret_cast<char*>(p), sizeof(*p));
	f.close();
}
//create new customer
void newPerson() {	
	Person p; p.createPerson();
}
//check if customer exists in records
bool checkCust(const char* n) {
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
Person& printName(const char* n, Person& t) {
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
//name print format
std::ostream& operator<<(std::ostream& os, const Person& p) {
	return os << p.name << ' ' << p.surname;
}

