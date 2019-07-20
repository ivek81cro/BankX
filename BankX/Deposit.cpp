#include"Deposit.h"
#include"Xclass.h"
#include"Person.h"
#include"Tools.h"

void Deposit::deposit() {
	try {
		Deposit::depositC();
	}
	catch (X& x) {
		x.errorx();
	}
}
//Deposit - cash
void Deposit::depositC(){
	Toolbox v;
	ManagerAcc rec;
	char c[22];
	std::cout << "Enter receiving account number: ";
	std::cin >> c;
	v.checkElem(c,"a") ? NULL : throw XaccNo();
	v.checkIfExists(c);
	Account ac = rec.returnAccount(c);
	std::cout << "Enter ammount you want to deposit: ";
	double amm;
	std::cin >> amm;
	amm < 0 ? throw XwrongAmm() : NULL;
	Deposit t(ac, 'c',amm);
	t.saveTrans();
	ac.addBalance(amm);
	ac.saveAccount();//append new balance to records
	std::cout<<"Currnent balance: " << ac.getBalance();
}

void Deposit::specificTr() {
	Toolbox v;
	std::cout << "Enter OIB: ";
	char c[12];
	std::cin >> c;
	v.checkElem(c,"o") ?  NULL : throw Xoib();
	allTransact(c);
}
//save record of Deposit
void Deposit::saveTrans() {
	std::ofstream f;
	f.open("deposit.bank", std::ios::binary | std::ios::app);
	if (!f)	throw Xfile();
	f.write(reinterpret_cast<char*>(this), sizeof(*this));
	f.close();
}
//print all (0) | (oib) specific oib Deposits
void Deposit::allTransact(char* c) {
	std::ifstream f;
	Deposit t;
	f.open("deposit.bank", std::ios::binary);
	if (!f)	throw Xfile();
	std::cout << std::setw(25) << std::left << std::setfill(' ') << "Date" <<
		std::setw(30) << std::left << std::setfill(' ') << "To account" <<
		std::setw(5) << std::left << std::setfill(' ') << "Type" <<
		std::setw(25) << std::setfill(' ') << std::right << "Ammount transfered" << std::endl;
	std::cout << std::string(100, '-') << std::endl;
	if (c == 0) {
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				std::cout << t;
		}
	}
	else {
		Person p;
		Toolbox v;
		p.printName(c);
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				if (!strcmp(c, t.acc.getoib()))
					std::cout << t;
		}
		if(v.checkElem(c,"p"))
			std::cout << "Owner: " << p << std::endl;
	}
	f.close();
}
//print format for Deposit records
std::ostream& operator<<(std::ostream& os, const Deposit& t) {
	return os << std::setw(25) << std::left << std::setfill(' ') << t.dateT <<
		std::setw(30) << std::left << std::setfill(' ') << t.acc <<
		std::setw(5) << std::left << std::setfill(' ') << t.type <<
		std::setw(25) << std::setfill(' ') << std::right << std::setprecision(2) <<
		std::fixed << t.ammount << std::endl;
}
