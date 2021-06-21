#include "BankingCommonDec1.h"
#include "AccountHandler.h"

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
			return 0;
		default:
			cout << "Illegal selection." << endl;
		}
	}

	system("Pause");
	return 0;
}