#include "employee.h"

// ���캯��
Employee::Employee(int id, string name, int department_id)
{
    this->id = id;
    this->name = name;
    this->department_id = department_id;
}

// ��ʾ��Ϣ
void Employee::show_info()
{
    cout << "Ա����ţ�" << this->id
         << "\tԱ��������" << this->name
         << "���ű�ţ�" << this->getDepartmentName() << endl;
}

// ��ȡ��������
string Employee::getDepartmentName()
{
    return string("Ա��");
}