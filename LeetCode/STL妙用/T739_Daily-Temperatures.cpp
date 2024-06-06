#include <iostream>
#include <vector>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) 
{
    vector<int> res(temperatures.size());
    for (int i = 0; i < temperatures.size(); i++) 
    {
        for (int j = i + 1; j < temperatures.size(); j++) 
        {
            if (temperatures[j] > temperatures[i]) 
            {
                res[i] = j - i;
                break;
            }
        }
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