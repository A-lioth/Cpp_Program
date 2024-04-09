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
    do
    {
        cout << "StaffManager Menu" << endl;
        cout << "0. Exit" << endl;
        cout << "1. Add employee" << endl;
        cout << "2. Show all employees" << endl;
        cout << "3. Delete employee" << endl;
        cout << "4. Modify employee" << endl;
        cout << "5. Search employee" << endl;
        cout << "6. Sort employees" << endl;
        cout << "7. Clear file" << endl;
        cout << "Please enter your choice: " << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
        {
            cout << "Exiting StaffManager..." << endl;
            break;
        }

        case 1:
        {
            this->AddEmployee();
            break;
        }

        case 2:
        {
            this->Show();
            break;
        }

        case 3:
        {
            this->Delete();
            break;
        }

        case 4:
        {
            this->Modify();
            break;
        }

        case 5:
        {
            this->Search();
            break;
        }

        case 6:
        {
            this->Sort();
            break;
        }

        case 7:
        {
            this->Clear();
            break;
        }

        default:
        {
            cout << "Invalid choice. Please enter a valid choice." << endl;
            break;
        }
        }
    } while (choice != 0);
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

void StaffManager::Show()
{
    if (this->IsEmpty)
    {
        cout << "StaffManager is empty." << endl;
        return;
    }
    for (int i = 0; i < this->EmployeeCount; i++)
    {
        this->StaffArray[i]->showInfo();
    }
    system("pause");
    system("cls");
}

void StaffManager::Delete()
{
    if (this->IsEmpty)
    {
        cout << "StaffManager is empty." << endl;
        return;
    }
    int id = 0;
    cout << "Enter the ID of the employee to delete: " << endl;
    cin >> id;
    int index = this->isExist(id);
    if (index == -1)
    {
        cout << "Invalid ID. No employee found with this ID." << endl;
        return;
    }
    Staff *staff = this->StaffArray[index];
    cout << "Are you sure to delete employee " << staff->name << " (ID: " << staff->id << ")? (Y/N)" << endl;
    char ch;
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        for (int i = index; i < this->EmployeeCount - 1; i++)
        {
            this->StaffArray[i] = this->StaffArray[i + 1];
        }
        this->EmployeeCount--;
        this->Save();
        cout << "Deleted employee " << staff->name << " (ID: " << staff->id << ")." << endl;
    }
    system("pause");
    system("cls");
}

int StaffManager::isExist(int id)
{
    int index = 0;
    for (int i = 0; i < this->EmployeeCount; i++)
    {
        if (this->StaffArray[i]->id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void StaffManager::Modify()
{
    if (this->IsEmpty)
    {
        cout << "StaffManager is empty." << endl;
        return;
    }

    int id = 0;
    cout << "Enter the ID of the employee to modify: " << endl;
    cin >> id;
    int index = this->isExist(id);
    if (index == -1)
    {
        cout << "Invalid ID. No employee found with this ID." << endl;
        return;
    }

    delete this->StaffArray[index];
    int new_id = 0;
    string new_name;
    int new_department_id = 0;
    cout << "Enter new ID: " << endl;
    cin >> new_id;
    cout << "Enter new name: " << endl;
    cin >> new_name;
    cout << "Enter new department ID: " << endl;
    cout << "1. labour" << endl;
    cout << "2. manager" << endl;
    cout << "3. boss" << endl;
    cin >> new_department_id;
    Staff *staff = nullptr;
    switch (new_department_id)
    {
    case 1:
    {
        staff = new Employee(new_id, new_name, new_department_id);
        break;
    }

    case 2:
    {
        staff = new Manager(new_id, new_name, new_department_id);
        break;
    }

    case 3:
    {
        staff = new Boss(new_id, new_name, new_department_id);
        break;
    }

    default:
    {
        cout << "Invalid department ID. Please enter a valid ID." << endl;
        break;
    }
    }
    this->StaffArray[index] = staff;
    this->Save();
    cout << "Modified employee " << staff->name << " (ID: " << staff->id << ")." << endl;
    system("pause");
    system("cls");
}

void StaffManager::Search()
{
    if (this->IsEmpty)
    {
        cout << "StaffManager is empty." << endl;
        return;
    }
    cout << "Choose a search option: " << endl;
    cout << "1. Search by ID" << endl;
    cout << "2. Search by name" << endl;
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int id = 0;
        cout << "Enter the ID to search: " << endl;
        cin >> id;
        int index = this->isExist(id);
        if (index == -1)
        {
            cout << "No employee found with this ID." << endl;
        }
        else
        {
            this->StaffArray[index]->showInfo();
        }
    }

    case 2:
    {
        string name;
        cout << "Enter the name to search: " << endl;
        cin >> name;
        bool found = false;
        for (int i = 0; i < this->EmployeeCount; i++)
        {
            if (this->StaffArray[i]->name == name)
            {
                this->StaffArray[i]->showInfo();
                found = true;
            }
        }
        if (!found)
        {
            cout << "No employee found with this name." << endl;
        }
    }

    default:
    {
        cout << "Invalid choice. Please enter a valid choice." << endl;
        break;
    }
    }
    system("pause");
    system("cls");
}

void StaffManager::Sort()
{
    if (this->IsEmpty)
    {
        cout << "StaffManager is empty." << endl;
        system("pause");
        system("cls");
        return;
    }
    // 选择排序
    cout << "Choose a sort option: " << endl;
    cout << "1. Sortascend by ID" << endl;
    cout << "2. Sortdescend by ID" << endl;
    int choice = 0;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        for (int i = 0; i < this->EmployeeCount; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < this->EmployeeCount; j++)
            {
                if (this->StaffArray[j]->id < this->StaffArray[minIndex]->id)
                {
                    minIndex = j;
                }
            }
            if (minIndex != i)
            {
                Staff *temp = this->StaffArray[i];
                this->StaffArray[i] = this->StaffArray[minIndex];
                this->StaffArray[minIndex] = temp;
            }
        }
    }

    case 2:
    {
        for (int i = 0; i < this->EmployeeCount; i++)
        {
            int maxIndex = i;
            for (int j = i + 1; j < this->EmployeeCount; j++)
            {
                if (this->StaffArray[j]->id > this->StaffArray[maxIndex]->id)
                {
                    maxIndex = j;
                }
            }
            if (maxIndex != i)
            {
                Staff *temp = this->StaffArray[i];
                this->StaffArray[i] = this->StaffArray[maxIndex];
                this->StaffArray[maxIndex] = temp;
            }
        }
    }

    default:
    {
        cout << "Invalid choice. Please enter a valid choice." << endl;
        break;
    }
    }
    this->Save();
    cout << "Sorted employees." << endl;
    this->Show();
}

void StaffManager::Clear()
{
    if (this->IsEmpty)
    {
        cout << "StaffManager is empty." << endl;
        return;
    }
    cout << "Are you sure to clear all employees? (Y/N)" << endl;
    char ch;
    cin >> ch;
    if (ch == 'Y' || ch == 'y')
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();
        if (this->StaffArray != nullptr)
        {
            for (int i = 0; i < this->EmployeeCount; i++)
            {
                if (this->StaffArray[i] != nullptr)
                {
                    delete this->StaffArray[i];
                    this->StaffArray[i] = nullptr;
                }
            }
            delete[] this->StaffArray;
            this->StaffArray = nullptr;
            this->EmployeeCount = 0;
            this->IsEmpty = true;
            cout << "Cleared all employees." << endl;
        }
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
    if (this->StaffArray != nullptr)
    {
        for (int i = 0; i < this->EmployeeCount; i++)
        {
            if (this->StaffArray[i] != nullptr)
            {
                delete this->StaffArray[i];
            }
        }
        delete[] this->StaffArray;
        this->StaffArray = nullptr;
    }
}