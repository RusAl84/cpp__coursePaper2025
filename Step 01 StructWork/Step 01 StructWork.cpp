﻿#include <iostream>
#include <string>
#include <Windows.h>
#include "Departament.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Step 01 StructWork\n";
    class Departament* dep = new Departament();
    //dep->DisplayDep();
    dep->data->resp_person = "Абрамова Ю.Ю.";
    struct Item* item = new Item();
    item->title = "Бубен";
    item->inventory_number = "434006916";
    item->commissioning_date.setDate(28, 05, 2025);
    item->service_life = 1;
    dep->data->items.push_back(*item);
    dep->DisplayDep();

    //cout << "Дата: " << dep->data->items[0].commissioning_date.getStringDate();
   
}

