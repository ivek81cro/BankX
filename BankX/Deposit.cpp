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
	v.checkElem(c, "a") ? NULL : throw XaccNo();
	v.checkIfExists(c);	
	std::cout << "Enter ammount you want to deposit: ";
	double amm;
	std::cin >> amm;
	amm < 0 ? throw XwrongAmm() : NULL;
	Account ac = rec.updateBalance(c, amm, 'd');
	Deposit t(ac, 'd',amm);
	t.saveTrans();
}

void Deposit::saveTrans() {
	std::ofstream f;
	f.open("deposit.bank", std::ios::binary | std::ios::app);
	if (!f)	throw Xfile();
	f.write(reinterpret_cast<char*>(this), sizeof(*this));
	f.close();
}

void Deposit::specificTr() {
	Toolbox v;
	std::cout << "Enter OIB: ";
	char c[12];
	std::cin >> c;
	v.checkElem(c,"o") ?  NULL : throw Xoib();
	allTransact(c);
}

//print format for Deposit records - used for withrawal allso
std::ostream& operator<<(std::ostream& os, const Deposit& t) {
	return os << std::setw(25) << std::left << std::setfill(' ') << t.dateT <<
		std::setw(30) << std::left << std::setfill(' ') << t.acc <<
		std::setw(5) << std::left << std::setfill(' ') << t.type <<
		std::setw(25) << std::setfill(' ') << std::right << std::setprecision(2) <<
		std::fixed << t.ammount;
}
