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
	string login; // Логин пользователя
	string hash_password; // Хешированный пароль
	bool role=1; // Роль пользователя
};

const string USERS = "Accounts.txt";

// Проверка на ввод целых чисел
int enterInteger();

// Ввод логина
string newLogin(vector<Account>);

// Ввод пароля
string newPass();

// Получение хэша функции
string hashingPassword(string);

// Считывание из файла в вектор
void readAccounts(vector<Account>&);

// Запись в файл
void fillAccounts(vector<Account>);

// Авторизация
pair<int, string> login(vector<Account>);

// Регистрация 
void newAccount(vector<Account>&);

// Ввод пароля звездочками
string enterPasswordWithStars();

// Просмотр всех учетных записей
void showAccounts(vector<Account>);

// Добавление новых учетных записей
void addNewAccount(vector<Account>&);

// Удаление учетных записей
void deleteAccount(vector<Account>&);

// Поиск одинакового логина
bool ischeckLogin(vector<Account>, string);

// Поиск пользователя
int searchAccount(vector<Account>);

// Изменение логина
void loginChanging(vector <Account>&, int);

// Изменение пароля
void passwordChanging(vector <Account>&, int);

// Изменения роли
void roleChanging(vector <Account>&, int);


