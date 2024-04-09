#include "staffmanager.h"

StaffManager::StaffManager()
{
    // 文件不存在则创建
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open())
    {
        cout << "StaffManager file not found. " << endl;
        this->EmployeeCount = 0;
        this->StaffArray = nullptr;
        this->IsEmpty = true;
        ifs.close();
        return;
    }

    // 文件为空则提示
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "StaffManager file is empty. " << endl;
        this->EmployeeCount = 0;
        this->StaffArray = nullptr;
        this->IsEmpty = true;
        ifs.close();
        return;
    }

    // 文件存在且不为空
    this->EmployeeCount = this->getEmployeeCount();
    cout << "the number of staffs: " << this->EmployeeCount << endl;

    // cout << "the number of staffs: " << EmployeeCount << endl;

    //
    this->StaffArray = new Staff *[this->EmployeeCount];
    this->Init();
    this->IsEmpty = false;
    ifs.close();
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
        this->IsEmpty = false;
        cout << "Added " << num << " employees." << endl;

        // 保存员工信息到文件
        this->Save();
    }

    system("pause");
    system("cls");
}

void StaffManager::Save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    if (ofs.is_open())
    {
        ofs << this->EmployeeCount << endl;
        for (int i = 0; i < this->EmployeeCount; i++)
        {
            ofs << this->StaffArray[i]->id << " "
                << this->StaffArray[i]->name << " "
                << this->StaffArray[i]->department_id << endl;
        }
    }
    ofs.close();
}

int StaffManager::getEmployeeCount()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id = 0;
    string name;
    int department_id = 0;
    /*while (ifs >> id && ifs >> name && ifs >> department_id)
    {
        this->EmployeeCount++;
    }
    ifs.close();
    return this->EmployeeCount;*/

    int count = 0;
    while (ifs >> id >> name >> department_id)
    {
        count++;
    }
    ifs.close();
    return count;
}

void StaffManager::Init()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id = 0;
    string name;
    int department_id = 0;
    int index = 0;
    // 读取员工信息
    while (ifs >> id >> name >> department_id)
    {
        Staff *staff = nullptr;
        switch (department_id)
        {
        case 1:
        {
            staff = new Employee(id, name, department_id);
            break;
        }

        case 2:
        {
            staff = new Manager(id, name, department_id);
            break;
        }

        case 3:
        {
            staff = new Boss(id, name, department_id);
            break;
        }

        default:
        {
            cout << "Invalid department ID. Please enter a valid ID." << endl;
            break;
        }
            // 向员工数组中添加员工
            // this->StaffArray[this->EmployeeCount] = staff;
            // this->EmployeeCount++;
            this->StaffArray[index] = staff;
            index++;
        }
        ifs.close();
    }
}

void StaffManager::Exit()
{
    cout << "Exiting Staff Manager..." << endl;
    system("pause");
    exit(0);
}

StaffManager::~StaffManager()
{
    if (this->StaffArray != nullptr)
    {
        delete[] this->StaffArray;
        this->StaffArray = nullptr;
    }
}