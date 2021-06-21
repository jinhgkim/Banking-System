#include "Account.h"
#include "BankingCommonDec1.h"

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
Account::Account(const Account& ref) :accountNumber(ref.accountNumber), balance(ref.balance)
{
	customerName = new char[strlen(ref.customerName) + 1];
	for (int i = 0; i < strlen(ref.customerName); i++)
		customerName[i] = ref.customerName[i];
	customerName[strlen(ref.customerName)] = '\0';
}
int Account::getAccountNumber() const
{
	return accountNumber;
}
void Account::deposit(int money)
{
	balance += money;
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