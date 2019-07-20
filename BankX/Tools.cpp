#include"Tools.h"
#include"Person.h"
#include"Xclass.h"
#include"Account.h"
#include<fstream>


bool Toolbox::checkElem(char* c, const char* n) {
	//acc
	if (n == "a") {
		int i = 0;
		if (isalpha(c[0]) || isalpha(c[1]))
			while (*c != '\0') { ++c; ++i; }
		return i == 21;
	}
	if (n == "p") {
		Person p;
		std::ifstream f;
		f.open("person.bank", std::ios::binary);
		if (!f)	throw Xfile();
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&p), sizeof(p)))
			{
				if (!strcmp(p.getOib(), c)) return true;
			}
		}
		f.close();
		return false;
	}
	if (n == "o") {
		int i = 0;
		while (*c != '\0') { ++c; ++i; }
		return i == 11;
	}
	return false;
}

bool Toolbox::checkIfExists(char* n) {
	std::ifstream f;
	Account t;
	f.open("records.bank", std::ios::binary);
	if (!f)	throw Xfile();
	while (!f.eof()) {
		if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
		{
			if (!strcmp(t.getAccNo(), n)) return true;
		}
	}
	f.close();
	return false;
}

//print specific person (c) | (0) print all persons
void Toolbox::allPerson(const char* c) {
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
		int flag = 1;
		t.printName(c);
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				if (!strcmp(c, t.getOib())) { std::cout << t; flag = 0; }
		}
		if (flag) { std::cout << "Nothing found"; }
	}
	f.close();
}
//0 print all accounts |c print specific accounts
void Toolbox::allAccounts(const char* c) {
	std::ifstream f;
	Account t;
	f.open("records.bank", std::ios::binary);
	if (!f)	throw Xfile();
	std::cout << std::setw(18) << std::setfill(' ') << "Account number" <<
		std::setw(10) << std::setfill(' ') << "OIB" <<
		std::setw(23) << std::setfill(' ') << "\tBalance" << std::endl;
	std::cout << std::string(80, '-') << std::endl;
	if (c == 0) {
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				t.allPerson();
		}
	}
	else {
		Person p;
		p.printName(c);
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				if (!strcmp(c, t.getoib()))
					t.allPerson();
		}
		std::cout << "Owner: " << p << std::endl;
	}
	f.close();
}