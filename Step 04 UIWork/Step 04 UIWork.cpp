#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include "..//Step 03 FileWork/FileWork.h"
#include "..//Step 01 StructWork/Departament.h"
#include "..//Step 02 ListWork/DepartamentList.h"
#include "..//UI ClassMenu/ClassEdit.h"
#include "..//UI ClassMenu/ClassMenu.h"
#include "..//Step 06 CryptoWork/ClassCrypt.h"

void mainMenu(DepartamentList* depList) {
	ClassMenu* mainMenu = new ClassMenu();
	mainMenu->addTitleItem("Главное меню");
	mainMenu->addItem("Просмотреть список имущества"); //0
	mainMenu->addItem("Добавить данные о имущества"); //1
	mainMenu->addItem("Загрузить БД из файла"); //2
	mainMenu->addItem("Сохранить БД в файл"); //3
	mainMenu->addItem("Зашифровать БД"); //4
	mainMenu->addItem("Расшифровать БД"); //5
	mainMenu->addItem("Выполнить вариант 29 часть 1"); //6
	mainMenu->addItem("Выполнить вариант 29 часть 2"); //7
	mainMenu->addItem("Выполнить вариант 29 часть 3"); //8
	mainMenu->addItem("Выход"); //9
	int resultSelectedItem = 0;
	int exitInt = 4;
	ClassMenu* invMenu = new ClassMenu();
	int countItem = 0;
	int resultInvSelectedItem = 1;
	const int exitInvtMenu = 0;
	invMenu->addTitleItem("Список имущества:");
	class FileWork* fWork = new FileWork();
	ClassCrypt* pCrypt = new ClassCrypt();
	ClassMenu* delMenu = new ClassMenu();
	int curCount;
	ClassEdit* ce = new  ClassEdit();
	//int resultSessionsMenuItem = 1;
	//const int exitIntSessionsMenuItem = 0;
	while (resultSelectedItem != exitInt) {
		mainMenu->run();
		resultSelectedItem = mainMenu->getSelectedItem();
		switch (resultSelectedItem) {
		case 0:
			resultInvSelectedItem = 1;
			while (resultInvSelectedItem != exitInvtMenu) {
				invMenu->eraseItem();
				invMenu->addItem("Выход");
				invMenu->addItem("Удалить данные о имуществе");
				struct node* current = depList->myHead;
				while (current) {
					string tmpString = string(current->data->data->name)+ " " + string(current->data->data->resp_person);
					invMenu->addItem(tmpString); //добавить в меню студентов
					current = current->next;
				}
				invMenu->run();
				resultInvSelectedItem = invMenu->getSelectedItem();
				if (resultInvSelectedItem == 1) //удаление данных о студенте
				{
					delMenu->eraseAll();
					delMenu->addTitleItem("Выберите имущество для удаления данных");
					delMenu->addItem("Выход");
					int resultDel = 1;
					const int exitDel = 0;
					struct node* current = depList->myHead;
					while (current) {
						string tmpString = string(current->data->data->name) + " " + string(current->data->data->resp_person);
						delMenu->addItem(tmpString); //добавить в меню имущество
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
				if (resultInvSelectedItem > 1)
				{
					int num = resultInvSelectedItem - 2;
					//depList->editItem(num);
					//можно сделать проверку есть ли такая ещё 
				}
			}
			//resultSelectedItem = exitInt;
			break;
		case 1: //Добавить данные о имущества
			//addDep();
			resultSelectedItem = 0;
			break;
		case 2: //Загрузить БД из файла  
			fWork->loadData(depList);
			countItem = depList->countItem;
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
}


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



}
