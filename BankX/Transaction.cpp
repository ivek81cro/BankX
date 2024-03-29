#include"Transaction.h"
#include"Xclass.h"
#include"Deposit.h"
#include"Withdraw.h"
#include"Person.h"
#include"Tools.h"
#include<fstream>

//set transaction time to system time now
std::string Transaction::return_current_time_and_date(){
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream ss;
	ss << std::put_time(std::localtime(&in_time_t), "%d/%m/%Y %X");
	return ss.str();
}

void Transaction::allTransact(char* c) {
	std::ifstream f, fp;
	Deposit t;
	f.open("deposit.bank", std::ios::binary);
	if (!f)	throw Xfile();
	std::cout << std::setw(25) << std::left << std::setfill(' ') << "Date" <<
		std::setw(30) << std::left << std::setfill(' ') << "To/from account" <<
		std::setw(5) << std::left << std::setfill(' ') << "Type" <<
		std::setw(25) << std::setfill(' ') << std::right << "Ammount transfered" << std::endl;
	std::cout << std::string(100, '-') << std::endl;
	if (c == 0) {
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				std::cout << t << std::endl;
		}
	}
	else {
		while (!f.eof()) {
			if (f.read(reinterpret_cast<char*>(&t), sizeof(t)))
				if (!strcmp(c, t.getAcc().getoib()))
					std::cout << t << std::endl;
		}
		fp.open("person.bank", std::ios::binary);
		Person p;
		while (!fp.eof()) {
			if (fp.read(reinterpret_cast<char*>(&p), sizeof(p)));
			if (!strcmp(p.getOib(), c)) break;
		}
		fp.close();
		std::cout << "Account owner: ";
		std::cout << p << std::endl;
	}
	f.close();
}

void Transaction::specificTr() {
	Toolbox v;
	std::cout << "Enter OIB: ";
	char c[12];
	std::cin >> c;
	v.checkElem(c, "o") ? NULL : throw Xoib();
	allTransact(c);
}