#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> v, int key)
{
    int left = 0, right = v.size() - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (v[mid] > key)
            right = mid - 1;
        else if (v[mid] < key)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}

int binarySearchRecursive(vector<int> v, int key, int left, int right)
{
    int mid;
    if (left > right)
        return -1;

    mid = (left + right) / 2;

    if (v[mid] < key)
        return binarySearchRecursive(v, key, mid + 1, right);
    else if (v[mid] > key)
        return binarySearchRecursive(v, key, left, mid - 1);
    else
        return mid;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key;
    cout << "Enter the element to search: ";
    cin >> key;
    /*
    if (binarySearch(v, key) == -1)
        cout << "Element not found in the vector." << endl;
    cout << "Index of the element is: " << binarySearch(v, key) << endl;
     */
    if (binarySearchRecursive(v, key, 0, v.size() - 1) == -1)
        cout << "Element not found in the vector." << endl;
    cout << "Index of the element is: " << binarySearchRecursive(v, key, 0, v.size() - 1) << endl;

    return 0;
}