#include"Navigation.h"

void accountsMenu(vector<Account>& accounts)
{
	while (true) {
		system("cls");
		cout << "----------------------" << endl;
		cout << "|���� ������� �������|" << endl;
		cout << "----------------------" << endl;
		cout << "1. �������� ������� �������" << endl;
		cout << "2. ���������� ������� ������" << endl;
		cout << "3. �������� ������� ������" << endl;
		cout << "4. �������������� ������� �������" << endl;
		cout << "0. ��������� �������" << endl;
		cout << "*�������� ���� �� �������: ";
		int i = enterInteger();
		switch (i) {
		case 1:
			system("cls");
			showAccounts(accounts);
			system("pause");
			break;
		case 2:
			addNewAccount(accounts);
			break;
		case 3:
			deleteAccount(accounts);
			break;
		case 4:
			editAccounts(accounts);
			break;
		case 0:
			return;
		default:
			cout << "!������� �� 0 �� 4!" << endl;
			system("pause");
		}
	}
}

void editAccounts(vector<Account>& accounts)
{
	system("cls");
	cout << "��������� ������ � ������������" << endl;
	int number = searchAccount(accounts) - 1;
	system("cls");
	while (true) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "|���� ��������� ������ ������� ������|" << endl;
		cout << "--------------------------------------" << endl;
		cout << " 1. ��������� ������" << endl;
		cout << " 2. ��������� ������" << endl;
		cout << " 3. ��������� ����" << endl;
		cout << " 0. ��������� �������" << endl;
		cout << "*�������� ���� �� �������: ";
		int choose = enterInteger();
		switch (choose) {
		case 1:
			loginChanging(accounts, number);
			break;
		case 2:
			passwordChanging(accounts, number);
			break;
		case 3:
			roleChanging(accounts, number);
			break;
		case 0:
			return;
		default:
			cout << "!������� �� 0 �� 3!" << endl;
			system("pause");
		}
	}
}

void adminMenu(vector<Account>& accounts, vector<Order>& orders, vector<Service>& services,string login) {
	while (true)
	{
		system("cls");
		cout << "---------------------" << endl;
		cout << "|���� ��������������|" << endl;
		cout << "---------------------" << endl;
		cout << "1. ������ � ��������������" << endl;
		cout << "2. ������ � ��������" << endl;
		cout << "3. ������ � ��������" << endl;
		cout << "0. ����� �� ��������" << endl;
		int i = enterInteger();
		switch (i) {
		case(1):
		{
			system("cls");
			accountsMenu(accounts);
			break;
		}
		case(2):
		{
			system("cls");
			ordersMenu(orders,services,login);
			break;
		}
		case(3):
		{
			system("cls");
			servicesMenu(services);
			break;
		}
		case(0):
		{
			return;
		}
		default:
		{
			cout << "!������� �� 0 �� 3!" << endl;
			system("pause");
			break;
		}

		}
	}
}
void userMenu(vector<Service>& service, vector<Order>& orders, string login) {
	while (true) {
		system("cls");
		cout << "-------------------" << endl;
		cout << "|���� ������������|" << endl;
		cout << "-------------------" << endl;
		cout << "1. �������� �����" << endl;
		cout << "2. ���������� ����� �� ����" << endl;
		cout << "3. ������� �����" << endl;
		cout << "4. �������� ������ ������" << endl;
		cout << "0. ����� �� ���������" << endl;

		switch (enterInteger())
		{
		case 1:
		{
			system("cls");
			displayServices(service);
			system("pause");
			break;
		}
		case(2):
		{
			sortServiceByPrice(service);
			break;
		}
		case(3):
		{
			
			if (service.size() == 0) {
				cout << "��� ����� ��� ������" << endl;
			}
			else {
				system("cls");
				orders.push_back(doOrder(service, login));
				writeDataToFile(orders);
			}
			system("pause");
			break;
		}
		case(4):
		{
			displayOrder(orders, login);
			break;
		}
		case(0):
		{
			return;
		}
		}
	}
}

void servicesMenu(vector<Service>& services){
	while (true) {

	 system("cls");
	 cout << "------------------------" << endl;
	 cout << "|���� ������ � ��������|" << endl;
	 cout << "------------------------" << endl;
	 cout << " 1. �������� ����� ������" << endl;
	 cout << " 2. ��������� ������������ ������" << endl;
	 cout << " 3. �������� ���� �����" << endl;
	 cout << " 4. �������� ������" << endl;
	 cout << " 0. ��������� �������" << endl;

		cout << "*�������� ���� �� �������: ";
		int choose = enterInteger();
		switch (choose) {
		case(1):
		{
			system("cls");
			createService(services);
			writeDataToFile(services);
			break;
		}
		case(2):
		{
			changeService(services);
			break;
		}
		case(3):
		{
			system("cls");
			displayServices(services);
			system("pause");
			break;
		}
		case(4):
		{
			deleteService(services);
			break;
		}
		case(0):
		{
			return;
		}
	     
		}
	}
}

void ordersMenu(vector<Order> orders, vector<Service>services,string login){
	while (true) {

		system("cls");
		cout << "------------------------" << endl;
		cout << "|���� ������ � ��������|" << endl;
		cout << "------------------------" << endl;
		cout << " 1. ��������� �������" << endl;
		cout << " 2. �������� ���� �������" << endl;
		cout << " 3. �������� ������" << endl;
		cout << " 4. ���������� ������� " << endl;
		cout << " 0. ��������� �������" << endl;

		cout << "*�������� ���� �� �������: ";
		int choose = enterInteger();
		switch (choose) {
		case(1):
		{
			changeOrder(orders, services,login);
			break;
		}
		case(2):
		{
			displayOrders(orders);
			break;
		}
		case(3):
		{
			deleteOrder(orders);
			break;
		}
		case(4):
		{
			sortMenu(orders);
			break;
		}
		case(0):
		{
			return;
		}
		default:
		{
			cout << "!������� �� 0 �� 4!" << endl;
			system("pause");
			break;
		}
		}
	}
}

void sortMenu( vector<Order> orders) {
	while (true) {

		system("cls");
		cout << "------------------------" << endl;
		cout << "|���� ���������� �������|" << endl;
		cout << "------------------------" << endl;
		cout << " 1. ���������� �� ������" << endl;
		cout << " 2. ���������� �� ����� ���������" << endl;
		cout << " 3. ���������� �� ���-�� �����" << endl;
		cout << " 0. ��������� �������" << endl;

		cout << "*�������� ���� �� �������: ";
		int choose = enterInteger();
		switch (choose) {
		case(1):
		{
			if (orders.size() != 0) {
				sortOrderByAdrress(orders);
			}
			else {
				cout << "��� �������!" << endl;
				system("pause");
			}
			break;
		}
		case(2):
		{
			if (orders.size() != 0) {
				sortOrderByConsName(orders);
			}
			else {
				cout << "��� �������!" << endl;
				system("pause");
			}
			break;
		}
		case(3):
		{
			if (orders.size() != 0) {
				sortOrderBySize(orders);
			}
			else{
			cout << "��� �������!" << endl;
			system("pause");
		    }
			break;
		}
		case(0):
		{
			return;
		}
		default:
		{
			cout << "!������� �� 0 �� 4!" << endl;
			system("pause");
			break;
		}
		}
	}
}