#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <time.h>
using namespace std;

class Student
{
public:
    string name;
    int score;
    Student(string name, int score) : name(name), score(score) {}
};

void createStudent(vector<Student> &stu)
{
    for (int i = 0; i < 5; i++)
    {
        string name = "stu" + to_string(i + 1);
        int score = 0;
        Student s(name, score);
        stu.push_back(s);
    }
}

void printStudent(vector<Student> &stu)
{
    for (int i = 0; i < stu.size(); i++)
    {
        cout << stu[i].name << " " << stu[i].score << endl;
    }
}

void showScore(vector<Student> &stu)
{
    for (int i = 0; i < stu.size(); i++)
    {
        cout << stu[i].name << " " << stu[i].score << endl;
    }
}

void setScore(vector<Student> &stu)
{
    for (int i = 0; i < stu.size(); i++)
    {
        deque<int> score;
        for (int j = 0; j < 5; j++)
        {
            int s = rand() % 41 + 60;
            score.push_back(s);
        }

        sort(score.begin(), score.end());
        score.pop_front();
        score.pop_back();
        
        int sum = 0;
        for (int j = 0; j < score.size(); j++)
        {
            sum += score[j];
        }

        int avg = sum / score.size();
        stu[i].score = avg;
    }
}

int main()
{
    srand((unsigned int)time(NULL));

    vector<Student> stu;
    createStudent(stu);
    //printStudent(stu);
    setScore(stu);
    showScore(stu);
    return 0;
}