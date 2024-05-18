#include<iostream>
#include"DateAndTime.h"
#include "order.h"

Date getCurrentDate()
{
	struct tm localtime;
	time_t now = time(NULL);
	localtime_s(&localtime, &now);
	Date currentDate;
	currentDate.day = localtime.tm_mday;
	currentDate.month = 1 + localtime.tm_mon; // tm_mon: months in range [0-11] currentDate.year = 1900 + localtime.tm_year;
	currentDate.year = 1900 + localtime.tm_year; // tm_year: years since 1900 return currentDate;
	return currentDate;
}

Time getCurrentTime()
{
	struct tm localtime;
	time_t now = time(NULL); localtime_s(&localtime, &now); Time currentTime;
	currentTime.hour = localtime.tm_hour;
	currentTime.minute = localtime.tm_min;
	currentTime.second = localtime.tm_sec;

	return currentTime;
}

void showDate(Date date)
{
	cout << date.day << "." << date.month << "." << date.year << endl;
}

void showTime(Time time)
{
	cout << time.hour << ":" << time.minute << ":" << time.second << endl;
}

Date enterDate() {
	int year, month, day;
	Date tempD;
	Time tempT;
	tempD = getCurrentDate();
	tempT = getCurrentTime();
	cout << "Введите год: " << endl;
	year = checkInterval(tempD.year,tempD.year+1);
	cout << "Введите номер месяца: "<<endl;
	month = checkInterval(1, 12);


	if (tempD.year == year && tempD.month>month) {
		cout << "Введите номер месяца, который остался в этом году: " << endl;
		month = checkInterval(tempD.month, 12);
	}


	cout << "Введите день: " << endl;
	if (tempD.month == 1 || tempD.month == 3 || tempD.month == 5 || tempD.month == 7 || tempD.month == 8 || tempD.month == 10 || tempD.month == 12) {

		if (tempD.month == month) {
			day = checkInterval(tempD.day, 31);
			if (day == tempD.day && tempT.hour == 19) {
				cout << "К сожалению сегодня не успеем выполнить заказ. Выберите другой день" << endl;
				day = checkInterval(tempD.day, 31);
			}
		}
		else day = checkInterval(1, 31);

	}
	else if (tempD.month == month) {
		day = checkInterval(tempD.day, 30);
		if (day == tempD.day && tempT.hour == 19) {
			cout << "К сожалению сегодня не успеем выполнить заказ. Выберите другой день" << endl;
			day = checkInterval(tempD.day, 30);
		}
	}
	else day = checkInterval(1, 30);
	tempD.year = year;
	tempD.month = month;
	tempD.day = day;
	return tempD;
}

Time enterTime(Date date) {
	Time tempT;
	Date tempD;
	int hour, minute,second=0;
	tempT = getCurrentTime();
	tempD = getCurrentDate();
	if (tempD.year == date.year && tempD.month == date.month && tempD.day == date.day) {
		cout << "Введите час(работаем с 7 утра до 20 часов): " << endl;
		hour = checkInterval(tempT.hour + 1, 20);
	}else{
		cout << "Введите час(работаем с 7 утра до 20 часов): " << endl;
		hour = checkInterval(7, 20);
	}
	if (tempT.hour != 20) {
		cout << "Введите минуты: " << endl;
		minute = checkInterval(0, 59);
	}
	tempT.hour = hour;
	tempT.minute = minute;

	return tempT;
}

