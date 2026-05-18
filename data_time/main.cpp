#include <iostream>
#include "DataTime.h"
#include <windows.h>//для русской кодировки
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int choice;
	cout << "Что вы хотите сделать?\n1 - Ввести дату и вывести её в другом формате\n2 - Найти разность между двумя датами\n3 - Узнать день недели для введенной даты\n4 - Определить дату пасхи по году\nВыбор:" << endl;
	cin >> choice;
	cin.ignore(1000, '\n');

	if (choice == 1) {
		DataVremya x;
		x.input();
		x.show();
	}
	else if (choice == 2) {
		DataVremya x;
		x.difference();
	}
	else if (choice == 3) {
		DataVremya d;
		d.input();
		int dow = d.getDayOfWeek();
		string daysNames[] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье" };
		cout << "День недели: " << daysNames[dow] << endl;
	}
	else if (choice == 4) {
		DataVremya e;
		int year;
		cout << "Введите год: ";
		cin >> year;
		e.setEaster(year);
		e.show();
		cout << "Дата Пасхи";
	}
	else {
		cout << "Неверный выбор!" << endl;
	}

	return 0;
}
