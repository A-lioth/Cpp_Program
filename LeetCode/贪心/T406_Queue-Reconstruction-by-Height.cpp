#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
}

int main()
{
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    vector<vector<int>> res = reconstructQueue(people);
    for (auto p : res)
    {
        cout << p[0] << " " << p[1] << endl;
    }
    return 0;
}