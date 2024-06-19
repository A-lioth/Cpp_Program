#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
}

int main()
{
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(numbers, target);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}