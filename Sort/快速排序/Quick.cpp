#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& arr, int left, int right) 
{
    int i= left, j= right;
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

void quickSort(vector<int>& arr, int left, int right) 
{
    if (left < right) 
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}


int main() 
{
	vector<int> arr = { 5, 2, 8, 3, 9, 1, 7, 4, 6 };
    quickSort(arr, 0, arr.size() - 1);
    for (int v : arr)
        cout << v << " ";
    return 0;
}