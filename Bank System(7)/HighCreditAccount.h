#ifndef HIGHCREDIT_ACCOUNT_H
#define HIGHCREDIT_ACCOUNT_H

#include "NormalAccount.h"

class HighCreditAccount :public NormalAccount
{
private:
	int extraInterest;
public:
	HighCreditAccount(char* name, int accNum, int bal, int interest, char score);
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
#endif
