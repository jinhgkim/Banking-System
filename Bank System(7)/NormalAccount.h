#ifndef NORMAL_ACCOUNT_H
#define NORMAL_ACCOUNT_H

#include "Account.h"

class NormalAccount :public Account
{
private:
	int interestRate;
public:
	NormalAccount(char* name, int accNum, int bal, int interest);
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

#endif // !NormalAccount_H

