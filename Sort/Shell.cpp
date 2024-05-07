#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int>& arr)
{
    int n = arr.size();
    int gap = n / 2;
    while (gap > 0)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        gap /= 2;
    }
}

int main()
{
    vector<int> arr = { 5, 3, 8, 4, 2, 7, 1, 6 };
    shellSort(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}