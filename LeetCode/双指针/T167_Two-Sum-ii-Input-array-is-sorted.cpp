#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int i = 0;
    int j = numbers.size() - 1;
    while (i < j)
    {
        if (numbers[i] + numbers[j] < target)
            i++;
        else if (numbers[i] + numbers[j] > target)
            j--;
        else
            return vector<int>{i + 1, j + 1};
    }
    return vector<int>{-1, -1};
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