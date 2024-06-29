#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target)
            return true;
        if (nums[left] < nums[mid])
        {
            if (target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else if (nums[left] > nums[mid])
        {
            if (target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
        else
            left++;
    }
    return false;
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1};
    int target = 2;
    bool result = search(nums, target);
    if (result)
        cout << "Target " << target << " found in the array." << endl;
    else
        cout << "Target " << target << " not found in the array." << endl;
    return 0;
}