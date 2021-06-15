#include<iostream>
#include<cstring>
using namespace std;
const int NAME_LEN = 20;

typedef struct
{
	char customerName[NAME_LEN];
	int accountNumber;
	int balance;

}Account;

Account accountArray[100];
int numOfAccounts = 0;

enum { NEW_ACCOUNT = 1, DEPOSIT, WITHDRAW, VIEW_ACCOUNT, EXIT };

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

	strcpy_s(accountArray[numOfAccounts].customerName, name);
	accountArray[numOfAccounts].accountNumber = accountNumber;
	accountArray[numOfAccounts].balance = balance;
	numOfAccounts++;
}
void depositMoney()
{
	int accountNumber;
	int money;
	cout << "Enter the account number: "; cin >> accountNumber;
	cout << "Amount of deposit: "; cin >> money;

	for (int i = 0; i < numOfAccounts; i++)
	{
		if (accountArray[i].accountNumber == accountNumber)
		{
			accountArray[i].balance += money;
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
		if (accountArray[i].accountNumber == accountNumber)
		{
			if (accountArray[i].balance < money)
			{
				cout << "Not enought balance to withdraw that amount of money." << endl;
				return;
			}
			accountArray[i].balance -= money;
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
		cout << "Account number: " << accountArray[i].accountNumber << endl;
		cout << "Name: " << accountArray[i].customerName << endl;
		cout << "Balance: " << accountArray[i].balance << endl;
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
		case EXIT:
			break;
		default:
			cout << "Illegal selection." << endl;
		}
	}

	system("Pause");
	return 0;
}