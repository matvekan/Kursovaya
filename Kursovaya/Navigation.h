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


void accountsMenu(vector<Account>&);// ���� ������ � �������� ��������

void editAccounts(vector<Account>&);// ���� ��������� ������� �������

void adminMenu(vector<Account>&, vector<Order>&,vector<Service>&services,string login);// ���� ��������������

void ordersMenu(vector<Order> orders,vector<Service>services,string login);//���� ������ � ��������

void servicesMenu(vector<Service>&services);//���� ������ � ��������

void userMenu(vector<Service>&service,vector<Order>&order,string);//���� ������������

void sortMenu(vector<Order> orders);//���� ����������