#include"Account.h"
#include"Xclass.h"
#include<fstream>

void Account::createAccount() {
	std::cout << "Enter account number: ";
	std::cin >> accountNo;
	if(checkIfExists(accountNo)) throw Xexists();
	std::cout << "Enter OIB: ";
	std::cin >> oib;
	std::cout << "Enter balance: ";
	std::cin >> balance;
	std::cout << std::endl;
}

bool checkIfExists(const char* n) {
	std::ifstream f;
	Account t;
	f.open("records.bank", std::ios::binary);
	while (!f.eof()) {
		if (f.read(reinterpret_cast<char*>(&t), sizeof(t)) )
		{
			if (!strcmp(t.getAccNo(), n)) return true;
		}
	}
	f.close();
	return false;
}
void allAccounts() {
	std::ifstream f;
	Account t;
	f.open("records.bank", std::ios::binary);
	while (!f.eof()) {
		if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
		{
			t.allPrint();
		}
	}
	f.close();
}

void Account::allPrint() { 
	std::cout << accountNo << ' ' << oib << ' ' << balance << std::endl; 
}

void Account::saveAccount() {
	std::ofstream f;
	f.open("records.bank", std::ios::binary|std::ios::app);
	if (!f) {
		std::cout << "Could not open file."; return;
	}
	f.write(reinterpret_cast<char*>(this), sizeof(*this));
	f.close();

}

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