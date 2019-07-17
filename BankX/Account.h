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
	~Account() {}
	char* getAccNo() { return accountNo; }
	void createAccount();
	void saveAccount();
	void allPrint();
	char* getoib() { return oib; }
};
class ManagerAcc {
public:
	bool checkIfExists(const char* n);
	void newAccount();
	void allAccounts(const char* c);
	bool checkOib(const char* c);
	bool checkAcc(const char* c);
	void searchByOIB();
	void searchAcc();
};

#endif