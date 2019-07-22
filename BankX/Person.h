#ifndef PER_H
#define PER_H
#include<iostream>

class ManagerPers {
public:
	ManagerPers() {};
	~ManagerPers() {};
	void newPerson();
		
	void searchPerson();
	void searchByOIB();
};

class Person : public ManagerPers {
	char name[20], surname[35], oib[12];
public:
	Person() {}
	~Person() {}
	void createPerson();
	void savePerson();
	char* getOib(){ return oib; }
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

#endif // !PER_H
