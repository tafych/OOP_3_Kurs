#include "person.h"
//�������� ������� � ���������� ������ person_Kononchuk
int person_Kononchuk::maxID = 0;

//�����������
person_Kononchuk::person_Kononchuk()
{
    ID = ++maxID;
}
person_Kononchuk::person_Kononchuk(std::ifstream& fin)
{
    fin >> this;
}
//����������
person_Kononchuk::~person_Kononchuk()
{
}
//���������� ��������� ������ � �������
std::ostream& operator<<(std::ostream& os, const person_Kononchuk* person) {
    return os << "|" << std::setw(4) << (*person).ID << "|"
        << std::setw(16) << (*person).firstName << "|" << std::setw(16) << (*person).lastName << "|" << std::setw(4) << (*person).age << "|" << std::endl;
}
//���������� ��������� ������ � ����������
std::istream& operator>>(std::istream& is, person_Kononchuk* person) {
    std::cout << "�������� ����������\n";
    std::cout << "������� ��� ����������: ";
    std::getline(std::cin, (*person).firstName);
    std::cout << "������� ������� ����������: ";
    std::getline(std::cin, (*person).lastName);
    std::cout << "������� ������� ����������: ";
    (*person).age = GetNum<int>();
    return is;
};
//���������� ��������� ������ � ����
std::ofstream& operator<<(std::ofstream& ofs, const person_Kononchuk* person) {
    ofs << (*person).ID << std::endl << (*person).firstName << std::endl << (*person).lastName << std::endl << (*person).age << std::endl;
    return ofs;
};
//���������� ��������� ������ �����
std::ifstream& operator>>(std::ifstream& ifs, person_Kononchuk* person) {
    ifs >> (*person).ID;
    person_Kononchuk::maxID = (person->ID > person_Kononchuk::maxID) ? person->ID : person_Kononchuk::maxID;
    ifs >> (*person).firstName;
    ifs >> (*person).lastName;
    ifs >> (*person).age;
    return ifs;
};

int person_Kononchuk::Get_ID()
{
    return ID;
};
int person_Kononchuk::Get_MaxID()
{
    return maxID;
}
void person_Kononchuk::Reset_MaxID()
{
    maxID=0;
}
//void person_Kononchuk::Set_MaxID(const vector<person_Kononchuk>& v)
//{
//    maxID=max id;
//}