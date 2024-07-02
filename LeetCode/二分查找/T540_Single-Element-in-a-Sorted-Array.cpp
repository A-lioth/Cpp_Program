#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    unordered_map<int, int> seen;
    for (int num : nums)
        seen[num]++;
    for (int num : nums)
        if (seen[num] == 1)
            return num;
    return -1;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(nums) << endl;
    return 0;
}