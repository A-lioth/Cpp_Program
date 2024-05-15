#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < arr.size() - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}
/* 
int main()
{
    vector<int> arr = {5, 3, 8, 4, 2, 7, 1, 6};
    bubbleSort(arr);
    for (int v : arr)
    {
        cout << v << " ";
    }
    return 0;
}
 */