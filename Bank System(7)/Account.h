#ifndef ACCOUNT_H
#define ACCOUNT_H

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
#endif
