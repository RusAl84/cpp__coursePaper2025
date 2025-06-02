#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "initial_data.h"
using namespace std;

class Departament
{
public:
    struct DepartamentStruct* data;

    void setDefaultDep() {
        struct DepartamentStruct* dp = new DepartamentStruct();
        dp->inst = "ИКБ";
        dp->name = "КБ-2";
        dp->position = "ассистент";
        dp->resp_person = "Брежнева Е.Д.";
        dp->id_dep = -1;
        struct Item* item = new Item();
        item->title = "Дрель";
        item->inventory_number = "434006913";
        item->commissioning_date.setDate(28, 05, 2025);
        item->service_life = 36;
        dp->items.push_back(*item);
        item->title = "Молоток";
        item->inventory_number = "434006914";
        dp->items.push_back(*item);
        item->title = "Стол";
        item->inventory_number = "434006915";
        dp->items.push_back(*item);
        this->data = dp;
    };

    void DisplayDep() {
        cout << endl << "Сокращенное обозначение института: " << data->inst;
        cout << endl << "Сокращенное обозначение кафедры: " << data->name;
        cout << endl << "Должность: " << data->position;
        cout << endl << "Фамилия и инициалы ответственного лица: " << data->resp_person;
        cout << endl << "--------------------------------------------------";
        for (int i = 0; i < data->items.size(); i++) {
            cout << endl << "Наименование имущества: " << data->items[i].title;
            cout << " Инвентарный номер: " << data->items[i].inventory_number;
            cout << endl << " Дата ввода в эксплуатацию: "; data->items[i].commissioning_date.Display();
            cout << endl << " Cрок службы: " << to_string(data->items[i].service_life);
        }
        cout << endl << "--------------------------------------------------";
    };

    Departament() {
        setDefaultDep();
    };

};

