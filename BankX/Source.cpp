#include<iostream>
#include<string>
#include<iomanip>

class Account {
	int accountNo; 
	char oib[11];
	float balance;
public:
	Account(){}
	void createAccount(Account& acc);
};

class Person {
	std::string name, surname;
	char oib[11];
public:
	Person(){}
	void createPerson(Person& pers);
};

void Account::createAccount(Account& acc) {
	std::cout << "Enter account number: ";
	std::cin >> acc.accountNo;
	std::cout << "Enter OIB: ";
	std::cin >> acc.oib;
	std::cout << "Enter Balance: ";
	std::cin >> acc.balance;
}

void newAccount(){
	Account acc;
	acc.createAccount(acc);
}
void Person::createPerson(Person& per) {
	std::cout << "Enter name: ";
	std::cin >> per.name;
	std::cout << "Enter ºurname: ";
	std::cin >> per.surname;
	std::cout << "Enter OIB: ";
	std::cin >> per.oib;
}

void newPerson(){
	Person per;
	
}

int main() {
	std::cout << std::setw(40) << std::setfill('*') << "Account system"
		<< std::setw(40) << std::setfill('*') << "" << std::endl;
	std::cout << "Select your choice" << std::endl;
	int c;
	std::cout << "1. New account" << std::endl;
	std::cout << "2. New person" << std::endl;
	std::cout << "\nSelection: "; std::cin >> c;
	switch (c)
	{
	case 1:
		newAccount();
		break;
	case 2:
		newPerson();
		break;
	default:
		std::cout << "Select one of existing choice!";
		exit(0);
		break;
	}

}