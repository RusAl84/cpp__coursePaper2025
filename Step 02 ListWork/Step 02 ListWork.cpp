#include <iostream>
#include "DepartamentList.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Step 02 ListWork\n";
    DepartamentList *depList = new  DepartamentList();
    depList->genData();
    depList->Dislay();
}
