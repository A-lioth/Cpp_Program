#include <iostream>
#include "Insertion.cpp"
#include "BubbleWithFlag.cpp"
#include "Shell.cpp"
#include "Selection.cpp"
#include "Quick.cpp"
#include "Heap.cpp"
#include <time.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef void (*SortFunc)(vector<int> &nums);
typedef void (*SortFunc1)(vector<int> &nums, int n, int m);

void init(vector<int> &nums)
{
    srand((unsigned)time(nullptr));
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = rand() % 10000;
    }
}

void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
        if (i % 10 == 9)
        {
            cout << endl;
        }
    }
    cout << endl;
}

double countTime(vector<int> nums, SortFunc func = nullptr, SortFunc1 func1 = nullptr)
{
    clock_t start, end;
    start = clock();
    if (func)
    {
        func(nums);
    }
    else if (func1)
    {
        func1(nums, 0, nums.size() - 1);
    }
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

int main()
{
    vector<int> nums(10000);
    int choice;
    do
    {
        cout << "1. Initalize array randomly" << endl;
        cout << "2. Output the original array" << endl;
        cout << "3. Count the time of all sorting algorithms" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            init(nums);
            break;
        case 2:
            print(nums);
            break;
        case 3:
            cout << "Insertion Sort: " << countTime(nums, insertionSort) << "s" << endl;
            cout << "Bubble Sort: " << countTime(nums, bubbleSort) << "s" << endl;
            cout << "Shell Sort: " << countTime(nums, shellSort) << "s" << endl;
            cout << "Selection Sort: " << countTime(nums, selectionSort) << "s" << endl;
            cout << "Heap Sort: " << countTime(nums, heapSort) << "s" << endl;
            cout << "Quick Sort: " << countTime(nums, nullptr, quickSort) << "s" << endl;
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}