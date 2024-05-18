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
#include"order.h"
#include"account.h"


using namespace std;


void accountsMenu(vector<Account>&);// Меню работы с учетными записями

void editAccounts(vector<Account>&);// Меню изменения учетных записей

void adminMenu(vector<Account>&, vector<Order>&,vector<Service>&services,string login);// Меню Администратора

void ordersMenu(vector<Order> orders,vector<Service>services,string login);//Меню работы с заказами

void servicesMenu(vector<Service>&services);//Меню работы с услугами

void userMenu(vector<Service>&service,vector<Order>&order,string);//Меню пользователя

void sortMenu(vector<Order> orders);//Меню сортировок