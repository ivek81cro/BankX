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
	void errorx() { std::cout << "That account number exists, pick a nother one."; }
};

#endif // !XCL_H
