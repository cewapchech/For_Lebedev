#include "DataTime.h"
#include <sstream>//для разбора строки с месяцем в формате dd MonthName yyyy
#include <string>//для строковых переменных
#include <iostream>
#include <cmath>//для функции abs
using namespace std;

bool DataVremya::isValidDate()const {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return 0;
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;
    if (day > daysInMonth[month - 1])
        return 0;
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59)
        return 0;
    return 1;
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
            throw Exception();
        };
    }
    else if (input.find(".") != string::npos) {//формат dd.MM.yyyy или dd.MM.yy
        int y;
        sscanf_s(input.c_str(), "%d.%d.%d", &day, &month, &y);
        if (y > 2000) {
            year = y;
        }
        else {
            if (y > 70) {
                year = 1900 + y;
            }
            else {
                year = 2000 + y;
            };
        };
    }
    else {//формат dd MonthName yyyy
        string monthStr;
        stringstream ss(input);
        ss >> day >> monthStr >> year;

        string months_ru[] = { "января","февраля","марта","апреля","мая","июня",
                                   "июля","августа","сентября","октября","ноября","декабря" };
        string months_en[] = { "january","february","march","april","may","june",
                               "july","august","september","october","november","december" };
        month = 0;
        for (int i = 0; i < 12; i++)
            if (monthStr == months_ru[i] || monthStr == months_en[i])
                month = i + 1;
        if (month == 0)
            cout << "\nОшибка: неверное название месяца!" << endl;
    }
    if (!isValidDate()) {
        cout << "Дата некорректна!" << endl;
        throw Exception();
    }
    return;
}
void DataVremya::show() {
    int format;
    bool timeCount = (hour != 0) && (minute != 0) && (second != 0);

    cout << "Выберите формат вывода (1 - dd.MM.yyyy, 2 - dd.MM.yy, 3 - dd MonthName yyyy): " << endl;
    cin >> format;
    if (format < 1 || format > 3) {//dd.MM.yyyy
        cout << "Неверный ввод формата!" << endl;
        throw Exception();
    }
    if (format == 1) {
        cout << "Дата: ";
        cout << day << "." << month << "." << year << endl;
        if (timeCount == 0) {
            cout << "Время не указано" << endl;
        }
        else
        {
            cout << hour << ":" << minute << ":" << second << endl;
        };
    }
    else if (format == 2) {//dd.MM.yy
        cout << "Дата: ";
        cout << day << "." << month << "." << (year % 100) << endl;
        if (timeCount == 0) {
            cout << "Время не указано" << endl;
        }
        else
        {
            cout << hour << ":" << minute << ":" << second << endl;
        };
    }
    else {//dd MonthName yyyy
        string months_ru[] = { "января","февраля","марта","апреля","мая","июня",
                                   "июля","августа","сентября","октября","ноября","декабря" };
        cout << "Дата: ";
        cout << day << " " << months_ru[month - 1] << " " << year << endl;
        if (timeCount == 0) {
            cout << "Время не указано" << endl;
        }
        else
        {
            cout << hour << ":" << minute << ":" << second << endl;
        };
    }
    return;
}
unsigned long long int DataVremya::toSeconds() const {//преобразование даты и времени в количество секунд с 1 января 1 года
    int days = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    int m_days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        m_days[1] = 29;
    for (int i = 0; i < month - 1; i++)
        days += m_days[i];
    days += day - 1;
    return(unsigned long long int) days * 86400 + hour * 3600 + minute * 60 + second;
}
void DataVremya::difference() {
    cout << "Ввод первой даты" << endl;
    DataVremya d1;
    d1.input();

    cout << "Ввод второй даты" << endl;
    DataVremya d2;
    d2.input();
    bool iso1 = (d1.hour != 0 && d1.minute != 0 && d1.second != 0);
    bool iso2 = (d2.hour != 0 && d2.minute != 0 && d2.second != 0);
    if ((!iso1 || !iso2)) {
        cout << "Внимание: по условию, если одна дата в формате yyyy-MM-ddThh:mm:ss, вторая тоже должна быть в нём. Расчёт произведён, но учтите формат";
    };

    unsigned long long int sec1 = d1.toSeconds();
    unsigned long long int sec2 = d2.toSeconds();
    unsigned long long int diff = (sec1 > sec2) ? (sec1 - sec2) : (sec2 - sec1);

    unsigned long long int days = diff / 86400;

    cout << "Разность: " << days << " дней";
    if (iso1 || iso2) {
        unsigned long long int hours = (diff % 86400) / 3600;
        unsigned long long int minutes = (diff % 3600) / 60;
        unsigned long long int seconds = diff % 60;
        cout << ", " << hours << " часов, " << minutes << " минут, " << seconds << " секунд";
    };
}
int DataVremya::getDayOfWeek() const {
    return (toSeconds() / 86400) % 7;
}
void DataVremya::setEaster(int y) {//алгоритм вычисления даты Пасхи по году по Гауссу
    int a = y % 19;
    int b = y % 4;
    int c = y % 7;
    int d = (19 * a + 15) % 30;
    int e = (2 * b + 4 * c + 6 * d + 6) % 7;
    int f = d + e;

    year = y;
    hour = 0;
    minute = 0;
    second = 0;
    if (year < 1900) {
        if (f <= 9) {
            month = 3;
            day = 22 + f;
        }
        else
        {
            month = 4;
            day = f - 9;
        }
    }
    else {
        if (f <= 26) {
            month = 4;
            day = 4 + f;
        }
        else {
            month = 5;
            day = f - 26;
        }
    };
}
