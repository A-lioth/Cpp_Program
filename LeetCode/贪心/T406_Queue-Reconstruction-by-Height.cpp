#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b)
         { return a[0] == b[0] ? a[1] > b[1] : a[0] > b[0]; });
    vector<vector<int>> res;
    for (auto p : people)
        res.insert(res.begin() + p[1], p);
    return res;
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