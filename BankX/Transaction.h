#ifndef TR_H
#define TR_H
#include<chrono>
#include<ctime>
#include<string>
#include<sstream>
#include<iomanip>

class Transaction {
protected:
	char dateT[20];
	double ammount;
public:
	Transaction(){
		std::string s;
		s = return_current_time_and_date();
		strcpy(dateT, s.c_str());
	}
	~Transaction() {}
	std::string return_current_time_and_date();
	void allTransact(char* c);
	void specificTr();
};

#endif // !TR_H