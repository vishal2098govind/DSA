#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int median(vector<vector<int>> &matrix, int r, int c)
{
    // find min max
    int mini = matrix[0][0];
    int maxi = matrix[0][c - 1];
    for (int i = 0; i < r; i++)
    {
        mini = min(mini, matrix[i][0]);
        maxi = max(maxi, matrix[i][c - 1]);
    }

    while (mini < maxi)
    {
        int mid = mini + (maxi - mini) / 2;
        int countNosLessThanMid = 0;
        for (int i = 0; i < r; i++)
        {
            int upperBound = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

            countNosLessThanMid += upperBound;
        }

        if (countNosLessThanMid < ((r * c + 1) / 2))
        {
            mini = mid + 1;
        }
        else
        {
            maxi = mid;
        }
    }
    return mini;
}

int main()
{
    int r = 3, c = 3;
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9},
    };
    int upperBound = upper_bound(matrix[0].begin(), matrix[0].end(), 5) - matrix[0].begin();
    int lowerBound = lower_bound(matrix[0].begin(), matrix[0].end(), 5) - matrix[0].begin();
    cout << "Median is " << median(matrix, r, c) << endl;
    cout << upperBound - lowerBound << endl;
    cout << (lower_bound(matrix[0].begin(), matrix[0].end(), 5) - matrix[0].begin()) << endl;
    cout << (lower_bound(matrix[1].begin(), matrix[1].end(), 5) - matrix[1].begin()) << endl;
    cout << (lower_bound(matrix[2].begin(), matrix[2].end(), 5) - matrix[2].begin()) << endl;
}