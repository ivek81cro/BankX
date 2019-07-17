#ifndef PER_H
#define PER_H
#include<iostream>
#include<string>

class Person {
	char name[20], surname[35], oib[12];
public:
	Person() {}
	~Person() {}
	void createPerson();
	char* getOib(){ return oib; }
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
	void allPrint();
	char* getoib() { return oib; }
};

class ManagerPers {
public:
	ManagerPers() {};
	~ManagerPers() {};
	void newPerson();
	void savePerson(Person* p);
	bool checkCust(const char* n);
	void searchPerson();
	Person& printName(const char* n, Person& p);
	void allPersons(const char* c);
	void searchByOIB();
};

#endif // !PER_H
