#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            Swap(arr[i], arr[maxIndex]);
        }
    }
}

template <typename T>
void printArray(T arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test()
{
    char str[] = "hello world";
    selectionSort(str, strlen(str));
    printArray(str, strlen(str));

    int arr[] = {5, 2, 8, 3, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printArray(arr, n);
}

int main()
{
    test();
    return 0;
}