#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "FileWork.h"
#include "..//Step 01 StructWork/Departament.h"
#include "..//Step 02 ListWork/DepartamentList.h"


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
    
    fWork->loadData(depList_new);
    cout << endl << endl << endl << "depList_new";
    depList_new->Dislay();
}