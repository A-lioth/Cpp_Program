#pragma once
#include <string>
#include <iostream>
using namespace std;

// ְ����
class Staff 
{
public:
    // �麯������ʾְ����Ϣ
    virtual void showInfo() = 0; 

    // �麯������ȡ��������
    virtual string getDepartmentName() = 0; 

    int id; // ְ�����
    string name; // ְ������
    string department_id; // ���ű��
};