#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    vector<int> ret;
    multiset<int> ms;
    for (int i = 0; i < nums.size(); i++)
    {
        ms.insert(nums[i]);
    }
    
    for (int i = 1; i <= nums.size(); i++)
    {
        if (ms.find(i) == ms.end())
        {
            ret.push_back(i);
        }
    }
    return ret;
}

int main()
{
    vector<int> nums = {1, 1};
    vector<int> ret = findDisappearedNumbers(nums);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " ";
    }
    return 0;
}