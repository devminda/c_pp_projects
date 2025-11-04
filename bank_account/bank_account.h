#ifndef BANK_ACCOUNT_H
#include <iostream>
#include <string>

class BankAccount {
private:
	double current_balance;
	std::string owner_name;
	double* history;
	int size;
	int history_capacity;

public:
	//Constructor
	//Default Constructor
	BankAccount();

	//Constructor with parameters
	BankAccount(std::string name, double initial_balance);

	//Getter
	std::string getOwnerName() const;
	double getCurrentBalance() const;
	std::string getTransactionHistory() const;
	//Setter
	void setOwnerName(std::string name);
	void setHistoryCapacity(int amount);

	//Auxiliary methods
	void print_account_info() const;
	void deposit(double amount);
	void withdraw(double amount);
	//Destructor
	~BankAccount();
};

#endif