#pragma once
#include <iostream>
using namespace std;
#include "staff.h"

class Employee : public Staff
{
public:
    // ���캯��
    Employee(int id, string name, int department_id);

    // ��ʾԱ����Ϣ
    virtual void show_info();

    // ��ȡ��������
    virtual string getDepartmentName();
};