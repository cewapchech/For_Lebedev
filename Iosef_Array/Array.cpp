#include "Array.h"
#include <locale.h>

Array::Array(int N) {
    size = N;
    capacity = N;
    ptr = new int[capacity];
    for (int i = 0; i < size; ++i) {
        ptr[i] = i + 1;
    }
}

Array::~Array() {
    delete[] ptr;
}

void Array::remove(int index) {
    for (int i = index; i < size - 1; ++i) {
        ptr[i] = ptr[i + 1];
    }
    size--;
}

int& Array::operator[](int index) {
    return ptr[index];
}

int Array::getSize() const {
    return size;
}

void Array::print() {
    for (int i = 0; i < size; ++i) {
        cout << ptr[i] << " ";
    }
    cout << endl;
}