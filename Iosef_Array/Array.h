#pragma once
#include <iostream>
using namespace std;

class Array {
    int* ptr;
    int size;
    int capacity;

public:

    explicit Array(int N) {
        size = N;
        capacity = N;
        ptr = new int[capacity];
        for (int i = 0; i < size; ++i) {
            ptr[i] = i + 1;
        }
    }

    ~Array() {
        delete[] ptr;
    }

    void remove(int index) {
        for (int; index < size - 1; ++index) {
            ptr[index] = ptr[index + 1];
        }
        size--;
    }

    int& operator[](int index) {
        return ptr[index];
    }

    int getSize() const {
        return size;
    }

    void print() {
        for (int i = 0; i < size; ++i) {
            cout << ptr[i] << " ";
        }
        cout << endl;
    }
};