#include "db.h"
#include <string>
//описание методов и параметров класса db_Kononchuk
//конструктор
db_Kononchuk::db_Kononchuk()
{
}
//деструктор
db_Kononchuk::~db_Kononchuk()
{
	clearPersons();
}
//функция удаления всех объектов person и очистка массива указателей
void db_Kononchuk::clearPersons()
{
	person_Kononchuk::Reset_MaxID();
	//(*persons[0]).Set_MaxID0();
	for (auto& person : persons)
	{
		delete person;
	}
	persons.clear();
	
}
//метод создания нового объекта person и внесения указателя на него в массив
void db_Kononchuk::addPerson()
{
	person_Kononchuk* somePerson = new person_Kononchuk();
	std::cin >> somePerson;
	//(*somePerson).Set_ID((persons.back())->Get_ID()+1);
	persons.push_back(somePerson);
	std::cout << "Сотрудник добавлен\n";
}
//вывод списка persons в консоль
void db_Kononchuk::outPerson()
{
	std::string resp="";
	std::cout << "|" << std::setw(4) << "ID" << "|" << std::setw(16) << "Имя" << "|" << std::setw(16) << "Фамилия" << "|" << std::setw(4) << "Возраст" << "|" << std::endl
		<< "=============================================" << std::endl;
	if (persons.size()) 
	{ 
		for (auto& iter : persons) 
			std::cout << iter; 
	}
	//else { std::cout << "Данные не были найдены" << std::endl; }
}
//чтение persons из указанного файла
void db_Kononchuk::load(std::string inputFile)
{
	//запрос имени файла и проверка его существования
	while (1) {
		std::cout << "Введите имя файла для загрузки: ";
		std::getline(std::cin, inputFile);
		inputFile = inputFile + ".txt";
		if (file_exist(inputFile)) {
			std::cout << "Файл был найден\n";
			break;
		}
		else {
			std::cout << "Файл не был найден. Попробовать снова ? Да 1 / Нет 0: ";
			if (!GetNum(0, 1))
				return;
		}
	}
	clearPersons();
	//создание файлового потока чтения
	std::ifstream fin("..\\" + inputFile, std::ios::binary);
	//считывание первой строки - количества объектов person в файле
	int n;
	fin >> n;
	//создание новых объектов person, указателей на них и наполнение данными из файла
	for (int i = 0; i < n; ++i)
	{
		person_Kononchuk* somePerson = new person_Kononchuk(fin);
		//fin >> somePerson;
		persons.push_back(somePerson);
	}
	//
	std::cout << "Файл загружен\n";

}
//запись persons в указанный файл
void db_Kononchuk::save(std::string outputFile)
{
	//запрос имени файла и проверка его существования
	if (outputFile.empty()) {
		do {
			std::cout << "Введите имя файла для сохранения: ";
			std::getline(std::cin, outputFile);
			if (file_exist(outputFile))
				std::cout << "Файл уже существует. Переписать ? Да 1 / Нет 0: ";
			else
				break;
		} while (!GetNum(0, 1));
	}
	//создание файлового потока записи
	std::ofstream fout("..\\" + outputFile + ".txt", std::ios::binary);
	//вывод в первую строку количествва объектов
	fout << persons.size() << std::endl;
	//последовательный вывод всех объектов
	for (auto& somePerson : persons)
	{
		fout << somePerson;
	}
	std::cout << "Сотрудники сохранены\n";
}

//метод удаления person из списка по параметру ID
void db_Kononchuk::deletePerson()
{
	std::cout << "Удаление сотрудников по ID\n";
	if (persons.empty()) {
		std::cout << "Лист сотрудников пуст\n";
		return;
	}

	std::cout << "Введите ID сотрудника для удаления (0 - отмена): ";
	//получение ID сотрудника для удаления
	int id = GetNum<int>(0, persons[0]->Get_MaxID());
	if (id) {
		//последовательный пребор указателей на элементы массива указателей persons
		for (auto st = persons.begin(); st != persons.end(); st++) {
			//если указатель st отсылает к указателю на объект с искомым ID:
			if ((*(*st)).Get_ID() == id) {
				//удалить указываемый объет
				delete (*st);
				//удалить указатель на объект
				persons.erase(st);
				std::cout << "Сотрудник ID = [" << id << "] был удален;\n";
				return;
			}
		}
		std::cout << "Сотрудник ID = [" << id << "] не был найден;\n";
	}
}