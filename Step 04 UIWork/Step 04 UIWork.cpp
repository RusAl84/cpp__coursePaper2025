#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "..//Step 03 FileWork/FileWork.h"
#include "..//Step 01 StructWork/Departament.h"
#include "..//Step 02 ListWork/DepartamentList.h"


int main()
{
    std::cout << "Hello World!\n";
    cout << "Step 04 UIWork\n";
    DepartamentList* depList = new  DepartamentList();
    class FileWork* fWork = new FileWork();
    fWork->loadData(depList);
    //cout << endl << endl << endl << "depList_new";
    //depList->Dislay();



}
