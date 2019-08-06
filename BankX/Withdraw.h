#ifndef WIT_H
#define WIT_H
#include"Transaction.h"
#include"Account.h"


class Withdraw : public Transaction {
	Account acc;
	char type;
public:
	Withdraw() {}
	Withdraw(Account ac, char t, double am=0) :acc(ac), type(t) { ammount = am; }
	void withdraw();
	~Withdraw() {}
	void withdrawC();
	void withdrawC(const char* acNo, const double &amm);
	void saveTrans();
	void specificTr();
};

#endif // !WIT_H