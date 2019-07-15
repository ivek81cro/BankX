#include<iostream>
#include<string>
#include<iomanip>
#include"Account.h"
#include"Person.h"

int main() {
	std::cout << std::setw(40) << std::setfill('*') << "Account system"
		<< std::setw(40) << std::setfill('*') << "" << std::endl;
	std::cout << "Select your choice" << std::endl;
	int c;
	std::cout << "1. New account" << std::endl;
	std::cout << "2. New person" << std::endl;
	std::cout << "3. Print all accounts" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cout << "\nSelection: ";
	while (std::cin >> c) {
		switch (c)
		{
		case 1:
			newAccount();
			break;
		case 2:
			newPerson();
			break;
		case 3:
			allAccounts();
			break;
		case 4:
			exit(0);
			break;
		default:
			std::cout << "Select one of existing choice! ";
			break;
		}
		std::cout << "\nSelection: ";
	}

}