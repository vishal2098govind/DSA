#include <iostream>
#include <vector>
using namespace std;
#define N 5

int findMaxDiff(int mat[][N])
{
    // prepare maxArr

    // fill last row and last col with max val in last row and last col respectively
    int maxLastVal = mat[N - 1][N - 1];
    int maxArr[N][N];
    // Last row
    for (int i = N - 1; i >= 0; i--)
    {
        maxLastVal = max(maxLastVal, mat[N - 1][i]);
        maxArr[N - 1][i] = maxLastVal;
    }
    // Last col
    maxLastVal = mat[N - 1][N - 1];
    for (int i = N - 1; i >= 0; i--)
    {
        maxLastVal = max(maxLastVal, mat[i][N - 1]);
        maxArr[i][N - 1] = maxLastVal;
    }

    int maxDiff = INT_MIN;

    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = N - 2; j >= 0; j--)
        {
            // Diff between mat[i][j] and diagonally below in maxArr[i][j]
            maxDiff = max(maxDiff, maxArr[i + 1][j + 1] - mat[i][j]);

            // max among mat[i][j] VS right side of maxArr[i][j] VS below side of maxArr[i][j]
            maxArr[i][j] = max(mat[i][j], max(maxArr[i + 1][j], maxArr[i][j + 1]));
        }
    }

    return maxDiff;
}

int main()
{
    int mat[][N] = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 6, 1, 3},
        {-4, -1, 1, 7, -6},
        {0, -4, 10, -5, 1},
    };

    int maxDiff = findMaxDiff(mat);
    cout << maxDiff;
}