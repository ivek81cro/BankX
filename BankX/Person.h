#ifndef PER_H
#define PER_H
#include<iostream>

class Person {
	char name[20], surname[35], oib[12];
public:
	Person() {}
	~Person() { std::cout << "Pers destr"; }
	void createPerson(Person& pers);
};

void newPerson();

#endif // !PER_H
