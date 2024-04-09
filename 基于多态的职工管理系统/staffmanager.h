#pragma once
#include <iostream>
#include "staff.h"
#include "manager.h"
#include "employee.h"
#include "boss.h"
using namespace std;
#include <fstream>


#define FILENAME "stafffile.txt"

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

    //保存员工信息到文件
    void Save();

    // 判断文件是否为空
    bool IsEmpty;

    // 获取员工人数
    int getEmployeeCount();

    // 初始化
    void Init();

    // 退出程序
    void Exit();

    // 析构函数
    ~StaffManager();
};