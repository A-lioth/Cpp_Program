#pragma once

#include <iostream>
#include <vector>
using namespace std;

int medianThree(vector<int>& nums, int left, int mid, int right)
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