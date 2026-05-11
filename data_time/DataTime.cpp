#include "DataTime.h"
#include <locale.h>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

bool DataVremya::isValidDate() {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;
    int daysInMonth[] = { 31, (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day > daysInMonth[month - 1])
        return false;
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
        return false;
    return true;
}
void DataVremya::input() {
    cout << "Введите дату (форматы: 01.01.2001 или 1 января 2001 или 01.01.01 или yyyy-MM-ddThh:mm:ss): ";
    string input;
    getline(cin, input);

    hour = minute = second = 0;

    if (input.find('T') != string::npos) {//формат yyyy-MM-ddThh:mm:ss
        int cnt = sscanf_s(input.c_str(), "%d-%d-%dT%d:%d:%d", &year, &month, &day, &hour, &minute, &second);
        if (cnt < 6) {
            cout << "Неверный формат!" << endl;
        }
    }
    else if (input.find(".") != string::npos) {//формат dd.MM.yyyy или dd.MM.yy
        int y;
        sscanf_s(input.c_str(), "%d.%d.%d", &day, &month, &y);
        year = (y < 100) ? 2000 + y : y;
    }
    else {//пока не работает, он не понимает названия месяцев :(
        string monthStr;
        stringstream ss(input);
        ss >> day >> monthStr >> year;
        string months[] = { "января","февраля","марта","апреля","мая","июня",
                "июля","августа","сентября","октября","ноября","декабря" };
        month = 0;
        for (int i = 0; i < 12; i++)
            if (monthStr == months[i])
                month = i + 1;
        if (month == 0)
            cout << "Ошибка: неверное название месяца!" << endl;
    }
    if (!isValidDate())
        cout << "Дата некорректна!" << endl;
}
void DataVremya::show() {
    cout << day << "." << month << "." << year
        << " " << hour << ":" << minute << ":" << second << endl;
}