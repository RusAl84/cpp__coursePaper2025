#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;
    void Display() {
        cout << day << "." << month << "." << year;
    }
    string getStringDate() {
        return string(to_string(day) + "." + to_string(month) + "." + to_string(year));
    }
    Date() = default;
    Date(int day, int month, int year)
        : day(day), month(month), year(year)
    {
    }
    void setDate(int _day, int _month, int _year)
    {
        day = _day;
        month = _month;
        year = _year;
    }
};