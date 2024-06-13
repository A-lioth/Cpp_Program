#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return 0;
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; });
    int res = 0, end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < end)
            res++;
        else
            end = intervals[i][1];
    }
    return res;
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals) << endl;
    return 0;
}