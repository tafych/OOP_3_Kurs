#include "db.h"
#include <string>
//�������� ������� � ���������� ������ db_Kononchuk
//�����������
db_Kononchuk::db_Kononchuk()
{
}
//����������
db_Kononchuk::~db_Kononchuk()
{
	clearPersons();
}
//������� �������� ���� �������� person � ������� ������� ����������
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
//����� �������� ������ ������� person � �������� ��������� �� ���� � ������
void db_Kononchuk::addPerson()
{
	person_Kononchuk* somePerson = new person_Kononchuk();
	std::cin >> somePerson;
	//(*somePerson).Set_ID((persons.back())->Get_ID()+1);
	persons.push_back(somePerson);
	std::cout << "��������� ��������\n";
}
//����� ������ persons � �������
void db_Kononchuk::outPerson()
{
	std::string resp="";
	std::cout << "|" << std::setw(4) << "ID" << "|" << std::setw(16) << "���" << "|" << std::setw(16) << "�������" << "|" << std::setw(4) << "�������" << "|" << std::endl
		<< "=============================================" << std::endl;
	if (persons.size()) 
	{ 
		for (auto& iter : persons) 
			std::cout << iter; 
	}
	//else { std::cout << "������ �� ���� �������" << std::endl; }
}
//������ persons �� ���������� �����
void db_Kononchuk::load(std::string inputFile)
{
	//������ ����� ����� � �������� ��� �������������
	while (1) {
		std::cout << "������� ��� ����� ��� ��������: ";
		std::getline(std::cin, inputFile);
		inputFile = inputFile + ".txt";
		if (file_exist(inputFile)) {
			std::cout << "���� ��� ������\n";
			break;
		}
		else {
			std::cout << "���� �� ��� ������. ����������� ����� ? �� 1 / ��� 0: ";
			if (!GetNum(0, 1))
				return;
		}
	}
	clearPersons();
	//�������� ��������� ������ ������
	std::ifstream fin("..\\" + inputFile, std::ios::binary);
	//���������� ������ ������ - ���������� �������� person � �����
	int n;
	fin >> n;
	//�������� ����� �������� person, ���������� �� ��� � ���������� ������� �� �����
	for (int i = 0; i < n; ++i)
	{
		person_Kononchuk* somePerson = new person_Kononchuk(fin);
		//fin >> somePerson;
		persons.push_back(somePerson);
	}
	//
	std::cout << "���� ��������\n";

}
//������ persons � ��������� ����
void db_Kononchuk::save(std::string outputFile)
{
	//������ ����� ����� � �������� ��� �������������
	if (outputFile.empty()) {
		do {
			std::cout << "������� ��� ����� ��� ����������: ";
			std::getline(std::cin, outputFile);
			if (file_exist(outputFile))
				std::cout << "���� ��� ����������. ���������� ? �� 1 / ��� 0: ";
			else
				break;
		} while (!GetNum(0, 1));
	}
	//�������� ��������� ������ ������
	std::ofstream fout("..\\" + outputFile + ".txt", std::ios::binary);
	//����� � ������ ������ ����������� ��������
	fout << persons.size() << std::endl;
	//���������������� ����� ���� ��������
	for (auto& somePerson : persons)
	{
		fout << somePerson;
	}
	std::cout << "���������� ���������\n";
}

//����� �������� person �� ������ �� ��������� ID
void db_Kononchuk::deletePerson()
{
	std::cout << "�������� ����������� �� ID\n";
	if (persons.empty()) {
		std::cout << "���� ����������� ����\n";
		return;
	}

	std::cout << "������� ID ���������� ��� �������� (0 - ������): ";
	//��������� ID ���������� ��� ��������
	int id = GetNum<int>(0, persons[0]->Get_MaxID());
	if (id) {
		//���������������� ������ ���������� �� �������� ������� ���������� persons
		for (auto st = persons.begin(); st != persons.end(); st++) {
			//���� ��������� st �������� � ��������� �� ������ � ������� ID:
			if ((*(*st)).Get_ID() == id) {
				//������� ����������� �����
				delete (*st);
				//������� ��������� �� ������
				persons.erase(st);
				std::cout << "��������� ID = [" << id << "] ��� ������;\n";
				return;
			}
		}
		std::cout << "��������� ID = [" << id << "] �� ��� ������;\n";
	}
}