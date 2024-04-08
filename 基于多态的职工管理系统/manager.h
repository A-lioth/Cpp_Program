#pragma once
#include <iostream>
#include "staff.h"
using namespace std;

class Manager : public Staff
{
public:
    // 经理类构造函数
    Manager(int id, string name, int department_id);

    // 显示经理信息
    virtual void showInfo();

    // 获取经理的部门名称
    virtual string getDepartmentName();
};