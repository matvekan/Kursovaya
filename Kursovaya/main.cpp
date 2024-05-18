#include"Navigation.h"

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Account> accounts;
	vector<Order>orders;
	vector<Service>services;

	readAccounts(accounts);
	readDataFromFile(orders);
	readDataFromFile(services);


	while (true) {
		cout << endl;
		system("cls");
		cout << "--------------------------------------------------" << endl;
		cout << "|ÏÐÎÃÐÀÌÌÀ ÄËß Ó×¨ÒÀ ÇÀÊÀÇÎÂ ÊËÈÍÈÍÃÎÂÎÉ ÊÎÌÏÀÍÈÈ|" << endl;
		cout << "--------------------------------------------------" << endl;
		cout << "1. Àâòîðèçàöèÿ" << endl;
		cout << "2. Ðåãèñòðàöèÿ" << endl;
		cout << "0. Âûéòè" << endl;
		cout << "*Âûáåðèòå îäèí èç ïóíêòîâ: ";
		int choise = enterInteger();
		switch (choise) {
		case(1):
		{
			pair<int, string> log = login(accounts);
			if (log.first == 1)
			{
				system("cls");
				adminMenu(accounts, orders,services ,log.second);
			}
			else
			{
				if (log.first == 0) 
				{
					system("cls");
					userMenu(services,orders, log.second);
				}
			}
			break;
		}
		case(2):
		{
			newAccount(accounts);
			break;
		}
		case(0): 
		{
			return 0;
		}
		default:
			cout << "!Ââåäèòå îò 0 äî 2!" << endl;
			system("pause");
		}
	}
}