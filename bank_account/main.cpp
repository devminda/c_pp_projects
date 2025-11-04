// bank_account.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "bank_account.h"

int main()
{
    std::cout << "Application Started"<<std::endl;
	BankAccount account0;
	account0.print_account_info();

	std::cout << "------------------" << std::endl;
	BankAccount account1("Alice", 1000.0);
	account1.print_account_info();
	std::cout << "------------------" << std::endl;
	account1.deposit(500.0);
	account1.print_account_info();
	account1.deposit(300.0);
	account1.print_account_info();
	account1.withdraw(200.0);
	account1.print_account_info();
	std::cout << "------------------" << std::endl;
	account1.setOwnerName("Bob");
	account1.setHistoryCapacity(20);
	account1.print_account_info();
	std::cout << "------------------" << std::endl;

	std::cout << "Application Finished" << std::endl;

	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
