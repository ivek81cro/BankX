#include"Account.h"
#include"Xclass.h"
#include"Person.h"
#include"Tools.h"

//enter data for new account
void Account::createAccount() {
	std::cout << "Enter account number: ";
	std::cin >> accountNo;
	Toolbox v;
	v.checkElem(accountNo,"a")? NULL : throw XaccNo();
	if(v.checkIfExists(accountNo)) throw Xexists();
	std::cout << "Enter OIB: ";
	std::cin >> oib;
	v.checkElem(oib,"o") ? NULL : throw Xoib();
	v.checkElem(oib,"o") ? NULL : throw Xcust();
	std::cout << "Enter balance: ";
	std::cin >> balance;
	status = true;
	std::cout << std::endl;
}

//print format for accounts
void Account::allPerson() {
	std::cout << accountNo << '\t' << oib << '\t' << std::setw(15)
		<< std::setprecision(2) << std::fixed << balance << "\t\tStatus:" <<
		(status ? " Open " : "Closed") << std::endl;
}

//save account
void Account::saveAccount() {
	std::ofstream f;
	f.open("records.bank", std::ios::binary | std::ios::app);
	if (!f)	throw Xfile();
	f.write(reinterpret_cast<char*>(this), sizeof(*this));
	f.close();

}
//print for acc.no.
std::ostream& operator<<(std::ostream& os, const Account& a) {
	return os << a.accountNo;
}

//search for specific accounts
void ManagerAcc::searchByOIB() {
	Toolbox v;
	char c[12];
	std::cout << "Enter OIB: ";
	std::cin >> c; 
	v.checkElem(c,"o")? NULL:throw Xoib();
	v.allAccounts(c);
}
//returns account for balance update, deletes old record
Account ManagerAcc::returnAccount(const char* c) {
	std::fstream f("records.bank", std::ios::in | std::ios::binary);
	std::fstream of("temp.bank", std::ios::out | std::ios::binary);
	Account t,n;
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
void ManagerAcc::newAccount() {
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
void ManagerAcc::searchAcc() {
	try {
		ManagerAcc::searchByOIB();
	}
	catch (X& x) {
		x.errorx();
	}

}