#ifndef GEN_H
#define GEN_H
#include"Account.h"

void newAccount();
void searchAcc();
void searchByOIB();
Account returnAccount(const char* c);
bool checkOib(const char* c);

#endif // !GEN_H


