#pragma once
#include <string>
#include <vector>
#include <Windows.h>
#include "..//Step 01 StructWork/Departament.h"

struct node {
    class Departament* data;
    struct node* next;
};

class DepartamentList
{
public:
    struct node* myHead;
    int countItem = 0;
    void addItem(class Departament* data)
    {
        struct node* newItem = new node();
        newItem->data = data;
        if (countItem == 0)
            newItem->next = NULL;
        else
            newItem->next = myHead;
        myHead = newItem;
        countItem++;
    }
    void insertItem(int index, class Departament* data) {
        if (not (index >= 0 and index <= countItem and countItem >= 0))
            return;
        if (index == 0)
            addItem(data);
        else {
            struct node* current = myHead;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            struct node* newItem = new node();
            newItem->data = data;
            newItem->next = current->next;
            current->next = newItem;
            countItem++;
        }
    }
    void editItem(int index, class Departament* data) {
        if (index >= 0 and index < countItem and countItem>0) {
            struct node* current = myHead;
            for (int i = 0; i < index; i++) {
                current = current->next;
                //cout << "+" << current->data;
            }
            current->data = data;
        }
        else {
            cout << endl << "Ошибка индекс не в диапазоне";
        }
    }
    void deleteItem(int index) {
        if (index >= 0 and index < countItem and countItem>0) {
            struct node* current = myHead;
            struct node* old;
            if (index == 0) {
                old = myHead;
                myHead = current->next;
                delete old;
                countItem--;
            }
            else {
                int i = 0;
                while (current) {
                    if (i == index - 1) {
                        old = current->next->next;
                        delete current->next;
                        current->next = old;
                        countItem--;
                        break;
                    }
                    i++;
                    current = current->next;
                }
            }
        }

    }
    void printMyList() {
        struct node* current = myHead;
        cout << endl;
        while (current) {
            cout << current->data->data->resp_person << endl;
            current = current->next;
        }
    }
    void Dislay() {
        struct node* current = myHead;
        while (current) {
            cout << endl;
            current->data->DisplayDep();
            current = current->next;
        }
    }

    void genData() {
        class Departament* dp = new Departament();
        dp->setDefaultDep();
        dp->data->resp_person = "Сорокина П.А.";
        //dp->data->id_dep = 1;
        dp->data->name = "КБ-1";
        struct Item* item = new Item();
        item->title = "Стул";
        item->inventory_number = "434006916";
        item->commissioning_date.setDate(28, 05, 2025);
        item->service_life = 24;
        dp->data->items.push_back(*item);
        addItem(dp);
        dp = new Departament();
        //dp->data->id_dep = 2;
        dp->data->name = "КБ-2";
        dp->data->resp_person = "Брежнева А.Е.";
        item->title = "Пассатижи";
        item->inventory_number = "434006917";
        item->commissioning_date.setDate(28, 05, 2025);
        item->service_life = 12;
        dp->data->items.push_back(*item);
        addItem(dp);
        dp = new Departament();
        //dp->data->id_dep = 3;
        dp->data->name = "КБ-3";
        dp->data->resp_person = "Филатов В.В.";
        item->title = "Шило";
        item->inventory_number = "434006918";
        item->commissioning_date.setDate(28, 05, 2025);
        item->service_life = 12;
        dp->data->items.push_back(*item);
        addItem(dp);
        dp = new Departament();
        //dp->data->id_dep = 4;
        dp->data->name = "КБ-4";
        dp->data->resp_person = "Русаков А.М.";
        item->title = "Отвертка";
        item->inventory_number = "434006919";
        item->commissioning_date.setDate(28, 05, 2025);
        item->service_life = 12;
        dp->data->items.push_back(*item);
        addItem(dp);
        dp = new Departament();
        //dp->data->id_dep = 5;
        dp->data->name = "КБ-5";
        dp->data->resp_person = "Харченко И.Г.";
        item->title = "Маркерная доска";
        item->inventory_number = "434006920";
        item->commissioning_date.setDate(28, 05, 2025);
        item->service_life = 36;
        dp->data->items.push_back(*item);
        addItem(dp);
    }
};