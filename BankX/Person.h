#ifndef PER_H
#define PER_H
#include<iostream>

class Person {
	char name[20], surname[35], oib[12];
public:
	Person() {}
	~Person() {}
	void createPerson();
	char* getOib(){ return oib; }
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
};

void newPerson();
void savePerson(Person* p);
bool checkCust(const char* n);
Person& printName(const char* n, Person& p);

#endif // !PER_H
