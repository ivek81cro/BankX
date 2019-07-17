#ifndef TRAN_H
#define TRAN_H
#pragma warning(disable : 4996)
#include"Account.h"
#include<chrono>

struct date {
	char time[20];// dd/mm/yyyy hh:mm:ss
	date(const char* c) { strcpy(time, c); }
	date(){}
	friend std::ostream& operator<<(std::ostream& os, const date& d) {
		return os << d.time << ' ';
	}
};

class Transaction {
	Account acc;
	char type;
	double ammount;
	date dat;	
public:
	Transaction(){}
	Transaction(Account ac, double am, char t, date da ):acc(ac),ammount(am),dat(da), type(t){}
	~Transaction(){}
	void deposit();
	void depositC();
	void saveTrans();
	void allTransact(const char* c);
	friend std::ostream& operator<<(std::ostream& os, const Transaction& t);
};

#endif // !TRAN_H
