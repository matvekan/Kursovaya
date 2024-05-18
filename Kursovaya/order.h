#pragma once
#include<iostream>
#include<string>
#include <iterator>
#include<conio.h>
#include<windows.h>
#include <vector>
#include<iomanip>
#include<fstream>
#include <algorithm>
#include <locale.h>
#include"DateAndTime.h"

using namespace std;

struct Service {
	string name;
	int price;
};


struct Order {
	string nameConsumer;
	string login;
	Date Date;
	Time Time;
	string numberOfPhone;
	string  address;
	vector<Service> Services;
	int finalCost() {
		int costOfOrder=0;

		//расчет общей стоимости заказа
		for (int i = 0; i < Services.size(); i++) {
			costOfOrder += Services.at(i).price;
		}
		return  costOfOrder;
	}
};



int inputInt(); // Ввод int

string enterString(); // Ввод строки

int checkInterval(int min, int max); // Ввод int в интервале

Order doOrder(vector<Service> services,string login);//Создание заказа

void createService(vector<Service>&services);//Создание услуги

void changeService(vector<Service>& services);//Редактировать услугу

void deleteOrder(vector<Order>& orders);//Удалить заказ

void displayOrder(const vector<Order> orders,string login);//Отобразить заказ клиента

void displayOrders(const vector<Order> orders);//Отобразить все заказы

void displayServices(vector<Service> services);//Отобразить все услуги

void deleteService(vector<Service>& service);//Удалить услугу

void changeOrder(vector<Order>&orders,vector<Service>services,string login);//Редактировать заказ

void readDataFromFile(vector<Order>& orders); // Чтение из файла информации о заказах

void writeDataToFile(const vector<Order>& orders); // Запись в файл информации о заказах

int choiseService(const vector<Service> services);//Выбор услуги

void writeDataToFile(const vector<Service>& services);//Запись в файл информации об услугах

void readDataFromFile(vector<Service>& services);//Чтение из файла информации об услугах

//Сортировки
void  sortServiceByPrice(vector<Service> services);//Сортировка услуг по цене
void sortOrderByConsName(vector<Order> orders);//Сортировка по имени клиента
void  sortOrderByAdrress(vector<Order> orders);//Сортировка по адресу 
void  sortOrderBySize(vector<Order> orders);//Сортировка по кол-ву услуг


//Компараторы
bool sortServiceByPriceComp(const Service RHS, const Service LHS);
bool sortOrderByConsNameComp(const Order RHS, const Order LHS);
bool sortOrderByAdrressComp(const Order RHS, const Order LHS);
bool sortOrderBySizeComp(const Order RHS, const Order LHS);






