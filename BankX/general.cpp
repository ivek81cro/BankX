#include"general.h"
#include"Account.h"
#include"Xclass.h"

//returns account for balance update, deletes old record
Account returnAccount(const char* c) {
	std::fstream f("records.bank", std::ios::in | std::ios::binary);
	std::fstream of("temp.bank", std::ios::out | std::ios::binary);
	Account t, n;
	while (!f.eof()) {
		if (f.read(reinterpret_cast<char*>(&t), sizeof(t))) {
			if (!strcmp(c, t.getAccNo())) {
				n = t; continue;
			}
			of.write(reinterpret_cast<char*>(&t), sizeof(t));
		}
	}
	f.close();
	of.close();
	remove("records.bank");
	rename("temp.bank", "records.bank");
	return n;
}
//open new account
void newAccount() {
	Account acc;
	try {
		acc.createAccount();
		acc.saveAccount();
	}
	catch (X& x) {
		x.errorx();
	}
}
//search for specific accounts
void searchAcc() {
	try {
		searchByOIB();
	}
	catch (X& x) {
		x.errorx();
	}

}
//search for specific accounts
void searchByOIB() {
	Account a;
	char c[12];
	std::cout << "Enter OIB: ";
	std::cin >> c;
	checkOib(c) ? NULL : throw Xoib();
	a.allAccounts(c);
}

//check if oib number is consistent with format
bool checkOib(const char* c) {
	int i = 0;
	while (*c != '\0') { ++c; ++i; }
	return i == 11;
}