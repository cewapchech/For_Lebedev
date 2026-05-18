#pragma once
class Exception {};

class DataVremya {
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int second;

    bool isValidDate()const;

public:
    DataVremya() : day(1), month(1), year(2000), hour(0), minute(0), second(0) {}

    void input();
    void show();
    unsigned long long int toSeconds() const;
    void difference();
    int getDayOfWeek() const;
    void setEaster(int y);

};
