#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;
    void Display() {
        cout << day << "." << month << "." << year;
    }
    Date() = default;
    Date(int day, int month, int year)
        : day(day), month(month), year(year)
    {
    }
    void setDate(int _day, int _month, int _year)
    {
        day = _day;
        month = _month;
        year = _year;
    }
};

struct Item {
    string title;  // Дрель - наименование имущества, 
    string inventory_number; // 434006913 -  инвентарный номер, 
    class Date commissioning_date; // 17.02.2025 - дата ввода в эксплуатацию, 
    int service_life; // 24  - срок службы,
    int id_dep;    // id для связи в файлах
};

struct Departament {
    string inst;     // ИКБ -  Сокращенное обозначение института 
    string name;  // КБ-2 - сокращенное обозначение кафедры  
    string position;  // ассистент - должность
    string resp_person; // Брежнева Е.Д. - фамилия и инициалы ответственного лица .
    vector <Item> items;  // список элементов
    int id_dep;    // id для связи в файлах
};





struct Departament * setDefaulDep() {
    struct Departament* dep = new Departament();
    dep->inst = "ИКБ";
    dep->name = "КБ-2";
    dep->position = "ассистент";
    dep->resp_person = "Брежнева Е.Д.";
    dep->id_dep = -1;
    struct Item *item =new Item();
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

void DisplayDep(struct Departament* dep) {
    cout << endl <<"Сокращенное обозначение института: "<< dep->inst;
    cout << endl <<"Сокращенное обозначение кафедры: "<< dep->name;
    cout << endl <<"Должность: "<< dep->position;
    cout << endl <<"Фамилия и инициалы ответственного лица: "<< dep->resp_person;
    //cout << endl << "--------------------------------------------------";
    //for (int i = 0; i < dep->items.size(); i++) {
    //    cout << endl << "Наименование имущества: " << dep->items[i].title;
    //    cout << " Инвентарный номер: " << dep->items[i].inventory_number;
    //    //cout << endl << " Дата ввода в эксплуатацию: "; dep->items[i].commissioning_date.Display();
    //    cout << endl << " Cрок службы: " << to_string(dep->items[i].service_life);
    //}
    //cout << endl << "--------------------------------------------------";
};


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Step 01 StructWork\n";
    struct Departament* dep = setDefaulDep();
    DisplayDep(dep);


}

