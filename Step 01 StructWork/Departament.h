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
    struct DepartamentStruct* dep;

    struct DepartamentStruct* setDefaultDep() {
        struct DepartamentStruct* dep = new DepartamentStruct();
        dep->inst = "ИКБ";
        dep->name = "КБ-2";
        dep->position = "ассистент";
        dep->resp_person = "Брежнева Е.Д.";
        dep->id_dep = -1;
        struct Item* item = new Item();
        item->title = "Дрель";
        item->inventory_number = "434006913";
        item->commissioning_date.setDate(28, 05, 2025);
        item->service_life = 36;
        dep->items.push_back(*item);
        item->title = "Молоток";
        item->inventory_number = "434006914";
        dep->items.push_back(*item);
        item->title = "Стол";
        item->inventory_number = "434006915";
        dep->items.push_back(*item);
        return dep;
    };

    void DisplayDep() {
        cout << endl << "Сокращенное обозначение института: " << dep->inst;
        cout << endl << "Сокращенное обозначение кафедры: " << dep->name;
        cout << endl << "Должность: " << dep->position;
        cout << endl << "Фамилия и инициалы ответственного лица: " << dep->resp_person;
        cout << endl << "--------------------------------------------------";
        for (int i = 0; i < dep->items.size(); i++) {
            cout << endl << "Наименование имущества: " << dep->items[i].title;
            cout << " Инвентарный номер: " << dep->items[i].inventory_number;
            cout << endl << " Дата ввода в эксплуатацию: "; dep->items[i].commissioning_date.Display();
            cout << endl << " Cрок службы: " << to_string(dep->items[i].service_life);
        }
        cout << endl << "--------------------------------------------------";
    };

    Departament() {
        dep=setDefaultDep();
    };

};

