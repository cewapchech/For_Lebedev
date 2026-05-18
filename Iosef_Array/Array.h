#pragma once
#include <iostream>
using namespace std;

class Array {
    int* ptr;
    int size;
    int capacity;

public:
    explicit Array(int N);
    ~Array();
    void remove(int index);
    int& operator[](int index);
    int getSize() const;
    void print();
};