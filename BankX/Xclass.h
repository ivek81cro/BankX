#ifndef XCL_H
#define XCL_H
#include<string>
#include<iostream>

class X {
public:
	virtual void errorx() = 0;
};

class Xfile :public X {
public:
	void errorx() { std::cout << "\nCan't open file, check if exists.\n"; }
};

class Xexists :public X {
public:
	void errorx() { std::cout << "\nThat account number doesn't exist/is closed, pick a nother one.\n"; }
};

class Xoib :public X {
public:
	void errorx() { std::cout << "\nWrong OIB number.\n"; }
};

class XaccNo :public X {
public:
	void errorx() { std::cout << "\nWrong account number(IBAN).\n"; }
};

class Xcust :public X {
public:
	void errorx() { std::cout << "\nThat customer doesn't exist, please enter customer data first.\n"; }
};

class XwrongAmm :public X {
public:
	void errorx() { std::cout << "\nDeposit can't be less than zero.\n"; }
};

class XchBal :public X {
public:
	void errorx() { std::cout << "\nNot enough money.\n"; }
};

#endif // !XCL_H
