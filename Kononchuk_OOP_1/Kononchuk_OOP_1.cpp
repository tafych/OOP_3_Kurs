#include "db.h"
#include <windows.h>
//описание функции проверки существования файла по имени
bool file_exist(const std::string& name_file)
{
	std::ifstream exist("..\\" + name_file); // Проверка существования файла    
	bool flag = exist.is_open();
	exist.close();
	return(flag);
}
//вывод меню и запрос выбрать пункт меню путём ввода с клавиатуры
int menu()
{
	system("cls");
	std::cout << "1. Добавить сотрудника\n"
		<< "2. Показать сотрудников\n"
		<< "3. Сохранить данные\n"
		<< "4. Загрузить данные\n"
		<< "5. Очистить данные\n"
		<< "6. Удалить сотрудника\n"
		<< "0. Выход\n" << "Меню >> ";
	int coursor = GetNum<int>(0, 6);
	return coursor;
}

int main()
{
	//устновка кодировки на русскую
	setlocale(LC_ALL, ".1251");
	SetConsoleCP(1251);
	//объявление объекта db
	db_Kononchuk stud;
	//запрос ввода пункта меню и исполнение соответсвующих методов объекта stud 
	do {
		switch (menu())
		{
		case 1:
		{
			system("cls");
			stud.addPerson();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			stud.outPerson();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			stud.save();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			stud.load();
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			stud.clearPersons();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			stud.deletePerson();
			system("pause");
			break;
		}

		case 0:
			return 0;
			break;
		}
	} while (true);
	return 0;
}