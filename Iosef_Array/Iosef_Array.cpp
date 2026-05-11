#include <iostream>
#include <chrono>
#include "Array.h"
using namespace std;

int Iosew(int N, int k) {
    Array arr(N);

    int index = 0;
    while (arr.getSize() > 1) {
        index = (index + k - 1) % arr.getSize();

        arr.remove(index);

        //arr.print();
    }

    return arr[0];
}

int main() {
    int N, k;

    cout << "Input N (how much elements): ";
    cin >> N;

    cout << "Input k (step): ";
    cin >> k;

    // Начало измерения времени
    auto start = chrono::high_resolution_clock::now();

    // Решение задачи Иосифа
    int result = Iosew(N, k);

    // Конец измерения времени
    auto end = chrono::high_resolution_clock::now();

    // Вычисление времени выполнения
    chrono::duration<double> duration = end - start;

    cout << "Last element: " << result << endl;

    // Вывод времени выполнения в секундах
    cout << "Time: " << duration.count() << " sec" << endl;

    return 0;
}
