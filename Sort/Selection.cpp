#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void selectionSort(vector<int> &nmus)
{
    int minIndex;
    for (int i = 0; i < nmus.size() - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < nmus.size(); j++)
        {
            if (nmus[j] < nmus[minIndex])
            {
                minIndex = j;
            }
        }
        swap(nmus[i], nmus[minIndex]);
    }
}
/* 
int main()
{
    vector<int> nums = {5, 2, 8, 3, 1, 7, 4, 6};
    selectionSort(nums);
    for (int v : nums)
    {
        cout << v << " ";
    }
    return 0;
}
 */