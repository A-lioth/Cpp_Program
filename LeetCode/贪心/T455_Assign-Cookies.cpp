#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findContentChildren(vector<int> &children, vector<int> &cookies)
{
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int child = 0, cookie = 0, ans = 0;
    while (child < children.size() && cookie < cookies.size())
    {
        if (children[child] <= cookies[cookie])
            child++;
        cookie++;
    }
    return child;
}

int main()
{
    vector<int> children = {1, 2, 3};
    vector<int> cookies = {1, 1};
    cout << findContentChildren(children, cookies) << endl;
    return 0;
}