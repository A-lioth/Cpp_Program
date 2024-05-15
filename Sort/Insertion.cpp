#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > key)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}
/* 
int main()
{
    vector<int> nums = {5, 2, 4, 6, 1, 3, 8, 7};
    insertionSort(nums);
    for (int v : nums)
    {
        cout << v << " ";
    }
    return 0;
}
 */