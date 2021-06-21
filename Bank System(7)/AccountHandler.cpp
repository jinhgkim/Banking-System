#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDec1.h"

AccountHandler::AccountHandler() {}
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < numOfAccounts; i++)
		delete accountArray[i];
}
void AccountHandler::displayMenu() const
{
	cout << "----- Menu -----" << endl;
	cout << "1. Open a new bank account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. View account info" << endl;
	cout << "5. Exit the program" << endl;
	cout << endl;
}
void AccountHandler::newBankAccount()
{
	int accType;
	cout << "[Select the Account Type]" << endl;
	cout << "1. Normal Account   2.High Credit Account" << endl;
	cout << "Select option: "; cin >> accType;
	cout << endl;
	if (accType == NORMAL)
		newNormalAccount();
	else
		newCreditAccount();
}
void AccountHandler::depositMoney()
{
	int accountNumber;
	int money;
	cout << "Enter the account number: "; cin >> accountNumber;
	cout << "Amount of deposit: "; cin >> money;

	for (int i = 0; i < numOfAccounts; i++)
	{
		if (accountArray[i]->getAccountNumber() == accountNumber)
		{
			accountArray[i]->deposit(money);
			cout << "Deposit completed" << endl;
			return;
		}
	}
	cout << "Invalid Account Information." << endl << endl;
}
void AccountHandler::withdrawMoney()
{
	int accountNumber;
	int money;
	cout << "Enter the account number: "; cin >> accountNumber;
	cout << "Amount of withdraw: "; cin >> money;

	for (int i = 0; i < numOfAccounts; i++)
	{
		if (accountArray[i]->getAccountNumber() == accountNumber)
		{
			accountArray[i]->withdraw(money);
			cout << "Withdraw completed" << endl;
			return;
		}
	}
	cout << "Invalid Account Information." << endl << endl;
}
void AccountHandler::viewEntireAccountInfo() const
{
	for (int i = 0; i < numOfAccounts; i++)
	{
		accountArray[i]->ViewAccInfo();
		cout << endl;
	}
}
void AccountHandler::newNormalAccount()
{
	char name[NAME_LEN];
	int accountNumber;
	int balance;
	int interestRate;

	cout << "[Open a Normal Account]" << endl;
	cout << "Enter the customer name: "; cin >> name;
	cout << "Set account number: "; cin >> accountNumber;
	cout << "Enter deposit: "; cin >> balance;
	cout << "Enter interest rate: "; cin >> interestRate;
	cout << endl;
	accountArray[numOfAccounts++] = new NormalAccount(name, accountNumber, balance, interestRate);
}
void AccountHandler::newCreditAccount()
{
	char name[NAME_LEN];
	int accountNumber;
	int balance;
	int interestRate;
	int creditLevel;

	cout << "[Open a High credit Account]" << endl;
	cout << "Enter the customer name: "; cin >> name;
	cout << "Set account number: "; cin >> accountNumber;
	cout << "Enter deposit: "; cin >> balance;
	cout << "Enter interest rate: "; cin >> interestRate;
	cout << "Enter credit Score: "; cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accountArray[numOfAccounts++] = new HighCreditAccount(name, accountNumber, balance, interestRate, LEVEL_A);
		break;
	case 2:
		accountArray[numOfAccounts++] = new HighCreditAccount(name, accountNumber, balance, interestRate, LEVEL_B);
		break;
	case 3:
		accountArray[numOfAccounts++] = new HighCreditAccount(name, accountNumber, balance, interestRate, LEVEL_C);
		break;
	}
}