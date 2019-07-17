#include"Menu.h"
#include"Account.h"
#include"Person.h"
#include"Transaction.h"

//clear screen function
void Menu::clrscr(){
	std::cout << "\033[2J\033[1;1H"; //clear screen, win linux
}
//Main menu
void Menu::mainMenu() {
	std::cout << std::setw(40) << std::setfill('*') << "Account system"
		<< std::setw(40) << std::setfill('*') << "" << std::endl;
	std::cout << "Select your choice" << std::endl;
	int c;
	std::cout << "1. Accounts" << std::endl;
	std::cout << "2. Customers" << std::endl;
	std::cout << "3. Transactions" << std::endl;
	std::cout << "9. Exit" << std::endl;
	std::cout << "\nSelection: ";
	Transaction t;
	while (std::cin >> c) {
		switch (c)
		{
		case 1:
			Menu::accountMenu();
			break;
		case 2:
			Menu::customerMenu();
			break;
		case 3:
			t.allTransact(0);
			break;
		case 9:
			exit(0);
			break;
		default:
			std::cout << "Select one of existing choice! ";
			break;
		}
		std::cout << "\nSelection: ";
	}
}
//account menu
void Menu::accountMenu() {
	Menu::clrscr();
	std::cout << std::setw(40) << std::setfill('*') << "Account management"
		<< std::setw(40) << std::setfill('*') << "" << std::endl;
	std::cout << "Select your choice" << std::endl;
	int c;
	std::cout << "1. New account" << std::endl;
	std::cout << "2. All accounts" << std::endl;
	std::cout << "3. Search for accounts owned by OIB" << std::endl;
	std::cout << "4. Deposit" << std::endl;
	std::cout << "5. Withdraw" << std::endl;
	std::cout << "6. Transfer" << std::endl;
	std::cout << "9. Back to main menu" << std::endl;
	std::cout << "\nSelection: ";
	while (std::cin >> c) {
		ManagerAcc m;
		Transaction t;
		switch (c)
		{
		case 1:
			m.newAccount();
			break;
		case 2:
			m.allAccounts(0);
			break;
		case 3:
			m.searchAcc();
			break;
		case 4:
			t.deposit();
			break;
		case 9:
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

void Menu::customerMenu() {
	Menu::clrscr();
	std::cout << std::setw(40) << std::setfill('*') << "Account management"
		<< std::setw(40) << std::setfill('*') << "" << std::endl;
	std::cout << "Select your choice" << std::endl;
	int c;
	std::cout << "1. New customer" << std::endl;
	std::cout << "2. All customers" << std::endl;
	std::cout << "3. Search for customer by OIB" << std::endl;
	std::cout << "9. Back to main menu" << std::endl;
	std::cout << "\nSelection: ";
	while (std::cin >> c) {
		ManagerPers p;
		switch (c)
		{
		case 1:
			p.newPerson();
			break;
		case 2:
			p.allPersons(0);
			break;
		case 3:
			p.searchPerson();
			break;
		case 9:
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