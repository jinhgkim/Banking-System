#include<iostream>
#include<cstring>

using namespace std;
const int NAME_LEN = 20;

enum { NEW_ACCOUNT = 1, DEPOSIT, WITHDRAW, VIEW_ACCOUNT, EXIT };
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };
enum { NORMAL = 1, CREDIT = 2 };

class Account
{
private:
	char* customerName;
	int accountNumber;
	int balance;

public:
	Account(char* name, int accNum, int bal);
	virtual ~Account();
	Account(const Account& ref);
	int getAccountNumber() const;
	virtual void deposit(int money);
	int withdraw(int money);
	void ViewAccInfo() const;
};
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

class NormalAccount :public Account
{
private:
	int interestRate;
public:
	NormalAccount(char *name, int accNum, int bal,int interest);
	virtual void deposit(int money);
};
NormalAccount::NormalAccount(char* name, int accNum, int bal, int interest)
	: Account(name, accNum, bal), interestRate(interest)
{}
void NormalAccount::deposit(int money)
{
	Account::deposit(money);
	Account::deposit(money * (interestRate / 100.0));
}

class HighCreditAccount :public NormalAccount
{
private:
	int extraInterest;
public:
	HighCreditAccount(char* name, int accNum, int bal, int interest,char score);
	virtual void deposit(int money);
};
HighCreditAccount::HighCreditAccount(char* name, int accNum, int bal, int interest, char score)
	:NormalAccount(name, accNum, bal, interest), extraInterest(score)
{}
void HighCreditAccount::deposit(int money)
{
	Account::deposit(money);
	Account::deposit(money * (extraInterest * 0.01));
}

class AccountHandler
{
private:
	Account* accountArray[100];
	int numOfAccounts = 0;
public:
	AccountHandler();
	~AccountHandler();
	void displayMenu() const;
	void newBankAccount();
	void depositMoney();
	void withdrawMoney();
	void viewEntireAccountInfo() const;
protected:
	void newNormalAccount();
	void newCreditAccount();
};
AccountHandler::AccountHandler(){}
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

int main()
{
	AccountHandler manager;
	int option;
	while (true)
	{
		manager.displayMenu();
		
		cout << "Select option: "; cin >> option;
		cout << endl;
		switch (option)
		{
		case NEW_ACCOUNT:
			manager.newBankAccount();
			break;
		case DEPOSIT:
			manager.depositMoney();
			break;
		case WITHDRAW:
			manager.withdrawMoney();
			break;
		case VIEW_ACCOUNT:
			manager.viewEntireAccountInfo();
			break;
		case EXIT:
			//manager.~AccountHandler();
			return 0;
		default:
			cout << "Illegal selection." << endl;
		}
	}

	system("Pause");
	return 0;
}