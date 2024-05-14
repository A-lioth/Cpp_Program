#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void siftDown(vector<int> &nums, int n, int i)
{
    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int maxIndex = i;
        if (left < n && nums[left] > nums[maxIndex])
        {
            maxIndex = left;
        }
        if (right < n && nums[right] > nums[maxIndex])
        {
            maxIndex = right;
        }
        if (maxIndex != i)
        {
            swap(nums[i], nums[maxIndex]);
            i = maxIndex;
        }
        else
        {
            break;
        }
    }
}

void heapSort(vector<int> &nums)
{
    for (int i = nums.size() / 2 - 1; i >= 0; i--)
    {
        siftDown(nums, nums.size(), i);
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        swap(nums[0], nums[i]);
        siftDown(nums, i, 0);
    }
}

int main()
{
    vector<int> nums = {5, 3, 8, 4, 2, 7, 6, 1};
    heapSort(nums);
    for (int v : nums)
    {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}