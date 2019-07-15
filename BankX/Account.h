#ifndef ACC_H
#define ACC_H
#include<iostream>

class Account {
	char accountNo[19], oib[11];
	float balance;
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