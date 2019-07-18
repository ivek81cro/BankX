#include<iostream>
#include<string>
#include <windows.h>
#include"Account.h"
#include"Person.h"
#include"Menu.h"

int main() {

	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 800, 400, TRUE);

	Menu m;
	m.mainMenu();

}