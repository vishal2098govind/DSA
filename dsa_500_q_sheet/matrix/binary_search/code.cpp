#include <iostream>
#include <vector>

using namespace std;

bool binarySearchRow(vector<vector<int>> &matrix, int row, int target)
{
    int s = 0;
    int e = matrix[0].size() - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (matrix[row][mid] < target)
        {
            // search in right sub row
            s = mid + 1;
        }
        else if (matrix[row][mid] > target)
        {
            // search in left sub row
            e = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int startRow = 0;
    int endRow = matrix.size() - 1;
    int c = matrix[0].size();
    while (startRow <= endRow)
    {
        int midRow = startRow + (endRow - startRow) / 2;
        if (matrix[midRow][0] < target)
        {
            if (matrix[midRow][c - 1] > target)
            {
                // binary search in mid row
                return binarySearchRow(matrix, midRow, target);
            }
            else if (matrix[midRow][c - 1] < target)
            {
                // key can be present below
                startRow = midRow + 1;
            }
            else
            {
                return 1;
            }
        }
        else if (matrix[midRow][0] > target)
        {
            // key can be present above
            endRow = midRow - 1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    vector<vector<int>> matrix = {{1, 3}};
    int target = 3;
    cout << searchMatrix(matrix, target);
}