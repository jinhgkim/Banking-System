#include<iostream>
#include<cstring>
using namespace std;
const int NAME_LEN = 20;

class Account
{
private:
	char* customerName;
	int accountNumber;
	int balance;

public:
	Account(char* name, int accNum, int bal);
	~Account();
	int getAccountNumber() const;
	int deposit(int money);
	int withdraw(int money);
	void ViewAccInfo() const;
};

enum { NEW_ACCOUNT = 1, DEPOSIT, WITHDRAW, VIEW_ACCOUNT, EXIT };

Account::Account(char* name, int accNum, int bal) : accountNumber(accNum), balance(bal)
{
	customerName = new char[strlen(name) + 1];
	for (int i = 0; i < strlen(name); i++)
		customerName[i] = name[i];
	customerName[strlen(name)] = '\0';
}
Account::~Account()
{
	delete[]customerName;
}
int Account::getAccountNumber() const
{
	return accountNumber;
}
int Account::deposit(int money)
{
	balance += money;
	return balance;
}
int Account::withdraw(int money)
{
	if (balance > money)
		balance -= money;
	else
		return 0;

	return balance;
}
void Account::ViewAccInfo() const
{
	cout << "Account number: " << accountNumber << endl;
	cout << "Name: " << customerName << endl;
	cout << "Balance: " << balance << endl;
}

Account* accountArray[100];
int numOfAccounts = 0;

void displayMenu() 
{
	cout << "----- Menu -----" << endl;
	cout << "1. Open a new bank account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. View account info" << endl;
	cout << "5. Exit the program" << endl;
	cout << endl;
}
void newBankAccount()
{
	char name[NAME_LEN];
	int accountNumber;
	int balance;

	cout << "[Open a new bank account]" << endl;
	cout << "Enter the customer name: "; cin >> name;
	cout << "Set account number: "; cin >> accountNumber;
	cout << "Enter deposit: "; cin >> balance;
	cout << endl;

	accountArray[numOfAccounts++] = new Account(name, accountNumber, balance);
}
void depositMoney()
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
void withdrawMoney()
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
void viewEntireAccountInfo()
{
	for (int i = 0; i < numOfAccounts; i++)
	{
		accountArray[i]->ViewAccInfo();
		cout << endl;
	}
}

int main()
{
	while (true)
	{
		displayMenu();
		int option;
		cout << "Select option: "; cin >> option;
		cout << endl;

		switch (option)
		{
		case NEW_ACCOUNT:
			newBankAccount();
			break;
		case DEPOSIT:
			depositMoney();
			break;
		case WITHDRAW:
			withdrawMoney();
			break;
		case VIEW_ACCOUNT:
			viewEntireAccountInfo();
			break;
		case EXIT:
			for (int i = 0; i < numOfAccounts; i++)
				delete accountArray[i];
			return 0;
		default:
			cout << "Illegal selection." << endl;
		}
	}

	system("Pause");
	return 0;
}
