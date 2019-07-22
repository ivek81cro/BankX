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
	~Withdraw() {}
	void withdraw();
	void withdrawC();
	void saveTrans();
	void specificTr();
};

#endif // !WIT_H