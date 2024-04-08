#pragma once
#include <string>
#include <iostream>
using namespace std;

// 职工类
class Staff
{
public:
    // 虚函数，显示职工信息
    virtual void showInfo() = 0;

    // 虚函数，获取部门名称
    virtual string getDepartmentName() = 0;

    int id;               // 职工编号
    string name;          // 职工姓名
    string department_id; // 部门编号
};