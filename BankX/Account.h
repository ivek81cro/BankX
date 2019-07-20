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
	double getBalance() { return balance; }
	void createAccount();
	void saveAccount();
	void allPerson();
	char* getoib() { return oib; }
	void addBalance(double n) { balance += n; };
	friend std::ostream& operator<<(std::ostream& os, const Account& a);
};
class ManagerAcc {
public:
	void newAccount();
	void searchByOIB();
	void searchAcc();
	Account returnAccount(const char* c);
};

#endif