#ifndef ACCOUNT_HANDLER_H
#define ACCOUNT_HANDLER_H

#include "Account.h"

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
#endif