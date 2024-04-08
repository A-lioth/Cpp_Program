#include "staffmanager.h"

StaffManager::StaffManager()
{
    this->EmployeeCount = 0;
    this->StaffArray = nullptr;
}

void StaffManager::Menu()
{
    int choice = 0;
}

void StaffManager::AddEmployee()
{
    // 提示输入添加员工的数量
    cout << "Enter the number of employees to add: " << endl;
    int num = 0;
    cin >> num;

    if (num <= 0)
    {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return;
    }
    else
    {
        int newSize = this->EmployeeCount + num;
        Staff **newSpace = new Staff *[newSize];

        // 复制老数组中的元素到新数组中
        if (this->StaffArray != nullptr)
        {
            for (int i = 0; i < this->EmployeeCount; i++)
            {
                newSpace[i] = this->StaffArray[i];
            }
        }

        for (int i = 0; i < num; i++)
        {
            int id = 0;
            string name;
            int department = 0;

            cout << "Enter " << i + 1 << " employee's ID: ";
            cin >> id;

            cout << "Enter " << i + 1 << " employee's name: ";
            cin >> name;

            cout << "Enter department ID for " << i + 1 << " employee: ";
            cout << "1. labour" << endl;
            cout << "2. manager" << endl;
            cout << "3. boss" << endl;
            cin >> department;

            Staff *staff = nullptr;
            switch (department)
            {
            case 1:
            {
                staff = new Employee(id, name, 1);
                break;
            }

            case 2:
            {
                staff = new Manager(id, name, 2);
                break;
            }

            case 3:
            {
                staff = new Boss(id, name, 3);
                break;
            }

            default:
            {
                cout << "Invalid department ID. Please enter a valid ID." << endl;
                break;
            }
            }
            // 向新数组中添加员工
            newSpace[this->EmployeeCount + i] = staff;
        }

        // 删除老数组
        if (this->StaffArray != nullptr)
        {
            delete[] this->StaffArray;
        }

        // 更新员工数组
        this->StaffArray = newSpace;

        // 更新员工数量
        this->EmployeeCount += num;
        cout << "Added " << num << " employees." << endl;
    }
    system("pause");
    system("cls");
}

void StaffManager::Exit()
{
    cout << "Exiting Staff Manager..." << endl;
    system("pause");
    exit(0);
}

StaffManager::~StaffManager()
{
}