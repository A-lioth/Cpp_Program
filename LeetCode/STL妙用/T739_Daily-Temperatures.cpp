#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) 
{
    vector<int> res(temperatures.size());
    stack<int> s;
    for (int i = 0; i < temperatures.size(); i++) 
    {
        while (!s.empty() && temperatures[i] > temperatures[s.top()]) 
        {
            res[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    return res;
}

int main() 
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(temperatures);
    for (int i = 0; i < res.size(); i++) 
    {
        cout << res[i] << " ";
    }
    return 0;
}