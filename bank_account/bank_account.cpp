#include "bank_account.h"


BankAccount::BankAccount() {
	owner_name = "Mat";
	current_balance = 0.0;
	history_capacity = 10;
	size = 0;
	history = new double[history_capacity];
}

BankAccount::BankAccount(std::string name, double initial_balance) {
	owner_name = name;
	current_balance = initial_balance;
	history_capacity = 2;
	size = 0;
	history = new double[history_capacity];
}

std::string BankAccount::getOwnerName() const {
	return owner_name;
}

double BankAccount::getCurrentBalance() const {
	return current_balance;
}

std::string BankAccount::getTransactionHistory() const {
	std::string result = "";
	for (int i = 0; i < size; i++) {
		result += std::to_string(history[i]) + " ";
	}
	return result;
	
}

void BankAccount::setOwnerName(std::string name) {
	owner_name = name;
}

void BankAccount::setHistoryCapacity(int amount) {
	if (amount > history_capacity) {
		double* new_history = new double[amount];
		for (int i = 0; i < size; i++) {
			new_history[i] = history[i];
		}
		delete[] history;
		history = new_history;
		history_capacity = amount;
	}
}

void BankAccount::print_account_info() const {
	std::cout << "Owner: " << owner_name << std::endl;
	std::cout << "Current Balance: " << current_balance << std::endl;
	std::cout << "Transaction History: "<< std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << history[i] << std::endl;
	}
	std::cout << std::endl;
}
void BankAccount::deposit(double amount) {
	if (amount > 0) {
		current_balance += amount;
		if (size >= history_capacity) {
			setHistoryCapacity(history_capacity * 2);
		}
		history[size] = amount;
		size++;
	}
	else {
		std::cout << "Deposit amount must be positive." << std::endl;
	}
}

void BankAccount::withdraw(double amount) {
	if (amount > 0 && amount <= current_balance) {
		current_balance -= amount;
		if (size >= history_capacity) {
			setHistoryCapacity(history_capacity * 2);
		}
		history[size] = -amount;
		size++;
	}
	else {
		std::cout << "Invalid withdraw amount." << std::endl;
	}
}

BankAccount::~BankAccount() {
	delete[] history;
}