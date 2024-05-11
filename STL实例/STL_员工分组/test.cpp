#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

class Staff
{
public:
    string name;
    int salary;
};

void createStaff(vector<Staff> &s)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        Staff staff;
        staff.name = "Staff ";
        staff.name += nameSeed[i];
        staff.salary = rand() % 10000 + 10000;
        s.push_back(staff);
    }
}

void setGroup(vector<Staff> &s, multimap<int, Staff> &m)
{
    for (int i = 0; i < s.size(); i++)
    {
        int departmentId = rand() % 3;
        m.insert(make_pair(departmentId, s[i]));
    }
}

void showGroup(multimap<int, Staff> &m)
{
    multimap<int, Staff>::iterator pos;
    pos = m.find(0);
    int index = 0;
    for (; pos != m.end() && index < m.count(0); pos++, index++)
    {
        cout << "Group 0: " << pos->second.name << endl << "Salary: " << pos->second.salary << endl;
    }
    cout << endl;
    pos = m.find(1);
    index = 0;
    for (; pos != m.end() && index < m.count(1); pos++, index++)
    {
        cout << "Group 1: " << pos->second.name << endl << "Salary: " << pos->second.salary << endl;
    }
    cout << endl;
    pos = m.find(2);
    index = 0;
    for (; pos != m.end() && index < m.count(2); pos++, index++)
    {
        cout << "Group 2: " << pos->second.name << endl << "Salary: " << pos->second.salary << endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    vector<Staff> s;
    createStaff(s);
    multimap<int, Staff> m;
    setGroup(s, m);
    showGroup(m);
    system("pause");
    return 0;
}