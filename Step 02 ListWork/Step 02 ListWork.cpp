#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "..//Step 01 StructWork/Departament.h"
using namespace std;

struct node {
    struct Departament* data;
    struct node* next;
};

class DepartamentList
{
public:
    struct node* myHead;
    int countItem = 0;
    void addItem(struct Departament* data)
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
    void insertItem(int index, struct Departament* data) {
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
    void editItem(int index, struct Departament* data) {
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
            cout << current->data->dep->resp_person << endl;
            current = current->next;
        }
    }
    void Dislay() {
        struct node* current = myHead;
        while (current) {
            cout << endl ;
            current->data->DisplayDep();
            current = current->next;
        }
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Step 02 ListWork\n";
    class Departament* dep = new Departament();
    dep->DisplayDep();
    dep->dep->resp_person = "Сорокина П.А.";
    struct Item* item = new Item();
    item->title = "Стул";
    item->inventory_number = "434006916";
    item->commissioning_date.setDate(28, 05, 2025);
    item->service_life = 24;
    dep->dep->items.push_back(*item);
    cout << endl << endl;
    dep->DisplayDep();

    DepartamentList *depList = new  DepartamentList();
    depList->addItem()
}
