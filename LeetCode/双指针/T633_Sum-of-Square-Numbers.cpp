#include <iostream>
#include <cmath>

using namespace std;

bool judgeSquareSum(int c)
{
    long left = 0, right = sqrt(c);
    while (left <= right)
    {
        long sum = left * left + right * right;
        if (sum < c)
            left++;
        else if (sum > c)
            right--;
        else
            return true;
    }
    return false;
}

int main()
{
    int c = 1000000;
    cout << judgeSquareSum(c) << endl;
    return 0;
}