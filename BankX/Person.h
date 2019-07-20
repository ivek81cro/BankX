#ifndef PER_H
#define PER_H
#include<iostream>

class ManagerPers {
public:
	ManagerPers() {};
	~ManagerPers() {};
	void newPerson();
	void savePerson();	
	void searchPerson();
	void searchByOIB();
};

class Person : public ManagerPers {
	char name[20], surname[35], oib[12];
public:
	Person() {}
	~Person() {}
	void createPerson();
	char* getOib(){ return oib; }
	void printName(const char* n);
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

#endif // !PER_H
