#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int medianThree(vector<int> &nums, int left, int mid, int right)
{
    if ((nums[left] < nums[mid]) ^ (nums[left] < nums[right]))
    {
        return left;
    }
    else if ((nums[mid] < nums[left]) ^ (nums[mid] < nums[right]))
    {
        return mid;
    }
    else
    {
        return right;
    }
}

int partition(vector<int> &arr, int left, int right)
{
    int med = medianThree(arr, left, (left + right) / 2, right);
    swap(arr[left], arr[med]);

    int i = left, j = right;
    while (i < j)
    {
        while (arr[i] <= arr[right] && i < j)
            i++;
        while (arr[j] > arr[right])
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[right]);
    return i;
}
/* 
void quickSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}
 */
// 尾递归优化
void quickSort(vector<int> &arr, int left, int right)
{
    while (left < right)
    {
        int pivot = partition(arr, left, right);
        if (pivot - left < right - pivot)
        {
            quickSort(arr, left, pivot - 1);
            left = pivot + 1;
        }
        else
        {
            quickSort(arr, pivot + 1, right);
            right = pivot - 1;
        }
    }
} 
/*
int main()
{
    vector<int> arr = {5, 2, 8, 3, 9, 1, 7, 4, 6};
    quickSort(arr, 0, arr.size() - 1);
    for (int v : arr)
        cout << v << " ";
    return 0;
}
 */