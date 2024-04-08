#pragma once
#include <iostream>
#include "staff.h"
#include "manager.h"
#include "employee.h"
#include "boss.h"
using namespace std;

class StaffManager
{
public:
    // 构造函数
    StaffManager();

    // 菜单
    void Menu();

    // 记录员工人数
    int EmployeeCount;

    // 员工数组指针
    Staff **StaffArray;

    // 添加员工
    void AddEmployee();



    // 退出程序
    void Exit();

    // 析构函数
    ~StaffManager();
};