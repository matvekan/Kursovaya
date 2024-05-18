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

		//������ ����� ��������� ������
		for (int i = 0; i < Services.size(); i++) {
			costOfOrder += Services.at(i).price;
		}
		return  costOfOrder;
	}
};



int inputInt(); // ���� int

string enterString(); // ���� ������

int checkInterval(int min, int max); // ���� int � ���������

Order doOrder(vector<Service> services,string login);//�������� ������

void createService(vector<Service>&services);//�������� ������

void changeService(vector<Service>& services);//������������� ������

void deleteOrder(vector<Order>& orders);//������� �����

void displayOrder(const vector<Order> orders,string login);//���������� ����� �������

void displayOrders(const vector<Order> orders);//���������� ��� ������

void displayServices(vector<Service> services);//���������� ��� ������

void deleteService(vector<Service>& service);//������� ������

void changeOrder(vector<Order>&orders,vector<Service>services,string login);//������������� �����

void readDataFromFile(vector<Order>& orders); // ������ �� ����� ���������� � �������

void writeDataToFile(const vector<Order>& orders); // ������ � ���� ���������� � �������

int choiseService(const vector<Service> services);//����� ������

void writeDataToFile(const vector<Service>& services);//������ � ���� ���������� �� �������

void readDataFromFile(vector<Service>& services);//������ �� ����� ���������� �� �������

//����������
void  sortServiceByPrice(vector<Service> services);//���������� ����� �� ����
void sortOrderByConsName(vector<Order> orders);//���������� �� ����� �������
void  sortOrderByAdrress(vector<Order> orders);//���������� �� ������ 
void  sortOrderBySize(vector<Order> orders);//���������� �� ���-�� �����


//�����������
bool sortServiceByPriceComp(const Service RHS, const Service LHS);
bool sortOrderByConsNameComp(const Order RHS, const Order LHS);
bool sortOrderByAdrressComp(const Order RHS, const Order LHS);
bool sortOrderBySizeComp(const Order RHS, const Order LHS);






