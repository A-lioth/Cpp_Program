#include <iostream>
#include <vector>

using namespace std;

bool checkPossibility(vector<int> &nums)
{
    int count = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
            if (count > 1)
                return false;
            if (i == 1 || nums[i - 2] <= nums[i])
                nums[i - 1] = nums[i];
            else
                nums[i] = nums[i - 1];
        }
    }
    return true;
}

int main()
{
    vector<int> nums = {4, 2, 3};
    cout << checkPossibility(nums) << endl;
    return 0;
}