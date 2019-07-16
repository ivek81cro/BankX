#include"Menu.h"
#include"Account.h"
#include"Person.h"

void clrscr(){
	std::cout << "\033[2J\033[1;1H"; //clear screen, win linux
}

void mainMenu() {
	std::cout << std::setw(40) << std::setfill('*') << "Account system"
		<< std::setw(40) << std::setfill('*') << "" << std::endl;
	std::cout << "Select your choice" << std::endl;
	int c;
	std::cout << "1. Accounts" << std::endl;
	std::cout << "2. Customers" << std::endl;
	std::cout << "3. Transactions" << std::endl;
	std::cout << "4. Exit" << std::endl;
	std::cout << "\nSelection: ";
	while (std::cin >> c) {
		switch (c)
		{
		case 1:
			accountMenu();
			break;
		case 2:
			newPerson();
			break;
		case 3:
			;
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

void accountMenu() {
	clrscr();
	std::cout << std::setw(40) << std::setfill('*') << "Account management"
		<< std::setw(40) << std::setfill('*') << "" << std::endl;
	std::cout << "Select your choice" << std::endl;
	int c;
	std::cout << "1. New account" << std::endl;
	std::cout << "2. All accounts" << std::endl;
	std::cout << "3. Search for accounts owned by OIB" << std::endl;
	std::cout << "4. Back to main menu" << std::endl;
	std::cout << "\nSelection: ";
	while (std::cin >> c) {
		switch (c)
		{
		case 1:
			newAccount();
			break;
		case 2:
			allAccounts(0);
			break;
		case 3:
			searchByOIB();
			break;
		case 4:
			clrscr();
			mainMenu();
			break;
		default:
			std::cout << "Select one of existing choice! ";
			break;
		}
		std::cout << "\nSelection: ";
	}
}