#include <iostream>

using namespace std;

int mySqrt(int x)
{
    if (x == 0)
        return 0;
    if (x < 4)
        return 1;
    long left = 1, right = x;
    while (left <= right)
    {
        long mid = (left + right) / 2;
        if (mid < x / mid)
            left = mid + 1;
        else if (mid > x / mid)
            right = mid - 1;
        else
            return mid;
    }
    return right;
}

int main()
{
    int x = 8;
    cout << mySqrt(x) << endl;
    return 0;
}