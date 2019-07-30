#ifndef TRAN_H
#define TRAN_H
#include"Transaction.h"
#include"Account.h"
#include"Withdraw.h"
#include"Deposit.h"

class Transfer{
public:
	Transfer();
	~Transfer(){}
	void transfer();
};

#endif // !TRAN_H