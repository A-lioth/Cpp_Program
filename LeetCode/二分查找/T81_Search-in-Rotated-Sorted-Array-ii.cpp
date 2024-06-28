#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int> &nums, int target)
{
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    bool result = search(nums, target);
    if (result)
        cout << "Target " << target << " found in the array." << endl;
    else
        cout << "Target " << target << " not found in the array." << endl;
    return 0;
}