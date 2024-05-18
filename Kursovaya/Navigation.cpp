#include"Navigation.h"

void accountsMenu(vector<Account>& accounts)
{
	while (true) {
		system("cls");
		cout << "----------------------" << endl;
		cout << "|МЕНЮ УЧЕТНЫХ ЗАПИСЕЙ|" << endl;
		cout << "----------------------" << endl;
		cout << "1. Просмотр учетных записей" << endl;
		cout << "2. Добавление учетной записи" << endl;
		cout << "3. Удаление учетной записи" << endl;
		cout << "4. Редактирование учетных записей" << endl;
		cout << "0. Вернуться обратно" << endl;
		cout << "*Выберите один из пунктов: ";
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
			cout << "!Введите от 0 до 4!" << endl;
			system("pause");
		}
	}
}

void editAccounts(vector<Account>& accounts)
{
	system("cls");
	cout << "ИЗМЕНЕНИЕ ДАННЫХ О ПОЛЬЗОВАТЕЛЕ" << endl;
	int number = searchAccount(accounts) - 1;
	system("cls");
	while (true) {
		system("cls");
		cout << "--------------------------------------" << endl;
		cout << "|МЕНЮ ИЗМЕНЕНИЯ ДАННЫХ УЧЕТНОЙ ЗАПИСИ|" << endl;
		cout << "--------------------------------------" << endl;
		cout << " 1. Изменение логина" << endl;
		cout << " 2. Изменение пароля" << endl;
		cout << " 3. Изменение роли" << endl;
		cout << " 0. Вернуться обратно" << endl;
		cout << "*Выберите один из пунктов: ";
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
			cout << "!Введите от 0 до 3!" << endl;
			system("pause");
		}
	}
}

void adminMenu(vector<Account>& accounts, vector<Order>& orders, vector<Service>& services,string login) {
	while (true)
	{
		system("cls");
		cout << "---------------------" << endl;
		cout << "|МЕНЮ АДМИНИСТРАТОРА|" << endl;
		cout << "---------------------" << endl;
		cout << "1. Работа с пользователями" << endl;
		cout << "2. Работа с заказами" << endl;
		cout << "3. Работа с услугами" << endl;
		cout << "0. Выйти из аккаунта" << endl;
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
			cout << "!Введите от 0 до 3!" << endl;
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
		cout << "|МЕНЮ ПОЛЬЗОВАТЕЛЯ|" << endl;
		cout << "-------------------" << endl;
		cout << "1. Просмотр услуг" << endl;
		cout << "2. Сортировка услуг по цене" << endl;
		cout << "3. Сделать заказ" << endl;
		cout << "4. Просмотр своего заказа" << endl;
		cout << "0. Выйти из программы" << endl;

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
				cout << "Нет услуг для заказа" << endl;
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
	 cout << "|МЕНЮ РАБОТЫ С УСЛУГАМИ|" << endl;
	 cout << "------------------------" << endl;
	 cout << " 1. Создание новой услуги" << endl;
	 cout << " 2. Изменение существующей услуги" << endl;
	 cout << " 3. Просмотр всех услуг" << endl;
	 cout << " 4. Удаление услуги" << endl;
	 cout << " 0. Вернуться обратно" << endl;

		cout << "*Выберите один из пунктов: ";
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
		cout << "|МЕНЮ РАБОТЫ С ЗАКАЗАМИ|" << endl;
		cout << "------------------------" << endl;
		cout << " 1. Изменение заказов" << endl;
		cout << " 2. Просмотр всех заказов" << endl;
		cout << " 3. Удаление заказа" << endl;
		cout << " 4. Сортировка заказов " << endl;
		cout << " 0. Вернуться обратно" << endl;

		cout << "*Выберите один из пунктов: ";
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
			cout << "!Введите от 0 до 4!" << endl;
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
		cout << "|МЕНЮ СОРТИРОВКИ ЗАКАЗОВ|" << endl;
		cout << "------------------------" << endl;
		cout << " 1. Сортировка по адресу" << endl;
		cout << " 2. Сортировка по имени заказчика" << endl;
		cout << " 3. Сортировка по кол-ву услуг" << endl;
		cout << " 0. Вернуться обратно" << endl;

		cout << "*Выберите один из пунктов: ";
		int choose = enterInteger();
		switch (choose) {
		case(1):
		{
			if (orders.size() != 0) {
				sortOrderByAdrress(orders);
			}
			else {
				cout << "Нет заказов!" << endl;
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
				cout << "Нет заказов!" << endl;
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
			cout << "Нет заказов!" << endl;
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
			cout << "!Введите от 0 до 4!" << endl;
			system("pause");
			break;
		}
		}
	}
}