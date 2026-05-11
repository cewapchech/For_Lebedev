#pragma once

class DataVremya {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;

    bool isValidDate();

public:
    DataVremya() : day(1), month(1), year(2000), hour(0), minute(0), second(0) {}

    void input();

    void show();
};

