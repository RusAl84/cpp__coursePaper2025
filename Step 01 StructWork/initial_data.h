#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"
struct Item {
    string title;  // ����� - ������������ ���������, 
    string inventory_number; // 434006913 -  ����������� �����, 
    class Date commissioning_date; // 17.02.2025 - ���� ����� � ������������, 
    int service_life; // 24  - ���� ������,
    //int id_dep;    // id ��� ����� � ������
};

struct DepartamentStruct {
    string inst;     // ��� -  ����������� ����������� ��������� 
    string name;  // ��-2 - ����������� ����������� �������  
    string position;  // ��������� - ���������
    string resp_person; // �������� �.�. - ������� � �������� �������������� ���� .
    vector <Item> items;  // ������ ���������
    //int id_dep;    // id ��� ����� � ������
};
