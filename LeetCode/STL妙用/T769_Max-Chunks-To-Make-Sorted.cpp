#include <iostream>
#include <vector>

using namespace std;
int maxChunksToSorted(vector<int> &arr)
{
    int ret = 0, vSum = 0, iSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        vSum += arr[i];
        iSum += i;
        if (vSum == iSum)
            ret++;
    }
    return ret;
}

int main()
{
    vector<int> arr = {1, 0, 2, 3, 4};
    cout << maxChunksToSorted(arr) << endl;
    return 0;
}