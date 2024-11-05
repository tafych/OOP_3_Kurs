#pragma once
#include "utility.h"
//объявление методов и параметров класса
class person_Kononchuk
{
	static int maxID;
	int ID;
	int age;
	std::string firstName;
	std::string lastName;
private:
	//параметры
	
	

public:

	//конструктор и деструктор
	person_Kononchuk();
	person_Kononchuk(std::ifstream& fin);
	~person_Kononchuk();
	//void Set_ID(int neu);
	int Get_ID();
	static int Get_MaxID();
	static void Reset_MaxID();

	friend std::ostream& operator<<(std::ostream& os, const person_Kononchuk* person);
	friend std::istream& operator>>(std::istream& is, person_Kononchuk* person);
	friend std::ofstream& operator<<(std::ofstream& ofs, const person_Kononchuk* person);
	friend std::ifstream& operator>>(std::ifstream& ifs, person_Kononchuk* person);
};

