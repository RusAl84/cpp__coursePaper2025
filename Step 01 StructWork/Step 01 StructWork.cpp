

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Departament {
    string inst;     // ИКБ -  Сокращенное обозначение института 
    string name;  // КБ-2 - сокращенное обозначение кафедры  
    string position;  // ассистент - должность
    string resp_person; // Брежнева Е.Д. - фамилия и инициалы ответственного лица .
    vector <Item> items;  // список элементов
    int id_dep;    // id для связи в файлах
};

struct Item {
    string title;  // Глубинный вибратор для бетона - наименование имущества, 
    string inventory_number; // 434006913 -  инвентарный номер, 
    struct Date commissioning_date; // 17.02.2025 - дата ввода в эксплуатацию, 
    int service_life; // 24  - срок службы,
    int id_dep;    // id для связи в файлах
};


struct Date {
    int day;
    int month;
    int year;
};


void setDefaulDep() {
};


int main()
{
    std::cout << "Hello World!\n";
}

