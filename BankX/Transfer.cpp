#include "Transfer.h"
#include"Tools.h"
#include"Xclass.h"

Transfer::Transfer() {
	try {
		Transfer::transfer();
	}
	catch (X& x) {
		x.errorx();
	}
}

void Transfer::transfer(){
	char payerac[22], payeeac[22];
	double amm;
	Toolbox t;
	std::cout << "Enter payer's account number: ";
	std::cin >> payerac;
	t.checkElem(payerac, "a") ? NULL : throw XaccNo();
	t.checkIfExists(payerac) ? NULL : throw Xexists();
	std::cout << "Enter payee account number: ";
	std::cin >> payeeac;
	t.checkElem(payeeac, "a") ? NULL : throw XaccNo();	
	t.checkIfExists(payeeac) ? NULL : throw Xexists();
	std::cout << "Enter ammount: ";
	std::cin >> amm;
	Withdraw w; 
	w.withdrawC(payerac, amm);
	Deposit d;
	d.depositC(payeeac, amm);
}