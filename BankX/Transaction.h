#ifndef TRAN_H
#define TRAN_H
#include"Account.h"
#include<chrono>
#include<ctime>
#include<string>
#include<sstream>
#include<iomanip>

class Transaction {
	Account acc;
	char type;
	double ammount;
	char dat[20];	
public:
	Transaction(){}
	Transaction(Account ac, double am, char t ):acc(ac),ammount(am), type(t){
		std::string s;
		s = return_current_time_and_date();
		strcpy(dat, s.c_str());
	}
	~Transaction(){}
	void deposit();
	void depositC();
	void saveTrans();
	void allTransact(const char* c);
	friend std::ostream& operator<<(std::ostream& os, const Transaction& t);
	std::string return_current_time_and_date();
};

#endif // !TRAN_H
