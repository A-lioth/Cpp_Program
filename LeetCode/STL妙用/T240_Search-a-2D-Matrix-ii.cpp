#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            j--;
        else if (matrix[i][j] < target)
            i++;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;
    bool result = searchMatrix(matrix, target);
    if (result)
        cout << "Target found in matrix" << endl;
    else
        cout << "Target not found in matrix" << endl;
    return 0;
}