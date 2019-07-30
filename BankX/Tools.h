#ifndef CHK_H
#define CHK_H
#include"Account.h"


class Toolbox {
public:	
	bool checkElem(char* c, const char* n);
	bool checkIfExists(char* n);
	void allPerson(const char* c);
	void allAccounts(const char* c);
	bool checkBalance(const Account ac, const double amm);
};

#endif // !CHK_H
