#ifndef DEP_H
#define DEP_H
#include"Transaction.h"
#include"Account.h"


class Deposit : public Transaction{
	Account acc;
	char type;
public:
	Deposit(){}
	Deposit(Account ac, char t, double am=0) :acc(ac), type(t) { ammount = am; }
	~Deposit(){}
	Account getAcc() { return acc; }
	void deposit();
	void depositC();
	void depositC(const char* acNo, const double &amm);
	friend std::ostream& operator<<(std::ostream& os, const Deposit& t);
	void saveTrans();
};

#endif // !DEP_H
