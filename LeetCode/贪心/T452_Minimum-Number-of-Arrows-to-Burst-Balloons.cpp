#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinArrowShots(vector<vector<int>> &points)
{
    if (points.empty())
        return 0;
    sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });
    int res = 0, end = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] <= end)
            end = min(end, points[i][1]);
        else
        {
            end = points[i][1];
            res++;
        }
    }
    return res + 1;
}

int main()
{
    vector<vector<int>> points = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << findMinArrowShots(points) << endl;
    return 0;
}