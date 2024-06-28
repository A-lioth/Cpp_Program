#include <iostream>
#include <vector>

using namespace std;

int lower_bound(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target > nums[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int upper_bound(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target > nums[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.empty())
        return {-1, -1};
    int left = lower_bound(nums, target);
    if (left == nums.size() || nums[left] != target)
        return {-1, -1};
    int right = upper_bound(nums, target + 1) - 1;
    return {left, right};
}

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> result = searchRange(nums, target);
    cout << "First position: " << result[0] << endl;
    cout << "Last position: " << result[1] << endl;
    return 0;
}