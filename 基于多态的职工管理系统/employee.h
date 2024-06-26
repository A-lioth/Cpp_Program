#pragma once
#include <iostream>
#include "staff.h"
using namespace std;

class Employee : public Staff
{
public:
    // 构造函数
    Employee(int id, string name, int department_id);

    // 显示员工信息
    virtual void showInfo();

    // 获取部门名称`
    virtual string getDepartmentName();
};