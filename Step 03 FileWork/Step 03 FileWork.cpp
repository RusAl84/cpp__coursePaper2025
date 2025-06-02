#include <iostream>

#include <string>
#include <vector>
#include <Windows.h>
#include "..//Step 01 StructWork/Departament.h"
#include "..//Step 02 ListWork/DepartamentList.h"

class FileWork {
public:
    string filename = "..//TextData.txt";

    void saveData(struct node* myHead) {
        struct node* current = myHead;
        int countItems = 0;
        FILE* TextFile;
        fopen_s(&TextFile, filename.c_str(), "w+");
        while (current) {
            //cout << current->data->first_name << endl;
            int countItems = current->data->data->items.size();
            fprintf(TextFile, "%s\n%s\n%s\n%s\n%s\n", \
                current->data->data->inst.c_str(), \
                current->data->data->name.c_str(), \
                current->data->data->position.c_str(), \
                current->data->data->resp_person.c_str(), \
                to_string(countItems).c_str()
            );
            for (int i = 0; i < countItems; i++) {
                fprintf(TextFile, "%s\n%s\n%s\n%s\n%s\n%s\n", \
                    current->data->data->items[i].title.c_str(), \
                    current->data->data->items[i].inventory_number.c_str(), \
                    to_string(current->data->data->items[i].commissioning_date.day).c_str(), \
                    to_string(current->data->data->items[i].commissioning_date.month).c_str(), \
                    to_string(current->data->data->items[i].commissioning_date.year).c_str(), \
                    to_string(current->data->data->items[i].service_life).c_str() \
                );
            }
            current = current->next;
        }
        fclose(TextFile);
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Step 03 FileWork\n";
    DepartamentList* depList = new  DepartamentList();
    depList->genData();
    depList->Dislay();
    class FileWork* fWork = new FileWork();
    fWork->saveData(depList->myHead);
    DepartamentList* depList_new = new  DepartamentList();

}

