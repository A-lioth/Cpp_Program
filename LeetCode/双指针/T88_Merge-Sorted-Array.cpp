#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int first_end = m - 1, second_end = n - 1;
    int last_end = m + n - 1;

    // nums1和nums2中均有元素
    while (first_end >= 0 && second_end >= 0)
        nums1[last_end--] = nums2[second_end] > nums1[first_end] ? nums2[second_end--] : nums1[first_end--];

    // nums2中有剩余元素
    while (second_end >= 0)
        nums1[last_end--] = nums2[second_end--];
}

int main()
{
    vector<int> nums1 = {0, 0, 3, 0, 0, 0, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {-1, 1, 1, 1, 2, 3};
    int n = 6;
    merge(nums1, m, nums2, n);
    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    return 0;
}