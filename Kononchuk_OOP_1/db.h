#pragma once
#include "person.h"
//объявление методов и параметров класса db_Kononchuk
class db_Kononchuk
{
private:

	std::vector<person_Kononchuk*> persons;
public:
	//список указателей на объекты persons
	
	//конструктор и деструктор
	db_Kononchuk();
	virtual ~db_Kononchuk();
	//методы и задание значений по умолчанию для некоторых из них
	void clearPersons();
	void addPerson();
	void outPerson();
	void load(std::string outputfile = "");
	void save(std::string outputfile = "");
	void deletePerson();
};
