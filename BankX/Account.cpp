#include"Account.h"
#include"Xclass.h"

void Account::createAccount() {
	std::cout << "Enter account number: ";
	std::cin >> accountNo;
	if(checkIfExists(accountNo)) throw Xexists();
	std::cout << "Enter OIB: ";
	std::cin >> oib;
	std::cout << "Enter balance: ";
	std::cin >> balance;
	status = true;
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
	std::cout << std::setw(18) << std::setfill(' ') << "Account number" <<
		std::setw(10) << std::setfill(' ') << "OIB" <<
		std::setw(23) << std::setfill(' ') << "\tBalance" << std::endl;
	while (!f.eof()) {
		if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
		{
			t.allPrint();
		}
	}
	f.close();
}

void Account::allPrint() {
	std::cout << accountNo << '\t' << oib << '\t' << std::setw(15)
		<< std::setprecision(2) << std::fixed << balance << "\t\tStatus:" <<
		(status ? " Open " : "Closed") << std::endl;
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