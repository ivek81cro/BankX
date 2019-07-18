#ifndef DEP_H
#define DEP_H
#include"Transaction.h"
#include"Account.h"


class Deposit : public Transaction, public ManagerAcc{
	Account acc;
	char type;	
public:
	Deposit(){}
	Deposit(Account ac, char t, double am) :acc(ac), type(t) { ammount = am; }
	~Deposit(){}
	void deposit();
	void depositC();
	void saveTrans();
	void allTransact(const char* c);
	friend std::ostream& operator<<(std::ostream& os, const Deposit& t);
	void specificTr();
};

#endif // !DEP_H
