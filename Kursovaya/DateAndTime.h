#pragma once
#include<iostream>
#include<time.h>


using namespace std;
struct Date
{
	int day;
	int month;
	int year;

};

struct Time
{
	int hour;
	int minute;
	int second;
};

Date getCurrentDate();//��������� ��������� ����

Time getCurrentTime();//��������� ���������� �������

void showDate(Date date);//������� ���� � �������

void showTime(Time time);//������� ����� � �������


Date enterDate();//���� ����
Time enterTime(Date date);//���� �������


