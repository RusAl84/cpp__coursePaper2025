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
        dep->inst = "���";
        dep->name = "��-2";
        dep->position = "���������";
        dep->resp_person = "�������� �.�.";
        dep->id_dep = -1;
        struct Item* item = new Item();
        item->title = "�����";
        item->inventory_number = "434006913";
        item->commissioning_date.setDate(28, 05, 2025);
        item->service_life = 36;
        dep->items.push_back(*item);
        item->title = "�������";
        item->inventory_number = "434006914";
        dep->items.push_back(*item);
        item->title = "����";
        item->inventory_number = "434006915";
        dep->items.push_back(*item);
        return dep;
    };

    void DisplayDep() {
        cout << endl << "����������� ����������� ���������: " << dep->inst;
        cout << endl << "����������� ����������� �������: " << dep->name;
        cout << endl << "���������: " << dep->position;
        cout << endl << "������� � �������� �������������� ����: " << dep->resp_person;
        cout << endl << "--------------------------------------------------";
        for (int i = 0; i < dep->items.size(); i++) {
            cout << endl << "������������ ���������: " << dep->items[i].title;
            cout << " ����������� �����: " << dep->items[i].inventory_number;
            cout << endl << " ���� ����� � ������������: "; dep->items[i].commissioning_date.Display();
            cout << endl << " C��� ������: " << to_string(dep->items[i].service_life);
        }
        cout << endl << "--------------------------------------------------";
    };

    Departament() {
        dep=setDefaultDep();
    };

};

