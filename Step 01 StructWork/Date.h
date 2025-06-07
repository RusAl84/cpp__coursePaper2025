#pragma once
#include <iostream>
#include <string>
#include <ctime>
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

    int checkDifference(int _day, int _month, int _year) {
        //struct tm a = { 0,0,0,24,5,104 }; /* June 24, 2004 */
        //https://stackoverflow.com/questions/14218894/number-of-days-between-two-dates-c
        struct tm a = { 0,0,0,_day,_month,_year - 1900}; 
        struct tm b = { 0,0,0,day,month,year - 1900 };
        time_t x = mktime(&a);
        time_t y = mktime(&b);
        int difference = 0;
        if (x != (time_t)(-1) && y != (time_t)(-1))
        {
            difference = difftime(y, x) / (60 * 60 * 24);
            //cout << ctime(&x);
            //cout << ctime(&y);
            //cout << "difference = " << difference << " days" << endl;
        }
        return difference;
    }
};