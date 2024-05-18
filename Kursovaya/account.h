#pragma once
#include<iostream>
#include<string>
#include <iterator>
#include<conio.h>
#include <vector>
#include<iomanip>
#include<fstream>
#include <algorithm>
#include <locale.h>
using namespace std;

struct Account {
	string login; // ����� ������������
	string hash_password; // ������������ ������
	bool role=1; // ���� ������������
};

const string USERS = "Accounts.txt";

// �������� �� ���� ����� �����
int enterInteger();

// ���� ������
string newLogin(vector<Account>);

// ���� ������
string newPass();

// ��������� ���� �������
string hashingPassword(string);

// ���������� �� ����� � ������
void readAccounts(vector<Account>&);

// ������ � ����
void fillAccounts(vector<Account>);

// �����������
pair<int, string> login(vector<Account>);

// ����������� 
void newAccount(vector<Account>&);

// ���� ������ �����������
string enterPasswordWithStars();

// �������� ���� ������� �������
void showAccounts(vector<Account>);

// ���������� ����� ������� �������
void addNewAccount(vector<Account>&);

// �������� ������� �������
void deleteAccount(vector<Account>&);

// ����� ����������� ������
bool ischeckLogin(vector<Account>, string);

// ����� ������������
int searchAccount(vector<Account>);

// ��������� ������
void loginChanging(vector <Account>&, int);

// ��������� ������
void passwordChanging(vector <Account>&, int);

// ��������� ����
void roleChanging(vector <Account>&, int);


