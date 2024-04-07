#include "employee.h"

// 构造函数
Employee::Employee(int id, string name, int department_id)
{
    this->id = id;
    this->name = name;
    this->department_id = department_id;
}

// 显示信息
void Employee::show_info()
{
    cout << "员工编号：" << this->id
         << "\t员工姓名：" << this->name
         << "部门编号：" << this->getDepartmentName() << endl;
}

// 获取部门名称
string Employee::getDepartmentName()
{
    return string("员工");
}