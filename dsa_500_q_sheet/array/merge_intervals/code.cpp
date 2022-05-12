#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void mergeIntervals(vector<vector<int>> &intervals, vector<vector<int>> &ans)
{
    sort(intervals.begin(), intervals.end());

    int s = intervals[0][0];
    int e = intervals[0][1];

    for (int i = 0; i < intervals.size(); i++)
    {
        if (intervals[i][0] <= e)
        {
            // Merge
            e = max(intervals[i][1], e);
        }
        else
        {
            ans.push_back({s, e});
            // Start new interval
            s = intervals[i][0];
            e = intervals[i][1];
        }
    }
    ans.push_back({s, e});
}

bool sortBy(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int main()
{
    vector<vector<int>> a = {{8, 10}, {2, 6}, {1, 3}, {8, 10}, {15, 18}};
    int arr[][2] = {{2, 6}, {1, 3}, {8, 10}, {15, 18}};
    // sort(arr, arr + 4);
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    mergeIntervals(a, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[" << ans[i][0] << ", " << ans[i][1] << "]"
             << ", ";
    }
}