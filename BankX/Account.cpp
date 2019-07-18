#include"Account.h"
#include"Xclass.h"
#include"Person.h"

//enter data for new account
void Account::createAccount() {
	Person p;
	ManagerAcc m;
	std::cout << "Enter account number: ";
	std::cin >> accountNo;
	m.checkAcc(accountNo)? NULL : throw XaccNo();
	if(m.checkIfExists(accountNo)) throw Xexists();
	std::cout << "Enter OIB: ";
	std::cin >> oib;
	m.checkOib(oib) ? NULL : throw Xoib();
	p.checkCust(oib) ? NULL : throw Xcust();
	std::cout << "Enter balance: ";
	std::cin >> balance;
	status = true;
	std::cout << std::endl;
}

//print format for accounts
void Account::allPrint() {
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

//check if account number is consistent with format
bool ManagerAcc::checkAcc(const char* c) {
	int i = 0;
	if(isalpha(c[0]) || isalpha(c[1]))
		while (*c != '\0') { ++c; ++i; }
	return i == 21;
}
//check if oib number is consistent with format
bool ManagerAcc::checkOib(const char* c) {
	int i = 0;
	while (*c != '\0') { ++c; ++i; }
	return i == 11;
}
//check if acc. number already exists
bool ManagerAcc::checkIfExists(const char* n) {
	std::ifstream f;
	Account t;
	f.open("records.bank", std::ios::binary);
	if (!f)	throw Xfile();
	while (!f.eof()) {
		if (f.read(reinterpret_cast<char*>(&t), sizeof(t)) )
		{
			if (!strcmp(t.getAccNo(), n)) return true;
		}
	}
	f.close();
	return false;
}
//0 print all accounts |c print specific accounts
void ManagerAcc::allAccounts(const char* c) {
	std::ifstream f;
	Account t;
	f.open("records.bank", std::ios::binary);
	if (!f)	throw Xfile();
	std::cout << std::setw(18) << std::setfill(' ') << "Account number" <<
		std::setw(10) << std::setfill(' ') << "OIB" <<
		std::setw(23) << std::setfill(' ') << "\tBalance" << std::endl;
	std::cout << std::string(80, '-') << std::endl;
	if (c == 0) {
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				t.allPrint();
		}
	}
	else {
		Person p;
		p.printName(c);
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				if(!strcmp(c,t.getoib()))
					t.allPrint();
		}
		std::cout << "Owner: " << p << std::endl;
	}
	f.close();
}

//search for specific accounts
void ManagerAcc::searchByOIB() {
	char c[12];
	std::cout << "Enter OIB: ";
	std::cin >> c; 
	checkOib(c)? NULL:throw Xoib();
	allAccounts(c);
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