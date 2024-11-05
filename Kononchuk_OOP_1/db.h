#pragma once
#include "person.h"
//���������� ������� � ���������� ������ db_Kononchuk
class db_Kononchuk
{
private:

	std::vector<person_Kononchuk*> persons;
public:
	//������ ���������� �� ������� persons
	
	//����������� � ����������
	db_Kononchuk();
	virtual ~db_Kononchuk();
	//������ � ������� �������� �� ��������� ��� ��������� �� ���
	void clearPersons();
	void addPerson();
	void outPerson();
	void load(std::string outputfile = "");
	void save(std::string outputfile = "");
	void deletePerson();
};
