#ifndef ACC_H
#define ACC_H
#include<iostream>
#include<fstream>
#include<iomanip>

class Account {
	char accountNo[22], oib[12];
	bool status;
	double balance;
public:
	Account() {}
	~Account() { std::cout << "Acc destr"; }
	char* getAccNo() { return accountNo; }
	void createAccount();
	void saveAccount();
	void allPrint();
};
bool checkIfExists(const char* n);
void newAccount();
void allAccounts();

#endif