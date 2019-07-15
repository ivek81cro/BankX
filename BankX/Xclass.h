#ifndef XCL_H
#define XCL_H
#include<string>
#include<iostream>

class X {
public:
	virtual void errorx() = 0;
};

class Xexists :public X {
public:
	void errorx() { std::cout << "\nThat account number exists, pick a nother one.\n"; }
};

#endif // !XCL_H
