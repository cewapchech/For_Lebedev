#include <iostream>
#include <sstream>
#include <string>
#include "DataTime.h"
#include <locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	DataVremya x;
	x.input();
	x.show();
}
