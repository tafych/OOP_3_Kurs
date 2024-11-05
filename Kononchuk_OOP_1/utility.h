#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
//�������� ����������� ��������� � �������� ��������� ������� � �������� ��� ���������� ������
//���������� ������� �������� ������������� ����� �� �����
bool file_exist(const std::string& name_file);
//������, ��������� ����� ������������ �����
template <typename T>
T GetNum(T min = 0, T max = 10000000);
//���������� ����� ������������ ����� � ����������� ���������
template <typename T>
T GetNum(T min, T max)
{
	T x;
	while ((std::cin >> x).fail() || (x < min) || (x > max) || (std::cin.get() != '\n'))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "������������ �������. ������� ������� �� ������ [" << min << "-" << max << "]: ";
	}
	return x;
}