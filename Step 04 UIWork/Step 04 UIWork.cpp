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


void editItems(struct node* current) {
	ClassMenu* itemsMenu = new ClassMenu();
	int result = 1;
	const int exit = 0;
	ClassMenu* msMenu = new ClassMenu();
	int resultS = 1;
	const int exitS = 0;
	ClassEdit* ce = new  ClassEdit();
	itemsMenu->addItem("Выход");   //0
	int itemsCount = current->data->data->items.size();
	int cur = 0;
	while (result != exit) {
		itemsMenu->eraseTitle();
		itemsMenu->addTitleItem("Просмотр/изменение/добавление данных имуществе");
		itemsMenu->addTitleItem("Выберите сессию для просмотра и редактирования информации об оценках");
		itemsMenu->run();
		result = itemsMenu->getSelectedItem();
		if (result == exit) {
			result = exit;
			break;
		}
		
		cur = result;
		if ((cur >= 1) and (cur <= itemsCount))
		{
			//рисуем меню и правим оценки про сессию
			msMenu->eraseAll();
			msMenu->addTitleItem("Просмотр/изменение/добавление данных о оценках");
			msMenu->addTitleItem("Данные сессии №" + std::to_string(cur));
			resultS = 1;
			while (resultS != exitS) {
				msMenu->eraseItem();
				msMenu->addItem("Выход");
				msMenu->addItem("Добавить запись");
				msMenu->addItem("Удалить запись");
				//for (int i = 0; i < namesCount; i++)
				//	if (not data[cur - 1][i].isEmpty)
				//	{
				//		msMenu->addItem("Имущество: " markString);
				//	}
				msMenu->run();
				resultS =msMenu->getSelectedItem();
				if (resultS == 0)
					resultS == exitS;
				if (resultS == 1) {
					int itemNum = msMenu->getItemsCount() - 3;
					if (itemNum > itemsCount) {
						system("cls");
						cout << "Ошибка бывает только itemsCount ";
						_getch();  //!!!!!!!!!!!!!!!????????
						_getch();
					}
					else {
						//addExamsResults(cur, itemNum);
					}
				}
				if (resultS == 2) {
					//Удалить запись
					//delExamsResults(cur);
				}
				if (resultS > 2) {
					//addExamsResults(cur, resultS - 3);
				}
			}
		}
		result = cur;
	}
}

void EditInv(struct node* current) {
	//_getch();
	//current->data->DisplayDep();
	//_getch();
	ClassMenu* depMenu = new ClassMenu();
	int resultdepMenu = 1;
	const int exitdepMenu = 0;
	ClassEdit* ce = new  ClassEdit();
	depMenu->addItem("Выход");   //0
	depMenu->addItem("Добавить/изменить cокращенное обозначение института"); //1
	depMenu->addItem("Добавить/изменить cокращенное обозначение кафедры");   //2
	depMenu->addItem("Добавить/изменить должность");   //3
	depMenu->addItem("Добавить/изменить фамилию и инициалы ответственного лица");   //4
	depMenu->addItem("Добавить/изменить (просмотреть) имущество");   //5
	while (resultdepMenu != exitdepMenu) {
		depMenu->eraseTitle();
		depMenu->addTitleItem("Изменение/добавление данных имуществе:");
		depMenu->addTitleItem("Сокращенное обозначение института: " + string(current->data->data->inst));
		depMenu->addTitleItem("Сокращенное обозначение кафедры: " + string(current->data->data->name));
		depMenu->addTitleItem("Должность: " + string(current->data->data->position)) ;
		depMenu->addTitleItem("Фамилия и инициалы ответственного лица: " + string(current->data->data->resp_person));
		depMenu->run();
		resultdepMenu = depMenu->getSelectedItem();
		string tmpString = "";
		int year = 0;
		int startYear = 0;
		switch (resultdepMenu) {
		case 0:
			resultdepMenu = exitdepMenu;
			break;
		case 1:
			ce->setLabel("Введите cокращенное обозначение института. ");
			current->data->data->inst=ce->setDataString(current->data->data->inst);
			break;
		case 2:
			ce->setLabel("Введите cокращенное обозначение кафедры. ");
			current->data->data->name = ce->setDataString(current->data->data->name);
			break;
		case 3:
			ce->setLabel("Введите должность. ");
			current->data->data->position = ce->setDataString(current->data->data->position);
			break;
		case 4:
			ce->setLabel("Введите фамилию и инициалы ответственного лица. ");
			current->data->data->resp_person = ce->setDataString(current->data->data->resp_person);
			break;
		case 5:
			ce->setLabel("Просмотреть/ изменить имущество");
			editItems(current);
			break;
		default:
			break;
		}
	}
}

void addInv(DepartamentList* depList) {
	class Departament* data = new Departament();
	data->setDefaultDep();
	depList->addItem(data);
	struct node* current = depList->myHead;
	EditInv(current);
}

void  depEdit(DepartamentList* depList, int num) {
	ClassMenu* depMenu = new ClassMenu();  // Меню редактирования данных о подразделении
	int countItem = 0;
	int resultDpsSelectedItem = 1;
	const int exitInt = 0;
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

		depMenu->addItem("Выход");
		depMenu->run();
		resultDpsSelectedItem = depMenu->getSelectedItem();
		switch (resultDpsSelectedItem)
		{
		case 0:
			resultDpsSelectedItem = 0;
			//resultSelectedItem = exitInt;
			break;

		default:
			break;
		}
	}
}

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
			//resultSelectedItem = exitInt;
			break;
		case 1: //Добавить данные о имущества
			addInv(depList);
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
			_getch();
			resultSelectedItem = 0;
			break;
		case 7: //Выполнить вариант 29 часть 2
			_getch();
			resultSelectedItem = 0;
			break;
		case 8: //Выполнить вариант 29 часть 3
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
