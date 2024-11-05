#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
//введение необходимых библиотек и описание некоторых функций и шаблонов для дальнейшей работы
//объявление функции проверки существования файла по имени
bool file_exist(const std::string& name_file);
//шаблон, требующий ввода натурального числа
template <typename T>
T GetNum(T min = 0, T max = 10000000);
//требование ввода натурального числа в определённом диапазоне
template <typename T>
T GetNum(T min, T max)
{
	T x;
	while ((std::cin >> x).fail() || (x < min) || (x > max) || (std::cin.get() != '\n'))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Некорректная команда. Введите команду из списка [" << min << "-" << max << "]: ";
	}
	return x;
}