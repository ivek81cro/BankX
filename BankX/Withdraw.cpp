#include"Withdraw.h"
#include"Xclass.h"
#include"Person.h"
#include"Tools.h"

void Withdraw::withdraw() {
	try {
		Withdraw::withdrawC();
	}
	catch (X& x) {
		x.errorx();
	}
}
//Withdraw - cash
void Withdraw::withdrawC() {
	Toolbox v;
	ManagerAcc rec;
	char c[22];
	std::cout << "Enter account number: ";
	std::cin >> c;
	v.checkElem(c, "a") ? NULL : throw XaccNo();
	v.checkIfExists(c);
	std::cout << "Enter ammount you want to withdraw: ";
	double amm;
	std::cin >> amm;
	amm < 0 ? throw XwrongAmm() : NULL;
	Account ac = rec.updateBalance(c, amm,'w');
	Withdraw w(ac, 'w', amm);
	w.saveTrans();
}

void Withdraw::saveTrans() {
	std::ofstream f;
	f.open("deposit.bank", std::ios::binary | std::ios::app);
	if (!f)	throw Xfile();
	f.write(reinterpret_cast<char*>(this), sizeof(*this));
	f.close();
}

void Withdraw::specificTr() {
	Toolbox v;
	std::cout << "Enter OIB: ";
	char c[12];
	std::cin >> c;
	v.checkElem(c, "o") ? NULL : throw Xoib();
	allTransact(c);
}