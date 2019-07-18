#include"Transaction.h"
#include"Xclass.h"
#include"Account.h"
#include"Person.h"

void Transaction::deposit() {
	try {
		Transaction::depositC();
	}
	catch (X& x) {
		x.errorx();
	}
}
//Deposit - cash
void Transaction::depositC()
{
	ManagerAcc rec;
	char c[22];
	std::cout << "Enter receiving account number: ";
	std::cin >> c;
	rec.checkAcc(c) ? NULL : throw XaccNo();
	rec.checkIfExists(c);
	Account ac = rec.returnAccount(c);
	std::cout << "Enter ammount you want to deposit: ";
	double amm;
	std::cin >> amm;
	amm < 0 ? throw XwrongAmm() : NULL;
	Transaction t(ac, amm, 'c');
	t.saveTrans();
	ac.addBalance(amm);
	ac.saveAccount();//append new balance to records
	std::cout<<"Currnent balance: " << ac.getBalance();
}
//save record of transaction
void Transaction::saveTrans() {
	std::ofstream f;
	f.open("transact.bank", std::ios::binary | std::ios::app);
	if (!f)	throw Xfile();
	f.write(reinterpret_cast<char*>(this), sizeof(*this));
	f.close();
}
//print all (0) | (oib) specific oib transactions
void Transaction::allTransact(const char* c) {
	std::ifstream f;
	Transaction t;
	f.open("transact.bank", std::ios::binary);
	if (!f)	throw Xfile();
	std::cout << "Date\t\t\t" << "To account" 
		<< '\t' << '\t' << '\t' << "Type" << "\tAmmount transfered" << std::endl;
	std::cout << std::string(80, '-') << std::endl;
	if (c == 0) {
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				std::cout << t;
		}
	}
	else {
		Person p;
		ManagerPers m;
		m.printName(c, p);
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				if (!strcmp(c, t.acc.getoib()))
					std::cout << t;
		}
		std::cout << "Owner: " << p << std::endl;
	}
	f.close();
}
//print format for transaction records
std::ostream& operator<<(std::ostream& os, const Transaction& t) {
	return os << t.dat << '\t' << t.acc << '\t' << '\t' << t.type << '\t' << t.ammount << std::endl;
}

std::string Transaction::return_current_time_and_date()
{
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%d/%m/%Y %X");
	return ss.str();
}
