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

Date getCurrentDate();//Получение настоящей даты

Time getCurrentTime();//Получение настоящего времени

void showDate(Date date);//Вывести дату в консоль

void showTime(Time time);//Вывести время в консоль


Date enterDate();//Ввод даты
Time enterTime(Date date);//Ввод времени


