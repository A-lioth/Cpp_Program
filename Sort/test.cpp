#include <iostream>
#include <functional>
#include "Quick.cpp"
#include "Insertion.cpp"
#include "BubbleWithFlag.cpp"
#include "Shell.cpp"
#include "Selection.cpp"
#include "Heap.cpp"
#include <ctime>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef void (*SortFunc)(vector<int> &nums);
typedef void (*SortFunc1)(vector<int> &nums, int n, int m);

void init(vector<int> &nums)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = rand() % 10000;
    }
}

void print(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        printf("%-d ", nums[i]);
        if (i % 10 == 9)
        {
            cout << endl;
        }
    }
    cout << endl;
}

double countTime(vector<int> nums, function<void(vector<int> &)> func = nullptr, function<void(vector<int> &, int, int)> func1 = nullptr)
{
    clock_t start, end;
    if (func)
    {
        start = clock();
        func(nums);
        end = clock();
        return ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    else if (func1)
    {
        start = clock();
        func1(nums, 0, nums.size() - 1);
        end = clock();
        return ((double)(end - start)) / CLOCKS_PER_SEC;
    }
    return 0;
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
            cout << "Shell Sort: " << countTime(nums, shellSort, nullptr) << "s" << endl;
            cout << "Heap Sort: " << countTime(nums, heapSort, nullptr) << "s" << endl;
            cout << "Insertion Sort: " << countTime(nums, insertionSort, nullptr) << "s" << endl;
            cout << "Selection Sort: " << countTime(nums, selectionSort, nullptr) << "s" << endl;
            cout << "Quick Sort: " << countTime(nums, nullptr, quickSort) << "s" << endl;
            cout << "Bubble Sort: " << countTime(nums, bubbleSort, nullptr) << "s" << endl;
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