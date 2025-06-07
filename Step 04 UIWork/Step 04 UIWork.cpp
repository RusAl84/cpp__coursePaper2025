#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "..//Step 01 StructWork/Departament.h"
#include "..//Step 02 ListWork/DepartamentList.h"
#include "..//Step 03 FileWork/FileWork.h"
#include "..//UI ClassMenu/ClassEdit.h"
#include "..//UI ClassMenu/ClassMenu.h"
#include "..//Step 06 CryptoWork/ClassCrypt.h"
//#include "..//Step 01 StructWork/Date.h"




void  itemEdit(struct node* current, int num) {  
	ClassMenu* itemMenu = new ClassMenu();  // Меню редактирования данных о подразделении
	int resultDpsSelectedItem = 1;
	const int exitInt = 4;
	itemMenu->addTitleItem("Редактирования данных о имуществе:");
	ClassEdit* ce = new  ClassEdit();
	while (resultDpsSelectedItem != exitInt)
	{
		itemMenu->eraseAll();
		itemMenu->addTitleItem("Редактирования данных о имуществе: ");
		itemMenu->addTitleItem(" Наименование имущества: " + current->data->data->items[num].title);
		itemMenu->addTitleItem(" Инвентарный номер: " + current->data->data->items[num].inventory_number);
		itemMenu->addTitleItem(" Дата ввода в эксплуатацию:" + current->data->data->items[num].commissioning_date.getStringDate());
		itemMenu->addTitleItem(" Cрок службы: " + to_string(current->data->data->items[num].service_life));
		itemMenu->addItem("Изменить Наименование имущества"); //0
		itemMenu->addItem("Изменить Инвентарный номер");//1
		itemMenu->addItem("Изменить Дата ввода в эксплуатацию");//2
		itemMenu->addItem("Изменить Cрок службы");//3
		itemMenu->addItem("Выход");//4
		itemMenu->run();
		resultDpsSelectedItem = itemMenu->getSelectedItem();
		switch (resultDpsSelectedItem)
		{
		case 0:
			ce->setLabel("Изменить Наименование имущества ");
			current->data->data->items[num].title = ce->setDataString(current->data->data->items[num].title);
			break;
		case 1:
			ce->setLabel("Изменить Инвентарный номер ");
			current->data->data->items[num].inventory_number = ce->setDataString(current->data->data->items[num].inventory_number);
			break;
		case 2:
			ce->setLabel("Изменить Дата ввода в эксплуатацию ");
			ce->setLabel("Введите день введения в в эксплуатацию: ");
			current->data->data->items[num].commissioning_date.day = ce->setDataInt(1, 31, current->data->data->items[num].commissioning_date.day);
			ce->setLabel("Введите месяц введения в в эксплуатацию:  ");
			current->data->data->items[num].commissioning_date.month = ce->setDataInt(1, 12, current->data->data->items[num].commissioning_date.month);;
			ce->setLabel("Введите год введения в в эксплуатацию: ");
			current->data->data->items[num].commissioning_date.year = ce->setDataInt(1960, 2050, current->data->data->items[num].commissioning_date.year);
			break;
		case 3:
			ce->setLabel("Изменить Cрок службы ");
			//int startRange, int endRange, int dataInt
			current->data->data->items[num].service_life = ce->setDataInt(1,240, current->data->data->items[num].service_life);
			break;
		case 4:
			resultDpsSelectedItem = exitInt;
			break;
		default:
			break;
		}
	}
}

void  itemAdd(struct node* current) {

	struct Item* item = new Item();
	item->title = "ЛОМ";
	item->inventory_number = "43400692222";
	item->commissioning_date.setDate(28, 05, 2025);
	item->service_life = 24;
	current->data->data->items.push_back(*item);
	itemEdit(current, current->data->data->items.size() - 1);
};



void editItems(struct node* current) {
	ClassMenu* itemsMenu = new ClassMenu();  // Меню подразделений
	int resultItsSelectedItem = 1;
	const int exitDpsMenu = 0;
	itemsMenu->addTitleItem("Список имущества:");
	//
	ClassMenu* delMenu = new ClassMenu();
	int curCount;
	while (resultItsSelectedItem != exitDpsMenu)
	{
		itemsMenu->eraseItem();
		itemsMenu->addItem("Выход");
		itemsMenu->addItem("Удалить данные имуществе");
		itemsMenu->addItem("Добавить имущество");
		for(int i=0; i< current->data->data->items.size();i++)
			itemsMenu->addItem(current->data->data->items[i].title + "  " + current->data->data->items[i].inventory_number);
		itemsMenu->run();
		resultItsSelectedItem = itemsMenu->getSelectedItem();
		if (resultItsSelectedItem == 1) //удаление данных
		{
			delMenu->eraseAll();
			delMenu->addTitleItem("Выберите имущество для удаления");
			delMenu->addItem("Выход");
			int resultDel = 1;
			const int exitDel = 0;
			for (int i = 0; i < current->data->data->items.size(); i++)
				delMenu->addItem(current->data->data->items[i].title + "  " + current->data->data->items[i].inventory_number);
			while (resultDel != exitDel) {
				delMenu->run();
				resultDel = delMenu->getSelectedItem();
				if (resultDel == exitDel) {
					break;
				}
				else {
					int num = resultDel - 1;
					//deleteItem(num);
					auto iter = current->data->data->items.cbegin();  // указатель на первый элемент
					current->data->data->items.erase(iter + num);  // удаляем  элемент
					break;
				}
			}
		}
		if (resultItsSelectedItem == 2) //добавление данных
		{
			itemAdd(current);
		}
		if (resultItsSelectedItem > 2) // изменение данных
		{
			int num = resultItsSelectedItem - 3;
			itemEdit(current, num);
		}
	}


};

void  depEdit(DepartamentList* depList, int num) {
	ClassMenu* depMenu = new ClassMenu();  // Меню редактирования данных о подразделении
	int resultDpsSelectedItem = 1;
	const int exitInt = 4;
	depMenu->addTitleItem("Редактирования данных о подразделении:");
	ClassEdit* ce = new  ClassEdit();
	struct node* current = depList->getItem(num);
	while (resultDpsSelectedItem != exitInt)
	{
		depMenu->eraseAll();
		depMenu->addTitleItem("Редактирования данных о подразделении: ");
		depMenu->addTitleItem(" Сокращенное обозначение института: " + current->data->data->inst);
		depMenu->addTitleItem(" Сокращенное обозначение кафедры: " + current->data->data->name);
		depMenu->addTitleItem(" Должность:" + current->data->data->position);
		depMenu->addTitleItem(" Фамилия и инициалы ответственного лица: " + current->data->data->resp_person);
		depMenu->addItem("Изменить Сокращенное обозначение института"); //0
		depMenu->addItem("Изменить Сокращенное обозначение кафедры");//1
		depMenu->addItem("Изменить Должность");//2
		depMenu->addItem("Изменить Фамилия и инициалы ответственного лица");//3
		depMenu->addItem("Просмотреть/изменить имущество");//4
		depMenu->addItem("Выход");//5
		depMenu->run();
		resultDpsSelectedItem = depMenu->getSelectedItem();
		switch (resultDpsSelectedItem)
		{
		case 0:
			ce->setLabel("Изменить Сокращенное обозначение института " );
			current->data->data->inst = ce->setDataString(current->data->data->inst);
			break;
		case 1:
			ce->setLabel("Изменить Сокращенное обозначение кафедры " );
			current->data->data->name = ce->setDataString(current->data->data->name);
			break;
		case 2:
			ce->setLabel("Изменить Должность ");
			current->data->data->position = ce->setDataString(current->data->data->position);
			break;
		case 3:
			ce->setLabel("Изменить Фамилия и инициалы ответственного лица ");
			current->data->data->resp_person = ce->setDataString(current->data->data->resp_person);
			break;
		case 4:
			editItems(current);
			break;
		default:
			break;
		}
	}
}

void  departamentsAdd(DepartamentList* depList) {
	class Departament* dp = new Departament();
	dp->setDefaultDep();
	dp->data->resp_person = "Сорокина П.А.";
	dp->data->name = "КБ-9";
	struct Item* item = new Item();
	item->title = "ЛОМ";
	item->inventory_number = "434006916";
	item->commissioning_date.setDate(28, 05, 2025);
	item->service_life = 24;
	dp->data->items.push_back(*item);
	depList->addItem(dp);
	depEdit(depList, depList->countItem-1);
};

void  departamentsEdit(DepartamentList* depList) {
	ClassMenu* departamentsMenu = new ClassMenu();  // Меню подразделений
	int resultDpsSelectedItem = 1;
	const int exitDpsMenu = 0;
	departamentsMenu->addTitleItem("Список подразделений:");
	ClassMenu* delMenu = new ClassMenu();
	int curCount;
	while (resultDpsSelectedItem != exitDpsMenu)
	{
		departamentsMenu->eraseItem();
		departamentsMenu->addItem("Выход");
		departamentsMenu->addItem("Удалить данные о кафедре");
		struct node* current = depList->myHead;
		while (current) {
			departamentsMenu->addItem(current->data->getDepString()); //добавить в меню кафедру 
			current = current->next;
		}
		departamentsMenu->run();
		resultDpsSelectedItem = departamentsMenu->getSelectedItem();
		if (resultDpsSelectedItem == 1) //удаление данных
		{
			delMenu->eraseAll();
			delMenu->addTitleItem("Выберите подразделение для удаления");
			delMenu->addItem("Выход");
			int resultDel = 1;
			const int exitDel = 0;
			struct node* current = depList->myHead;
			while (current) {
				delMenu->addItem(current->data->getDepString()); //добавить в меню кафедру
				current = current->next;
			}
			while (resultDel != exitDel) {
				delMenu->run();
				resultDel = delMenu->getSelectedItem();
				if (resultDel == exitDel) {
					break;
				}
				else {
					int num = resultDel - 1;
					depList->deleteItem(num);
					break;
				}
			}
		}
		if (resultDpsSelectedItem > 1)
		{
			int num = resultDpsSelectedItem - 2;
			// редактирование подразделения
			depEdit(depList, num);
		}
	}
};

void var29_1(DepartamentList* depList) {
	system("cls");
	cout << "1) список имущества кафедры, закрепленного за определенным сотрудником"<< endl;
	ClassEdit* ce = new  ClassEdit();
	ce->setLabel("Введите Фамилию и инициалы сотрудника для поиска имущества ");
	string found_resp_person = ce->setDataString("Русаков А.М.");
	struct node* current = depList->myHead;
	while (current) {
		if (current->data->data->resp_person == found_resp_person) {
			current->data->DisplayDep();
			break;
		};
		current = current->next;
	}
	if (current == NULL) {
		system("cls");
		cout << "Имущество за сотрудником " + found_resp_person + " не числится";
	}
	_getch();
};

void var29_2(DepartamentList* depList) {
	system("cls");
	cout << "2) список имущества, подлежащего списанию в ближайшие 3 - 4 месяца" << endl;
	ClassEdit* ce = new  ClassEdit();
	ce->setLabel("Введите дату для выполнения задания ");
	ce->setLabel("Введите день: ");
	int day = ce->setDataInt(1, 31, 07);
	ce->setLabel("Введите месяц: ");
	int month = ce->setDataInt(1, 12, 06);;
	ce->setLabel("Введите год: ");
	int year= ce->setDataInt(1960, 2080, 2025);;
	_getch();

};

void var29_3(DepartamentList* depList) {
	system("cls");
	cout << "3) количество некоторого имущества(например, стульев), закрепленных за кафедрой" << endl;
};

void mainMenu(DepartamentList* depList) {
	ClassMenu* mainMenu = new ClassMenu();
	mainMenu->addTitleItem("Главное меню");
	mainMenu->addItem("Просмотреть список подразделений"); //0
	mainMenu->addItem("Добавить данные о подразделении"); //1
	mainMenu->addItem("Загрузить БД из файла"); //2
	mainMenu->addItem("Сохранить БД в файл"); //3
	mainMenu->addItem("Зашифровать БД"); //4
	mainMenu->addItem("Расшифровать БД"); //5
	mainMenu->addItem("Выполнить вариант 29 часть 1"); //6
	mainMenu->addItem("Выполнить вариант 29 часть 2"); //7
	mainMenu->addItem("Выполнить вариант 29 часть 3"); //8
	mainMenu->addItem("Выход"); //9
	int resultSelectedItem = 0;
	int exitInt = 9;
	class FileWork* fWork = new FileWork();
	ClassCrypt* pCrypt = new ClassCrypt();
	while (resultSelectedItem != exitInt)
	{
		mainMenu->run();
		resultSelectedItem = mainMenu->getSelectedItem();
		switch (resultSelectedItem)
		{
		case 0:
			departamentsEdit(depList);
			resultSelectedItem = 0;
			break;
		case 1: //Добавить данные о подразделении
			departamentsAdd(depList);
			resultSelectedItem = 0;
			break;
		case 2: //Загрузить БД из файла  
			fWork->loadData(depList);
			//countItem = depList->countItem;
			resultSelectedItem = 0;
			break;
		case 3: //Сохранить БД в файл
			fWork->saveData(depList->myHead);
			resultSelectedItem = 0;
			break;
		case 4: //Зашифровать БД
			pCrypt->db_filename = fWork->filename;
			pCrypt->secure_db_filename = "secure_dataText.txt";
			pCrypt->Crypt();
			resultSelectedItem = 0;
			break;
		case 5: //Расшифровать БД
			pCrypt->db_filename = fWork->filename;
			pCrypt->secure_db_filename = "secure_dataText.txt";
			pCrypt->Decrypt();
			resultSelectedItem = 0;
			break;
		case 6: //Выполнить вариант 29 часть 1
			var29_1(depList);
			resultSelectedItem = 0;
			break;
		case 7: //Выполнить вариант 29 часть 2
			var29_2(depList);
			_getch();
			resultSelectedItem = 0;
			break;
		case 8: //Выполнить вариант 29 часть 3
			var29_3(depList);
			_getch();
			resultSelectedItem = 0;
			break;
		case 9:
			resultSelectedItem = exitInt;
			break;
		default:
			break;
		}
	}
	//_getch();
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    cout << "Step 04 UIWork\n";
    DepartamentList* depList = new  DepartamentList();
    class FileWork* fWork = new FileWork();
    fWork->loadData(depList);
    //cout << endl << endl << endl << "depList_new";
    //depList->Dislay();
	mainMenu(depList);
	//addInv(depList);
}
