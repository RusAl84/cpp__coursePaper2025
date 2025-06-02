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
        dp->inst = "���";
        dp->name = "��-2";
        dp->position = "���������";
        dp->resp_person = "�������� �.�.";
        dp->id_dep = -1;
        struct Item* item = new Item();
        item->title = "�����";
        item->inventory_number = "434006913";
        item->commissioning_date.setDate(28, 05, 2025);
        item->service_life = 36;
        dp->items.push_back(*item);
        item->title = "�������";
        item->inventory_number = "434006914";
        dp->items.push_back(*item);
        item->title = "����";
        item->inventory_number = "434006915";
        dp->items.push_back(*item);
        this->data = dp;
    };

    void DisplayDep() {
        cout << endl << "����������� ����������� ���������: " << data->inst;
        cout << endl << "����������� ����������� �������: " << data->name;
        cout << endl << "���������: " << data->position;
        cout << endl << "������� � �������� �������������� ����: " << data->resp_person;
        cout << endl << "--------------------------------------------------";
        for (int i = 0; i < data->items.size(); i++) {
            cout << endl << "������������ ���������: " << data->items[i].title;
            cout << " ����������� �����: " << data->items[i].inventory_number;
            cout << endl << " ���� ����� � ������������: "; data->items[i].commissioning_date.Display();
            cout << endl << " C��� ������: " << to_string(data->items[i].service_life);
        }
        cout << endl << "--------------------------------------------------";
    };

    Departament() {
        setDefaultDep();
    };

};

