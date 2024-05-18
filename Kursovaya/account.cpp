#include "Account.h"

string account; // ����� ����������������� ������������	

int enterInteger()
{
	string str;
	while (true) {
		cin >> str;

		string::iterator it = str.begin();
		while (it != str.end())
		{
			if (*it < '0' || *it > '9') {
				cout << "!������� ����� �����!" << endl;
				break;
			}
			it++;

		}
		if (str.size() > 9) {
			cout << "!����� �� ����� ���� ������� 9 ��������!" << endl;
			continue;
		}
		if (it == str.end())
			return stoi(str);
	}
}

string hashingPassword(string password)
{
	int shift = 3;
	string hashed_password;
	for (int i = 0; i < password.length(); i++) {
		char c = password[i];
		if (isalpha(c)) {
			c = toupper(c);
			c = (((c - 65) + shift) % 26) + 65;
		}
		hashed_password += c;
	}

	return hashed_password;

}

string newLogin(vector<Account> accounts) {
	string login;
	while (true) {
		cout << "*������� �����: ";
		int prov = 0;
		cin >> login;
		for (int i = 0; i < login.size(); i++) {
			if ((login[i] < 'a' || login[i] > 'z') && (login[i] < 'A' || login[i] > 'Z') && (login[i] < '0' || login[i] > '9')) {
				prov = 1;
			}
		}
		for (int i = 0; i < accounts.size(); i++) {
			if (login == accounts.at(i).login) prov = 3;
		}

		if (prov == 3) {
			cout << "!������ ����� �����!" << endl;
		}
		else
			if (prov == 0) { return login; }
			else {
				cout << "!����� ����� ��������� ������ ��������� ����� � �����!" << endl;
			}
	}
}

string newPass() {
	string pass;
	while (true) {
		cout << "*������� ������: ";
		int prov = 0, kolchi = 0;
		cin >> pass;
		for (int i = 0; i < pass.size(); i++) {
			if ((pass[i] < 'a' || pass[i] > 'z') && (pass[i] < 'A' || pass[i] > 'Z') && (pass[i] < '0' || pass[i] > '9')) {
				prov = 1;
			}
			if (pass[i] >= '0' && pass[i] <= '9') {
				kolchi++;
			}
		}
		if (prov == 0 && kolchi >= 1 && pass.size() > 4) { return pass; }
		else {
			cout << "!������ ����� �������� ������ �� ��������� ���� � ����, � ����� ������ ���� ������ 4 ��������!" << endl;
		}
	}
}

void readAccounts(vector<Account>& accounts)
{
	ifstream file;
	Account copy;
	file.open(USERS, ios::in);
	if (!file) {
		cout << "!������ �������� �����!" << endl;
		exit(1);
		system("pause");
	}
	else {
		while (true) {
			if (!(file >> copy.login >> copy.hash_password >> copy.role))
				break;
			accounts.push_back(copy);
		}
		if (accounts.size() == 0) {
			Account  admin;
			admin.login = "admin";  // ����� ��� ����������� ������
			admin.hash_password = hashingPassword("123qwe");  // ������ ��� ����������� ������
			admin.role = 1;
			ofstream file(USERS, ios::out);
			file << admin.login << "\t"
				<< admin.hash_password << "\t"
				<< admin.role << "\t";
			file.close();
			accounts.push_back(admin);
		}
	}

	file.close();
}

void fillAccounts(vector<Account> accounts)
{
	ofstream file(USERS, ios::out);
	if (!file)
	{
		cout << "!������ �������� �����!" << endl;
		system("pause");
		return;
	}
	for (int i = 0; i < accounts.size(); i++) {
		if (i != 0 && i != accounts.size()) file << endl;
		file << accounts.at(i).login
			<< "\t" << accounts.at(i).hash_password
			<< "\t" << accounts.at(i).role;
	}
	file.close();
}

pair<int, string> login(vector<Account> accounts)
{
	system("cls");
	string login;
	string password;
	while (true) {
		cout << "�����������" << endl;
		cout << "*������� �����: ";
		cin >> login;
		cout << "*������� ������: ";
		password = enterPasswordWithStars();
		for (int i = 0; i < accounts.size(); i++) {
			if (login == accounts.at(i).login && hashingPassword(password) == accounts.at(i).hash_password) {
				system("cls");
				account = accounts.at(i).login;
				return pair<int, string>(accounts.at(i).role, accounts.at(i).login);
			}
		}
		cout << "\n!�������� ����� ��� ������!\n(1. ��������� ����; 0. ��������� �������)" << endl;
		int i = 0;
		while (i != 1)
		{
			i = enterInteger();
			switch (i) {
			case 1:
			{
				system("cls");
				break;
			}
			case 0:
				return pair<int, string>(-1, " ");
			default:
				cout << "!������� �� 0 �� 1!" << endl;
			}
		}
		continue;
	}
}

void newAccount(vector<Account>& accounts)
{
	string login, password;
	while (true) {
		system("cls");
		cout << "�����������" << endl;
		login = newLogin(accounts);
		password = newPass();
		Account copy;
		copy.login = login;
		copy.hash_password = hashingPassword(password);
		copy.role = 0;
		accounts.push_back(copy);
		fillAccounts(accounts);
		cout << "����������� ������ �������" << endl;
		system("pause");
		return;
	}
}

string enterPasswordWithStars()
{
	string password;
	char c;

	while (true) {
		int i = 0;
		while ((c = _getch()) != 13)
		{
			if (c == 8) {
				if (i == 0)
					continue;
				cout << (char)8 << ' ' << (char)8;
				if (!password.empty())
					password.pop_back();
				i--;
				continue;
			}
			password += c;
			_putch('*');
			i++;
		}
		if (i > 0) {
			break;
		}
	}
	return password;
}

void showAccounts(vector<Account> accounts)
{
	cout << "========================================="
		<< "\n|             ������������              |"
		<< "\n========================================="
		<< "\n|  �  |      �����     |      ����      |"
		<< "\n|=====|================|================|";

	for (int i = 0; i < accounts.size(); i++)
	{
		cout << "\n| " << setw(4) << left << (i + 1)
			<< "| " << setw(15) << left << accounts.at(i).login;
		if (accounts.at(i).role)
			cout << "| " << setw(15) << left << "A������������" << "|";
		else
			cout << "| " << setw(15) << left << "������������" << "|";

		cout << "\n|-=-=-|-=-=-=-=-=-=-=-=|=-=-=-=-=-=-=-=-|";
	}
	cout << endl;
}

void addNewAccount(vector<Account>& accounts)
{
	string login, password;
	int role;
	while (true) {
		system("cls");
		cout << "���������� ������ ������������" << endl;
		login = newLogin(accounts);
		password = newPass();
		cout << "*�������� ����: " << endl;
		cout << "1. �������������\n0. ������������" << endl;
		while (true) {
			role = enterInteger();
			if (role == 1 || role == 0)
				break;
			else
				cout << "!������� 0 ��� 1! " << endl;
		}
		Account copy;
		copy.login = login;
		copy.hash_password = hashingPassword(password);
		copy.role = role;
		accounts.push_back(copy);
		fillAccounts(accounts);
		cout << "������� ��������" << endl;
		system("pause");
		return;
	}
}

void deleteAccount(vector<Account>& accounts) {
	system("cls");
	bool flag = true;
	cout << "�������� �������������" << endl;
	int number_user = searchAccount(accounts);
	if (accounts.at(number_user - 1).login == account) {
		cout << "!���������� ������� ����������� ������� ������!" << endl;
		system("pause");
		return;
	}
	if (number_user > 0 && number_user <= accounts.size()) {
		if (number_user == accounts.size())	
			accounts.pop_back();
		else
			accounts.erase(accounts.begin() + (number_user - 1));
		fillAccounts(accounts);
		cout << "������������ ������" << endl;
		system("pause");
		return;
	}
}

void loginChanging(vector<Account>& accounts, int number)
{
	system("cls");
	string new_login;
	cout << "��������� ������" << endl;
	while (true) {
		new_login = newLogin(accounts);
		if (new_login == accounts.at(number).login)
			cout << endl << "!����� ����� ������ ���������� �� �������!" << endl << endl;
		else if (!ischeckLogin(accounts, new_login))
			cout << endl << "!����� �����, ��������� ����!" << endl << endl;
		else
		{
			accounts.at(number).login = new_login;
			fillAccounts(accounts);
			cout << "����� �������" << endl;
			system("pause");
			return;
		}
	}
}

int searchAccount(vector<Account> accounts)
{
	showAccounts(accounts);
	while (true) {
		cout << "*�������� ����� ������������: ";
		int number_user = enterInteger();
		if (number_user <= 0 || number_user > accounts.size()) {
			cout << "!������������ �� ������, ��������� ����!" << endl;
			continue;
		}
		else
			return number_user;
	}
}

bool ischeckLogin(vector<Account> accounts, string login)
{
	for (int i = 0; i < accounts.size(); i++) {
		if (login == accounts.at(i).login) {
			return 0;
		}
	}
	return 1;
}

void passwordChanging(vector<Account>& accounts, int number)
{
	system("cls");
	cout << "�������� ������" << endl;
	string new_password;
	while (true) {
		new_password = newPass();
		accounts.at(number).hash_password = hashingPassword(new_password);
		fillAccounts(accounts);
		cout << "������ �������" << endl << endl;
		system("pause");
		return;
	}
}

void roleChanging(vector<Account>& accounts, int number)
{
	system("cls");
	if (accounts.at(number).login == account) {
		cout << "!���������� �������� ���� ������������ ��������!" << endl;
		system("pause");
		return;
	}
	cout << "�������� ����" << endl;
	int change;
	if (accounts.at(number).role == 1)
	{
		cout << "*������� �������� ���� �� ������������?" << endl;
		cout << "1 - ��\n0 - ���" << endl;
		while (true) {
			if (change = enterInteger() == 1)
			{
				accounts.at(number).role = 0;
				fillAccounts(accounts);
				cout << endl << "���� ��������" << endl << endl;
				system("pause");
				return;
			}
			else if (!change)
				return;
			else
				cout << "!������� �� 0 �� 1!" << endl;
		}
	}
	else
	{
		cout << "*������� �������� ���� �� ��������������?" << endl;
		cout << "1 - ��\n0 - ���" << endl;
		while (true) {
			if (change = enterInteger() == 1)
			{
				accounts.at(number).role = 1;
				fillAccounts(accounts);
				cout << endl << "���� ��������" << endl << endl;
				system("pause");
				return;
			}
			else if (!change)
				return;
			else
				cout << "!������� �� 0 �� 1! " << endl;
		}
	}
}
